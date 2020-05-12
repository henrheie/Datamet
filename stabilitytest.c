/*
stability_test.c
--------------------------------------------------------------------------------------
Purpose         Checking the stability of the numerical method and changes the value
                of the variable testpar according to the results from the stability
                test


Call sequence:  stability_test(h,Re,dt)

--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
Re              double          Reynolds number
h               double          Grid spacing
dt				double			Time step

Local:
--------
i               int             Counting variable
j               int             Counting variable
checkstability  double          Array containing the three stability criteria
max             double          Variable containing the largest accepted time step
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019

*/

#include "header.h"
int stability_test(double h, double Re, double dt){
double checkstability[3]={h,Re*h*h/4,2.0/(Re*Re)}, max = h;
int testpar=1;

for (int i=1; i < 2 ; i++){

    if (checkstability[i]<max){
        max = checkstability[i];

    }//end if

    }// end for
  if(dt>max){
        printf("warning!!\n");
        printf("Calculation stopped. Dt is too big\n");
        printf("Dt has to be smaller than %f \n",max);
        testpar=0;

} // end if

return testpar;
}// end void


