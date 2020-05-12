/*
write_results.c
--------------------------------------------------------------------------------------
Purpose:        Prints the final results into the GL file.

Call sequence:  write_results(&fidGL,n,&teller,P,PSI,U,V)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n               int             Number of grid cells
*teller         int             Pointer to counting variable
U               double          Array containing horizontal speed of each vertical
                                grid wall
V               double          Array containing vertical speed of each horizontal
                                grid wall
P               double          Array containing pressure of each grid cell excl.
                                ghost cells
PSI             double          Array containing stream function of each grid cell
*fidGL          FILE            Pointer to the GL-file

Local:
------
i               int             Counting variable
j               int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/

#include "header.h"
void write_results(FILE *fidGL, int n, int *teller, double P[n][n],
                    double PSI[n+1][n+1], double U[n][n], double V[n][n]){
fprintf(fidGL, "\n\n*RESULTS  %i\n%%DIMENSION  1\n%%PER_NODE #1",*teller);
for (int i=0; i<n;i++){
    for ( int j=0;j<n;j++){
        fprintf(fidGL, "\n%f", P[i][j]);
    }//end for j
}//end for i
*teller=*teller+1;

fprintf(fidGL, "\n\n*RESULTS  %i\n%%DIMENSION  1\n%%PER_NODE #1",*teller);

for (int i=0; i<n;i++){
    for (int j=0;j<n;j++){
        fprintf(fidGL, "\n%f", PSI[i][j]);
    }//end for j
}//end for i

*teller = *teller+1;

fprintf(fidGL, "\n\n*RESULTS  %i\n%%DIMENSION  3\n%%PER_NODE #1",*teller);
for (int i=0; i<n;i++){
    for (int  j=0;j<n;j++){
        fprintf(fidGL,"\n%f  %f  %f", U[i][j],V[i][j],0.0);
    }//end for j
}//end for i
*teller=*teller+1;
}//end void


