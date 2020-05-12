#include "header.h"
void choose_BC(int *bcPar,int *x_start, int x_end,int y_start,int y_end){
int a,b,c,d,e;
printf("Which model will you run?\n");
printf("Press 1 for cavity box \n");
printf("Press 2 for channel flow\n");
printf("Press 3 for plate in uniform flow\n");
printf("Press 4 for box in uniform \n");
scanf("%d",&a);
*bcpar=a;
while (*bcpar <1 || *bcpar>4){
    printf("Invalid input from user! Choose 1,2,3, or 4 \n");
    scanf("%d,&a");

}//end while
if (*bcpar ==4.0 ){
    printf("Choose x starting \n");
    scanf("%d",&b);
    printf("Choose y starting \n");
    scanf("%d",&c);
    printf("Choose x ending \n");
    scanf("%d",&d);
    printf("Choose y ending \n");
    scanf("%d",&e);

} //endif
    *x_start=b;
    *y_start=c;
    *x_end=d;
    *y_end=e;





}//end void
