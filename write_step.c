/*
write_steps.c
--------------------------------------------------------------------------------------
Purpose:        Prints the steps into the GL file.

Call sequence:  write_steps(&fidGL,n,&teller)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
-------
n               int             Number of grid cells
*teller         int             Pointer to counting variable
*fidGL          FILE            Pointer to the GL-file

Local:
-------
i               int             Counting variable
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/


#include "header.h"

void write_steps(FILE *fidGL, int n, int *teller){
fprintf(fidGL, "\n\n*GLVIEWSCALAR 1\n%%NAME \"Pressure\" ");
for (int i=1; i<=(*teller/3); i++){

    fprintf(fidGL,"\n%%STEP  %i  \n%i",i,(i*3)-2);
}//end for

fprintf(fidGL, "\n\n*GLVIEWSCALAR 2\n%%NAME \"Streamfunction\" ");
for (int i=1; i<=(*teller/3); i++){
fprintf(fidGL, "\n%%STEP  %i  \n%i",i,(i*3)-1);
}//end for

fprintf(fidGL,"\n\n*GLVIEWVECTOR 1\n%%NAME \"Velocity\" ");
for (int i=1; i<=(*teller/3); i++){
        fprintf(fidGL, "\n%%STEP  %i  \n%i",i,i*3);
}//end for


}//end void
