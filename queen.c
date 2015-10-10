#include <stdio.h>
#include <math.h>

int a[9]={100};
int count = 0;

int Place( int i, int value )
{
    int j;
    if(i==1) return 1;
    for( j=1; j<i; j++ )
    {
        if(a[j]==value)
          return 0;
        if(abs(i-j)==abs(value-a[j]))
          return 0;
    }
    return 1;
}

void ShowResult()
{
    int i,j;
    for(j=1;j<=8;j++)
    {
      for(i=1;i<a[j];i++)
      {
        printf("* ");
      }
      printf("Q");
      for(i=i+1;i<=8;i++)
      {
        printf("* ");  
      }
      printf("\n");
    }
}


void Backtrack(int t)
{
    int i;
    if(t>8)
    {
      printf("******************************\n");
      ShowResult();
      count++;
      return;
    }
   
    else
    {
      for(i=1;i<=8;i++)
      {
        if(Place(t,i))
        {
          a[t]=i;
          Backtrack(t+1);
        }
      }
    }
}

void ShowCount()
{
    printf("\n八皇后問題共有%d個解\n",count);
}

void main()
{
    Backtrack(1);
    ShowCount();
}

























































