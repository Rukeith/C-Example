#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int integerPower(int base ,int exponent);

int main ( void )
{
   int sum,base,exponent;
   printf( "Input your numbers\n" );
   scanf( "%d %d\n",&base,&exponent );
   
   sum = int integerPower(base,exponent);

   printf("%d\n",sum);

   return 0;
}

int tegerPower(a,b)
{
   int sum = 1;
   int i;
   for(i=1;i<=b;i++)
   {
    sum  = sum*a;

   }
   return sum;
}
