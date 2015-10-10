#include<stdio.h>

int main (void)
{
    int i=0;
    int counter=0;
    int sum=0;
    printf("Input some numbers to calculate average .\n");
    scanf("%d", &i);
    while(i != 9999){
      sum = sum + i;
      counter = counter + 1;
      scanf("%d", &i);
    }
    printf("Average is %f \n",(float)sum/counter);
    return 0;
}
