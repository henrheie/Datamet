
/*
calculate_lift_drag.c
--------------------------------------------------------------------------------------
Purpose         Calculating the lift and drag working on the box in the box in uniform
                flow,flow case

Call sequence  calculate_lift_drag(&fudlift, &fiddrag, n,p,x_start,x_end,y_start,y_end)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
---------
n				int				Number of grid cells in the domain
x_start			int				horizontal start point
x_end			int				horizontal end point
y_start			int				vertical start point
y_end			int				vertical end point
p               double          Array containing pressure values for each grid cell
fiddrag         FILE            File containing the drag working on the box of each
                                time step
fidlift         FILE            File containing the lift working on the box of each
                                time step


Local:
-------
i               int             Counting variable
j               int             Counting variable
drag            double          Drag force of the present time step
lift            double          Lift force of the present time step
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/

#include "header.h"
void calculate_lift_drag(FILE *fidlift, FILE *fiddrag, int n, double p[n+2][n+2],
                          int x_start, int x_end, int y_start, int y_end){
int i,j;
double lift = 0, drag =0;
for (i=x_start; i<= x_end ;i++){
    lift = lift + p[i][y_end+1]- p[i][y_start-1];

}//end for
fprintf(fidlift, "\n%f",lift);

for (j=y_start;j<=y_end;j++){
    drag =drag + p[x_start-1][j] - p[x_end+1][-1];


}//end for

fprintf(fiddrag, "\n%f",drag);


}//end void


