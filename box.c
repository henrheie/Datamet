/*
box.c
--------------------------------------------------------------------------------------
Purpose:        Applying appropriate BC for case of a box in uniform flow

Call sequence:  box(n,u,v,x_start,x_end,y_start,y_end)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
-------
n				int				Number of grid cells in the domain
x_start			int				horizontal start point
x_end			int				horizontal end point
y_start			int				vertical start point
y_end			int				vertical end point
u               Double          Matrix containing horizontal velocities of each grid
                                cell
v               Double          Matrix containing horizontal velocities of each grid
                                cell


Local:
-------
i               int             Counting variable
j               int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/

#include "header.h"
void box(int n,double u[n+2][n+2],double v[n+2][n+2],int x_start,int x_end,int y_start,int y_end)
{
int i,j;

for ( j = 0; j<= n+1 ; j++){
    u[0][j] = 1; //inlet velocity
    v[0][j] =0.0; // inlet
    u[n][j] = u[n-1][j];


}
for (int i=0; i<= n+1 ;i++){
    v[i][n]= 0.0;
    v[i][0]=0.0;
    u[i][n+1]=u[i][n];
    u[i][0] = u[i][1];

}//end for i



for (i=x_start; i <= x_end;i++){
    v[i][y_start-1]= 0.0;
    v[i][y_end]=0.0;
    u[i][y_start]= -u[i][y_start-1];
    u[i][y_end] = -u[i][y_end+1];


}//end for i




for ( j = y_start; j<= y_end; j++){
    u[x_start-1][j] = 0.0;
    u[x_end][j] =0.0;
    v[x_start][j] = -v[x_start-1][j];
    v[x_end][j] = -v[x_end+1][j];


}//end for j
u[x_start-1][y_start]=0.0;
v[x_start][y_start-1] =0.0;

v[x_start][y_end]=0.0;
u[x_start-1][y_end]=0.0;

v[x_end][y_end]=0.0;
u[x_end][y_end]=0.0;





}//end void
