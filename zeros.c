#include "header.h"
void zeros(int n, double *u, double *v, double *p){
int i,j;
for (i=0;i<n+1;i++){
    for (j=0;j<n+1;j++){


        u[i][j]=0.0;
        v[i][j]=0.0;
        p[i][j]=0.0;


    }//end for (j)

}//end for(i)




}//end void
