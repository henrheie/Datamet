/*
cavitybox.c
--------------------------------------------------------------------------------------
Purpose:        Applying appropriate BC for the cavity box flow case

Call sequence:  cavity_box(n,u,v)

--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
-------
n				int				Number of grid cells in the domain
u               Double          Matrix containing horizontal velocities of
                                each grid cell
v               Double          Matrix containing horizontal velocities of
                                each grid cell


Local:
--------
i               int             Counting variable
j               int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/
#include "header.h"
void cavitybox(int n, double u[n+2][n+2], double v[n+2][n+2]){
int i,j;
for (j=0;j<=n+1;j++){
        u[0][j]=0.0;
        v[0][j]=-v[1][j];
        u[n][j]=0.0;
        v[n+1][j]=-v[n][j];
    }//end for j
for (i=0;i<=n+1;i++)
    {
        v[i][n]=0.0;
        v[i][0]=0.0;
        u[i][n+1]=-u[i][n]+2.0;
        u[i][0]=-u[i][1];
    }//end for i
}//end void
