/*
NavierStokes.c
--------------------------------------------------------------------------------------
Purpose:    Run the program and all its functions.

Subroutines
Name                    Description
--------------------------------------------------------------------------------------
header.h                Contains the subroutinedeclerations and global macro
                        definitions.
interpolate.c           Finds the optimal value for relaxation parameter
option.c                Lets the user choose flow case
stability_test.c        Checking the stability of the numerical model
calvel.c                Calculates the tentative velocities and solving the momentum
                        equations
cavitybox.c             Defining BCs for flow in a cavity box
channelflow.c           Defining BCs for a channel flow
plate.c                 Defining BCs for plate in uniform flow
box.cpiter.c            Defining BCs for box in uniform flow
print_pressure.c        Prints the pressure of one single point into a txt file
calculate_lift_drag.c   Calculates the lift and drag working on the box in uniform
                        flow
calculateUVP.c          Calculates pressure and velocities for each grid cell
stream_function.c       Calculates the stream function
make_vtf.c              Prints the results to a VTF file

Variables

Name			        Type			Description
--------------------------------------------------------------------------------------
Global:
---------
n						int				Number of grid cells in the domain
tmax                    int             Maximum time value
Re						int				Reynolds number
x_start					int				horizontal start point
x_end					int				horizontal end point
y_start					int				vertical start point
y_end					int				vertical end point
itmax                   int             Maximum number of iterations
iter                    int             Variable containing the iteration number
Bcpar                   int             Variable telling the program which BC to
                                        apply
Testpar                 int             Variable telling if the numerical method is
                                        stable
iflag                   int             Parameter which checks continuity equation
dt						double			Time step
epsi                    double          Maximum allowed mistake of divergence
h                       double          Step in space
Beta                    double          Relaxation parameter
div                     double          Divergence of matrices
u                       double          Matrix containing horizontal speed of each
                                        grid cell
v                       double          Matrix containing vertical speed of each
                                        grid cell
p                       double          Matrix containing pressure of each grid
                                        cell incl. ghost cells
U                       double          Matrix containing horizontal speed of each
                                        vertical grid wall
V                       double          Matrix containing vertical speed of each
                                        horizontal grid wall
P                       double          Matrix containing pressure of each grid cell
                                        excl. ghost cells
PSI                     double          Matrix containing stream function of each grid
                                        cell
fidpres                 FILE            File where the pressure behind the plate is
                                        printed
fidLift                 FILE            File where the lift working on the box is
                                        printed
fiddrag                 FILE            File where the drag working on the box is
                                        printed

Local:


--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019

*/

#include "header.h"
#define n 40 // Defining the number of grid cells
int main(){
// Defining global variables
int tmax=30, itmax = 2000, bcPar;
int testpar=1, iflag,iter;
int x_start = 0, x_end = 0, y_start=0, y_end=0;
double Re = 1000, t, epsi = 1e-6, dt = 0.1, h=1.0/n;
double omega, beta, div=1;

// Creating null matrices

double u[n + 2][n + 2] = {0};
double v[n+2][n+2] = {0};
double p[n+2][n+2] = {0};
double U[n][n] = {0};
double V[n][n] = {0};
double P[n][n] = {0};
double PSI[n+1][n+1] = {0};

//Finding relaxation parameter
omega=interpolate(n);
beta=(omega*h*h)/(4*dt);

// Letting the user choose which flow case to examine
options(n,&bcPar,&x_start,&x_end,&y_start,&y_end);
//Checking if the numerical solution
testpar=stability_test(h,Re,dt);

if (testpar == 0.0){
    printf("Function not stable");
    return 0;

}//end if

//Open files used to print results
FILE *fidpres;
FILE *fidLift;
FILE *fiddrag;
fidpres = fopen("PointPressure.txt","w+");
fidLift = fopen("totlift.txt","w+");
fiddrag = fopen("totdrag.txt","w+");

// main time loop
for(t=0; t<=tmax;t=t+dt){
    calvel(n,u,v,p,dt,h,Re,x_start,x_end,y_start,y_end);
    for ( iter=1;iter<=itmax;iter++){
       //Choosing appropriate BC
        if(bcPar==1.0){
            cavitybox(n,u,v);
        }//end if
        if (bcPar==2.0){
            channelflow(n,u,v);
        }//end if
        if (bcPar==3.0){
            plate(n,u,v);
            }//end  if
        if (bcPar==4.0){
            box(n,u,v,x_start,x_end,y_start,y_end);
        }//end if


      piter(n,epsi,u,v,p,dt,h,beta,&iflag,x_start,x_end,y_start,y_end,&div);



    if(iflag==0.0){
        break;
    }

    }//end for iter
    if(iter>=itmax){
        printf("Warning! Time t= %f,iter =%d,div=%f \n",t,iter,div);
    }//end if
    else{
        printf("Time t= %f \t\t iter=%d\t div=%f \n",t,iter,div);
    }

    if(bcPar ==3.0){
        print_pressure(fidpres,n,p);
    }
    if(bcPar ==4.0){
        calculate_lift_drag(fidLift,fiddrag,n,p,x_start,x_end,y_start,y_end);
    }
}//end for time


//Closing files
fclose(fidpres);
fclose(fidLift);
fclose(fiddrag);

calculateUVP(n,u,v,p,U,V,P);//Calculating result velocities

stream_function(n,u,v,h,PSI);//Finding stream function
print_results(n,u,v,p,U,V,P,PSI);//Printing all results in text files
make_vtf(n,U,V,P,PSI); //Making a vtf file for use in GLview

return 0;
}//end main
