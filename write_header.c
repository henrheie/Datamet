/*
write_header.c
--------------------------------------------------------------------------------------
Purpose:        Prints the header into the .vtf file.

Call sequence   write_header(&fidGL,n)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n               int             Number of grid cells
*fidGL          FILE            Pointer to the vtf-file

Local:
------
i               int             Counting variable
j               int             Counting variable

--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/
#include "header.h"

void write_header(FILE *fidGL, int n){
int i,j;
fprintf(fidGL, "*VTF-1.00 \n\n\n!noder \n*NODES 1"); // Writes the node coordinate

for (i=0; i<n; i++){
    for (j=0; j<n; j++){
        fprintf(fidGL, "\n%f  %f  %f",(j + 1.0),(i + 1.0),0.0);

    }//end for j
}//end for i
fprintf(fidGL, "\n\n*ELEMENTS\t1\n%%NODES #1\n%%QUADS");
for(j=0; j<(n-1); j++){
    for( i=1; i<(n); i++){
    fprintf(fidGL, "\n%i %5i %5i %5i",i+(j * n),i+1+(j * n),i+n+1+(j*n), i+n+(j*n));
    }//end for i
}//end for j
fprintf (fidGL, "\n\n*GLVIEWGEOMETRY 1\n%%ELEMENTS\n1\n");
}//end void
