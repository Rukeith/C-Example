#include<stdio.h>

int main(void)
{
    int l,i=0,j=0;
    printf("Input your width?");
    scanf("%d",&l);
    while(l>i)
    {
      i++;
      printf("*");
    }

    i=0;

    while(i<l-2)
    {
      i++;      
      printf("\n*");
      while(j<l-2){
        printf(" ");
        j++;}
      printf("*");
      j=0;
    }
    
    i=0;
    printf("\n");
    while(l>i)
    {
      i++;
      printf("*");
    }
    
    getchar();
    return 0;  

}
