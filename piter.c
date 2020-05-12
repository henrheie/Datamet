/*
piter.c
--------------------------------------------------------------------------------------
Purpose:        Iterative process to find the velocity at the following time step.
                The pressure is iterated until the divergence is smaller than the
                pre established epsi. If the uniform flow around a box flow case is
                chosen, no calculations inside the box domain will be done.

Call sequence: piter(n,epsi,u,vp,dt,h,&iflag,x_start,x_end,y_start,y:end,&div)

--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n				int				Number of grid cells in the domain
x_start			int				horizontal start point
x_end			int				horizontal end point
y_start			int				vertical start point
y_end			int				vertical end point
*iflag          int             Pointer to logical flag to check if divergence is
                                sufficiently small
u               double          Array containing horizontal velocities of each
                                grid cell
v               double          Array containing horizontal velocities of each
                                grid cell
h               double          Step in space
Beta            double          Relaxation parameter
div             double          Divergence of matrices
p               double          Array containing pressure of each grid cell incl.
                                ghost cells
dt				double			Time step


Local:
------
i               int             Counting variable
j               int             Counting variable
delp            double          Pressure difference to calculate velocities
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019

*/


#include "header.h"
void piter(int n, double epsi, double u[n+2][n+2], double v[n+2][n+2],
            double p[n+2][n+2],double dt, double h, double beta, int *iflag,
            int x_start, int x_end, int y_start, int y_end,double *div){
int i,j;
double delp;
*iflag=0;
for(j=1;j<=n;j++){
    for(i=1;i<=n;i++){
        if (i<x_start || i > x_end || j < y_start || j>y_end){
            *div=(u[i][j]-u[i-1][j])/h+ (v[i][j]-v[i][j-1])/h;  //continuity equation

            if(fabs(*div)>=epsi){
                *iflag=1;
            } // end if
            delp=-beta*(*div);
            p[i][j] = p[i][j] + delp;
            u[i][j] = u[i][j] + delp*dt/h;
            u[i-1][j] = u[i-1][j] - delp*dt/h;
            v[i][j] = v[i][j] + delp*dt/h;
            v[i][j-1] = v[i][j-1] - delp*dt/h;

        }//end if


    }//end for i


}//end for j



}

