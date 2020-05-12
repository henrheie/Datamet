/*
calvel.c
--------------------------------------------------------------------------------------
Purpose:        The first step of the solution algorithm .Calculating the new
                tentative velocities from the old pressure. If the flow case of a box
                in uniform flow is chosen,the domain of the box will not be calculated.

Call sequence:  calvel(n,u,v,p,dt,h,Re, x_start, x_end, y_start, y_end)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n               int             Number of grid cells
x_start			int				horizontal start point
x_end	    	int				horizontal end point
y_start			int				vertical start point
y_end			int				vertical end point
u               double          Array containing horizontal speed of each grid cell
v               double          Array containing vertical speed of each grid cell
p               double          Array containing pressure of each grid cell incl.
                                ghost cells
U               double          Array containing horizontal speed of each vertical
                                grid wall
V               double          Array containing vertical speed of each horizontal
                                grid wall
P               double          Array containing pressure of each grid cell excl.
                                ghost cells
fidpres         FILE            File of  pressure values of a single point for
                                each time step


Local:
---------
i               int             Counting variable
j               int             Counting variable
fux             double          First velocity term in calculations of new u
fuy             double          First velocity term in calculations of new v
fvx             double          Second velocity term in calculations of new u
fvy             double          Second velocity term in calculations of new v
visu            double          Third velocity term in calculations of new u
visv            double          Third velocity term in calculations of new v
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019

*/
#include "header.h"
void calvel(int n, double u[n+2][n+2], double v[n+2][n+2], double p[n+2][n+2],
    double dt, double h, double Re, int x_start, int x_end, int y_start, int y_end){
int i,j;
double fux, fuy, fvx, fvy, visu, visv;

for (i=1; i<=n; i++){
    for (j=1;j<=n; j++){
        if (i<x_start || i> x_end || j<y_start || j>y_end){
            fux=((u[i][j]+u[i+1][j])*(u[i][j]+u[i+1][j])-
                    (u[i-1][j]+u[i][j])*(u[i-1][j]+u[i][j]))*0.25/h;

            fuy=((v[i][j]+v[i+1][j])*(u[i][j]+u[i][j+1])-
                    (v[i][j-1]+v[i+1][j-1])*(u[i][j-1]+u[i][j]))*0.25/h;

            fvx=((u[i][j]+u[i][j+1])*(v[i][j]+v[i+1][j])-
                 (u[i-1][j]+u[i-1][j+1])*(v[i-1][j]+v[i][j]))*0.25/h;

            fvy=((v[i][j]+v[i][j+1])*(v[i][j]+v[i][j+1])-
                 (v[i][j-1]+v[i][j])*(v[i][j-1]+v[i][j]))*0.25/h;

            visu=(u[i+1][j]+u[i-1][j]+u[i][j+1]+u[i][j-1]-4.0*u[i][j])/(Re*h*h);
            visv=(v[i+1][j]+v[i-1][j]+v[i][j+1]+v[i][j-1]-4.0*v[i][j])/(Re*h*h);

            u[i][j]=u[i][j]+dt*((p[i][j]-p[i+1][j])/h-fux-fuy+visu);
            v[i][j]=v[i][j]+dt*((p[i][j]-p[i][j+1])/h-fvx-fvy+visv);

                   } //end if
    } //end for j

}//end for i

}//end void

