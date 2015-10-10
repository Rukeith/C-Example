#include<stdio.h>

int main(void)
{
   float gallons;
   float miles;
   float summ=0;
   float j=0;
   float sumg=0;
   printf("Enter the gallons used (-1 to end): ");
   scanf("%f",&gallons);
   printf("Enter the miles driven: ");
   scanf("%f",&miles);

   while(gallons!=(-1)){
     printf("The miles / gallon for this tank was %f\n\n", miles / gallons);
     summ+=miles;
     sumg+=gallons;     
     
     printf("Enter the gallons used (-1 to end): ");
     scanf("%f",&gallons);
     if(gallons!=-1){
       printf("Enter the miles driven: ");
       scanf("%f",&miles);
     }
   }
   
   printf("The overall average miles/gallon was %f\n",summ / sumg);
   return 0;
}
