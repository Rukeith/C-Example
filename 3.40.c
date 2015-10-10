#include<stdio.h>

int main()
{
    int i,j,k=2;
    while((k%2)==0 && k<9){
      k+=2;
      i=0;
      j=0;
      while(i<8){
        i++;
        printf("* ");
      }
      printf("\n");
      printf(" ");
      while(j<8){
        j++;
        printf("* ");
      }
      printf("\n");
    }
    
    
    return 0;

}
