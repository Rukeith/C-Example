#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float calculateCharges ( float hr );

int main ( void )
{
   float sum = 0;
   float time;
   int i;
   printf("Car        Hours       Charge\n");
   for ( i = 0; i <= 3; i++ ){
      printf( "%d        ", i);
      scanf( "%f", &time);
      printf( "%f       %f\n", time, calculateCharges( time ) );
      sum = time + sum;
   }
   printf( "TOTAL      %f       %f", sum, calculateCharges(sum) );

   return 0;
}

float calculateCharges (float hr )
{
   float charge = 0;
   int x = 0;
   if( hr <= 3) {
      charge = 2;
   }
   else {
      x = ceil ( hr );
      charge = ( x - 3) * 0.5 + 2 ;
      if ( charge > 10.00){
         charge = 10.00;
      }
   }

   return charge;
}
