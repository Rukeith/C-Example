#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double hyoptenuse ( double n, double m);

int main ( void )
{
   double three;
   double a,b;
   printf( "Input your number\n" );
   scanf( "%f %f\n",&a,&b );

   three = double hyoptenuse (a,b);
   printf( "The thrid is %f\n", three);

   return 0;
}


double hyoptenuse ( double n, double m)
{
   double d;
   d = sqrt( n*n + m*m);
   
   return d;
}
