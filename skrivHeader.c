#include "header.h"

void write_header(FILE *fidGL, int n){
fprintf(fidGL, "*VTF-1.00 \n !noder \n*NODES \t\t\t\t\t 1"); // Writes the node coordinate
int i,j;
for (i=0; i<n; i=i++){
    for (int j=0; j<n;n++){
        fprintf(fidGL, "\n%f\t\t%f\t\t%f",(j+1.0),(i+1.0),0.0);

    }//end for j

}//end for i
fprintf(fidGL, "\n\n*ELEMENTS\t\t\t\t 1 \n%%NODES #1\n%%QUADS");
for( j=0; j<(n-1); j++){
    for( i=0; i<(n-1); i++){
   fprintf(fidGL, "\n%i    %5i    %5i    %5i", i+(j*n),i+1+(j*n),i+n+1(j*n),i+n+(j*n));
    }//end for i
}//end for j
fprintf (fidGL, "\n\n*GLVIEWGEOMETRY 1\n%%ELEMENTS\n1\n");
}//end void
