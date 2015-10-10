#include<stdio.h>
#include<math.h>

int main ( void )
{
   float num;
   int y;
   printf( "Input your number\n" );
   scanf( "%f", &num );
   y = floor( num + .5 );
   printf( "%d   %f", y,num );

   return 0;
}
