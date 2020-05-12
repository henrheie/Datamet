/*
channelflow.c
--------------------------------------------------------------------------------------
Purpose:        Applying appropriate BC for the channel flow case

Call sequence:  channelflow(n,u,v)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
-------
n				int				Number of grid cells in the domain
u               Double          Matrix containing horizontal velocities of each
                                grid cell
v               Double          Matrix containing horizontal velocities of each
                                grid cell
Local:
-------
i               int             Counting variable
j               int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/

#include "header.h"
void channelflow(int n, double u[n+2][n+2], double v[n+2][n+2]){
int i,j;

for (j=0 ; j<=n+1 ; j++){
    u[0][j]=1.0;
    v[0][j]=0.0;
    u[n+1][j]=u[n][j];

    }//end for

for (i=0 ; i<=n+1 ; i++)
    {
    v[i][n]=0.0;
    v[i][0]=0.0;
    u[i][n+1]=-u[i][n];
    u[i][0]=-u[i][1];
    }//end for


u[0][0]=0;
u[0][n+1]=0;
}//end void
