/*
interpolate.c
--------------------------------------------------------------------------------------
Purpose         Interpolating the optimal relaxation parameter for a chosen n-value
Call sequence   interpolate(n)
--------------------------------------------------------------------------------------
Variables
--------------------------------------------------------------------------------------
Name			Type			Description

Global:
--------
n				int				Number of gridscells in the domain
dt              int             Timestep

Local:
----------
nn				int	            Array containing values of n
i               int             Counting variable
omega			double			Relaxation parameter for iterative methods
oo				double			Array containing values for omega to the
                                corresponding n-value
--------------------------------------------------------------------------------------
Candidate number: 10085
Last  modified 05.05.2019

*/


double interpolate(int n){
	int i, nn[9] ={ 0,5,10,20,30,40,60,100,500 }; //values from sola.m
	double oo[9] ={ 1.7,1.78,1.86,1.92,1.95,1.96,1.97,1.98,1.99 }; //values from sola.m
    double omega;


	for (i = 0; i < sizeof(nn); i++){
		if (n < nn[i]) {
			omega = oo[i - 1]+ (oo[i + 1]- oo[i - 1])*(n - nn[i - 1])/(nn[i + 1] - nn[i - 1]);

			break;
		}/*End if*/
	}/*End for*/

	return omega;
}/*End funciton*/
