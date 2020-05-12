/*
calculateUVP.c
--------------------------------------------------------------------------------------
Purpose:        Calculating the velocities of between the grid cells by finding the
                average of the values

Call sequence:  calculateUVP(n,u,v,p,U,V,P)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n               int             Number of grid cells
u               double          Matrix containing horizontal speed of each grid cell
v               double          Matrix containing vertical speed of each grid cell
p               double          Matrix containing pressure of each grid cell incl.
                                ghost cells
U               double          Matrix containing horizontal speed of each vertical
                                grid wall
V               double          Matrix containing vertical speed of each horizontal
                                grid wall
P               double          Matrix containing pressure of each grid cell excl.
                                ghost cells
fidpres         FILE            File of  pressure values of a single point for
                                each time step


Local:
-------
i               int             Counting variable
j               int             Counting variable
-------------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/
#include "header.h"

void calculateUVP(int n,double u[n+2][n+2], double v[n+2][n+2], double p[n+2][n+2],
                   double U[n][n], double V[n][n], double P[n][n]){
printf("\n Calculating UVP");
int i,j;
for (i=0; i<=n-1;i++){
    for (j=0;j<=n-1;j++){
        U[j][i] = (u[i][j+1]+u[i+1][j+1])/2;
        V[j][i] = (v[i+1][j]+v[i+1][j+1])/2;
        P[j][i] = p[i+1][j+1];
    }//end for j
}//end for i

}//end void
