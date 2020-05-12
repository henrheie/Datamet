/*
stream_function.c
--------------------------------------------------------------------------------------
Purpose:         This subroutine calculates the stream function of the final time step

Call sequence:   stream_function(n,u,v,h,PSI)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
-------
n				int				Number of grid cells in the domain
h               double          Step size in space
u               double          Array containing horizontal velocities of each
                                grid cell
v               double          Array containing horizontal velocities of each
                                grid cell
PSI             double          Array containing stream function of each grid cell

Local:
-------
i               int             Counting variable
j               int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/


#include "header.h"


void stream_function(int n, double u[n+2][n+2], double v[n+2][n+2], double h,
                      double PSI[n+1][n+1]){
int i,j;
double psi[n+1][n+1];



for (i=0;i<=n;i++){
    for (j=0;j<=n;j++){
        psi[i][j]= 0.0;
    }
}

for (i=1; i<=n;i++){
    psi[i][0] = psi [i-1][0] - (v[i][0])*h;
    // printf("\n v[%i][0] = %f",i,v[i][0]);
}//end for i

for (i=0; i<=n;i++){
    for (j=1;j<=n;j++){
    psi[i][j] = psi[i][j-1] + (u[i][j])*h;
   // printf("\n psi[%i][%i] = %f",i,j,psi[i][j]);
    } //end for j
}//end for i

for (i=0; i<=n;i++){
    for (j=0;j<=n;j++){
        PSI[i][j] = -psi[j][i];
 //printf("\n PSI[%i][%i] = %f",i,j,PSI[i][j]);
    } //end for j
}//end for i

}//end void
