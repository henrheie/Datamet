/*
header.h
--------------------------------------------------------------------------------------
Purpose:        Contains declarations for all subroutines

--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>


double interpolate(int n);


void options(int n, int *bc_par, int *x_start, int *x_end, int *y_start, int *y_end);


int stability_test(double h, double Re, double dt);


void calvel(int n, double u[n+2][n+2], double v[n+2][n+2], double p[n+2][n+2],
             double dt, double h, double Re, int x_start, int x_end, int y_start,
              int y_end);


void cavitybox(int n, double u[n+2][n+2], double v[n+2][n+2]);


void channelflow(int n, double u[n+2][n+2], double v[n+2][n+2]);


void plate(int n, double u[n+2][n+2], double v[n+2][n+2]);


void box(int n, double u[n+2][n+2], double v[n+2][n+2], int x_start, int x_end,
          int y_start, int y_end);


void piter(int n, double epsi, double u[n+2][n+2], double v[n+2][n+2],
            double p[n+2][n+2], double dt, double h, double beta, int *iflag,
            int x_start, int x_end, int y_start, int y_end,double* div);


void print_pressure(FILE *fidpres, int n, double p[n+2][n+2]);


void calculate_lift_drag(FILE *fidlift, FILE *fiddrag, int n, double p[n+2][n+2],
                         int x_start, int x_end, int y_start, int y_end);


void calculateUVP(int n,double u[n+2][n+2], double v[n+2][n+2], double p[n+2][n+2],
                   double U[n][n], double V[n][n], double P[n][n]);


void stream_function(int n, double u[n+2][n+2], double v[n+2][n+2], double h,
                      double PSI[n+1][n+1]);


void print_results(int n, double u[n+2][n+2], double v[n+2][n+2],
                   double p[n+2][n+2], double U[n][n], double V[n][n],
                    double P[n][n], double PSI[n+1][n+1]);


void make_vtf(int n, double U[n][n], double V[n][n], double P[n][n],
               double PSI[n+1][n+1]);


void write_header(FILE *f, int n);


void write_results(FILE *f, int n, int *teller, double P[n][n],
                    double PSI[n+1][n+1], double U[n][n], double V[n][n]);


void write_steps(FILE *f, int n, int *teller);

