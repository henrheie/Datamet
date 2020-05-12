/*
plate.c
--------------------------------------------------------------------------------------
Purpose:        Applying appropriate BC for the case of uniform flow around a plate

Call sequence:  plate(n,u,v)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
---------
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
void plate(int n, double u[n+2][n+2], double v[n+2][n+2]){
int i,j;
for (j=0;j<=n+1;j++){ //BC of inlet flow

    u[0][j]=1.0;
    v[0][j]=0.0;

    if (j>n/3 && j<2*n/3){
          u[0][j]=0.0;
          v[0][j]=-v[1][j];
    }//end if

    u[n+1][j]=u[n][j];//Outgoing flow
    v[n+1][j]=-v[n][j];

}//end for
for (i=0;i<=n+1;i++){ //BC of top and bottom wall
    v[i][n]=0.0;
    v[i][0]=0.0;
    u[i][n+1]=u[i][n];
    u[i][0]=u[i][1];
}//end for


}//end void
