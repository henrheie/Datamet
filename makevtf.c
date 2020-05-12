
/*
make_vtf.c
--------------------------------------------------------------------------------------
Purpose:           Creates a VTF file which can be visualized with GLwiew.
                   This is done by using the subroutines,write_header.c,
                   write_results.c and write_steps.c

Call sequence      make_vtf(n,U,V,P,PSI)

--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
------
n               int             Number of grid cells
U               double          Array containing horizontal speed of each vertical
                                grid wall
V               double          Array containing vertical speed of each horizontal
                                grid wall
P               double          Array containing pressure of each grid cell excl.
                                ghost cells
*fidGL          FILE            File where header, results and steps are printed.


Local:
------
teller          int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019

*/
#include "header.h"
void make_vtf(int n, double U[n][n], double V[n][n], double P[n][n],
                double PSI[n+1][n+1]){

int teller=1;
FILE  *fidGL;
fidGL = fopen("GLview.vtf","w+");

write_header(fidGL,n);
write_results(fidGL,n,&teller,P,PSI,U,V);
write_steps(fidGL,n,&teller);

fclose(fidGL);


}//end void
