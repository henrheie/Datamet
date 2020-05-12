/*
print_pressure.c
--------------------------------------------------------------------------------------
Purpose:        Printing the pressure value of a single point behind the plate in
                the case of uniform flow around plate


Call sequence: print_pressure(&fidpre,n,p)

--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
-------
n               int             Number of grid cells
p				double			Array including pressure values of each grid cell
fidpres         FILE            File of  pressure values of a single point for each
                                time step

Local:
------
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/

#include "header.h"
void print_pressure(FILE *fidpres, int n, double p[n+2][n+2]){

fprintf(fidpres, "\n %f ", p[n/4,n/2]);

}//end void
