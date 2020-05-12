/*
print_results.c
--------------------------------------------------------------------------------------
Purpose:        Printing the the results from the final time step into text files.

Call sequence:  print_results(n,u,v,p,U,V,P,PSI)

--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description
--------------------------------------------------------------------------------------
Global:
--------
n				int				Number of grid cells in the domain
u               double          Array containing horizontal velocities of each
                                grid cell
v               double          Array containing horizontal velocities of each
                                grid cell
p               double          Array containing pressure of each grid cell incl.
                                ghost cells
U               double          Array containing horizontal speed of each vertical
                                grid wall
V               double          Array containing vertical speed of each horizontal
                                grid wall
P               double          Array containing pressure of each grid cell excl.
                                ghost cells
PSI             double          Array containing stream function of each grid cell

Local:
-------
i               int             Counting variable
j               int             Counting variable
fpu             FILE            pointer to text file where u matrix is printed
fpv             FILE            pointer to text file where v matrix is printed
fpp             FILE            pointer to text file where p matrix is printed
fpU             FILE            pointer to text file where U matrix is printed
fpV             FILE            pointer to text file where v matrix is printed
fpP             FILE            pointer to text file where p matrix is printed
fpPSI           FILE            pointer to text file where PSI matrix is printed
-------------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/
#include "header.h"

void print_results(int n, double u[n+2][n+2], double v[n+2][n+2], double p[n+2][n+2],
                double U[n][n], double V[n][n], double P[n][n], double PSI[n+1][n+1]){
printf("\n results");
int i,j;
FILE *fpu;
FILE *fpv;
FILE *fpp;
FILE *fpU;
FILE *fpV;
FILE *fpP;
FILE *fpPSI;

fpu = fopen("uvel.txt","w+");
fpv = fopen("vvel.txt","w+");
fpp = fopen("pres.txt","w+");
fpU = fopen("U.txt","w+");
fpV = fopen("V.txt","w+");
fpP = fopen("P.txt","w+");
fpPSI = fopen("PSI.txt","w+");

for (i=0; i<=n-1;i++){
    for (j=0;j<=n-1;j++){
    fprintf(fpu, "%.10f\t",u[i][j]);
    fprintf(fpv, "%.10f\t",v[i][j]);
    fprintf(fpp, "%.10f\t",p[i][j]);
    fprintf(fpU, "%.10f\t",U[i][j]);
    fprintf(fpV, "%.10f\t",V[i][j]);
    fprintf(fpP, "%.10f\t",P[i][j]);
    fprintf(fpPSI, "%.10f\t",PSI[i][j]);


    }//end for j
    fprintf(fpu, "\n");
    fprintf(fpv, "\n");
    fprintf(fpp, "\n");
    fprintf(fpU, "\n");
    fprintf(fpV, "\n");
    fprintf(fpP, "\n");
    fprintf(fpPSI, "\n");

}//end for i
    fclose(fpu);
    fclose(fpv);
    fclose(fpp);
    fclose(fpU);
    fclose(fpV);
    fclose(fpP);
    fclose(fpPSI);

printf("\n Printing done");

}//end void
