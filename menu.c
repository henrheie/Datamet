/*
Menu.c
-----------------------------------------------------------------------
Purpose:	Information about, boundary condition, geometry, Reynolds
			number, angle of inlet flow and maximum time is collected
			from the prgram user.

Variables
---------
Name					Type			Description
--------------------------------------------
Global
------
n						int				Number of grid cells in the domain
Re						int				Reynolds number
x_start					int				horizontal start pont
x_end					int				horzontal end point
y_start					int				vertical start pont
y_end					int				vertical end poin
x_start_percent			int				horizontal start pont in percent of x-direction
x_end_percent			int				horizontal end point in percent of x-direction
y_start_percent			int				vertical start point in percent of y-direction
y_end_percent			int				vertcal end point in percent of y direction
check					int				Check if user input are satisfactory
boundary_conditions		int				Logical flag to apply correct boundary conditions
u_top					int				Horizontal velocity at top wall
u_bottom				int				Horizontal velocity at bottom wall
dt						double			Time step
velv					double			Vertical velocity in program 4

Local:
------
a						int				Variable directing value of *prog
b						int				Variable direction value of *x_start_percent
c						int				Variable directing valye of *y_start_percent
d						int				Variable directing value of x_end_percent
e						int				Variable directing value of y_end_percent
f						int				Variable directing valye of boundary_conditions
g						int				Variable directing value of Re
h						int				Variable directing value of check
angle					int				input angle for pragram 4
i										Varble for directiong value of t_max
j


*/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<unistd.h>
void menu(int n, int *prog, double *t_max, int x_start_percent, int *x_end_percent, int *y_start_percent, int *y_end_percent,
	int *x_start, int *y_start, int *x_end, int *y_end, int *boundary_condition, int *u_top, int *u_bottom, int *check, double *velv) {

	int a, b, c, d, e, f, h, i;
	double g, j;
	*velv = 0.0;
	while (*check == 1) { // continous loop while user is not satisfied with inputs
		printf("\n \n \n \n \n \n");
		for (i = 1;1 < 30;i++){
			printf("=");
		}//end for
printf("\n--------Welcome to the program menu--------\n");
	printf("\n \n \n \n \n \n");
		for (i = 1;1 < 30;i++){
			printf("=");
		}//end for
printf("Choose your preferred program");
    for (i = 1;1 < 30;i++){
			printf("=");
		} //end for

printf("\t\t Program 1: Cavity cell \n ");
printf("\t\t Program 2: Cavity cell with box \n");
printf("\t\t Program 3: Free channel flow \n");
printf("\t\t Program 4: Channel flow with box \n");

//her kan det være at jeg legger til litt til!!
printf("Program to run? \n");
scanf("%d",&a);
*prog = a;

if (*prog > 4)
    {
    while (*prog>4)
        {
            printf("!!!WARNING!!!\n");
            printf("Number must be between 1 and 4\n\n\n");
            printf("Choose nr. between 1 and 5");
            scanf("%d",&a);
            *prog = a;
        }//while

    }//if
for (i = 1;1 < 30;i++){
			printf("=");
		} //end for

//Defining box geometry

if (*prog==2 || *prog==4){



}//if

	}//end while
}// end menu.c


