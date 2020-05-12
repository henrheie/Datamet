/*
options.c
--------------------------------------------------------------------------------------
Purpose:        This subroutine gives the user choises of which flow case
                to analyze and where to place the box if the flow around
                box flow case is chosen.

Call sequence   options(n,&BCpar,&x_start,&x_end,&y_start,&y_end)


--------------------------------------------------------------------------------------
Variables
---------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n				int				Number of grid cells in the domain
x_start			int				horizontal start point
x_end			int				horizontal end point
y_start			int				vertical start point
y_end			int				vertical end point
u               Double          Matrix containing horizontal velocities of
                                each grid cell
v               Double          Matrix containing horizontal velocities of
                                each grid cell
Local:
---------
a               int             Variable containing which flow case to run
b               int             Variable containing the horizontal staring point
                                of box
c               int             Variable containing the vertical staring point
                                of box
d               int             Variable containing the horizontal ending point
                                of box
e               int             Variable containing the vertical ending point
                                of box
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019


*/


#include "stdio.h"
void options(int n, int *bcPar, int *x_start, int *x_end, int *y_start, int *y_end){

int a,b,c,d,e;
printf("Choose model to run \n");
printf("Type 1 for cavity box \n");
printf("Type 2 for channel flow\n");
printf("Type 3 for plate in uniform flow\n");
printf("Type 4 for box in uniform flow\n");
scanf("%d",&a);
*bcPar=a;
while (*bcPar<1 || *bcPar>4){
    printf("intvalid input for program user. Choose 1,2,3 or 4 \n");
    scanf("%d",&a);
    *bcPar=a;
}//end while
int check=0;
if (*bcPar==4.0){

while (check != 1){
    printf("Choose xstart\n");
    scanf("%d",&b);
    printf("Choose ystart\n");
    scanf("%d",&c);
    printf("Choose xend\n");
    scanf("%d",&d);
    printf("Choose yend\n");
    scanf("%d",&e);


    *x_start=b;
    *y_start=c;
    *x_end=d;
    *y_end=e;
if (floor(*x_start)!=*x_start || floor(*y_start)!=*y_start ||
            floor(*x_end)!=*x_end || floor(*y_end)!=*y_end ){
    printf ("WARNING SARTING POINTS AND ENDING POINTS MUST BE WHOLE NUMBERS!\n");
}
    // investigating if the box corners are placed correctly

if (*x_start <= 0 || *x_end >= n || *y_start <= 0 || *y_end >= n){
    printf ("WARNING BOX HAS TO BE INSIDE DOMAIN!\n");
} //end if
if (*x_start >= *x_end || *y_start >= *y_end){
    printf("WARNING! starting point must be before ending point! \n");
}

else {
    check=1;
}//else

//end if
} //end while
} // end if









}//void


