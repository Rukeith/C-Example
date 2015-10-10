/*遞迴回溯法解迷宮*/
#include <stdio.h>

int maze [7][10]={
    1,1,1,1,1,1,1,1,1,1,
    1,0,1,0,1,0,0,0,0,1,
    1,0,1,0,1,0,1,1,0,1,
    1,0,1,0,1,1,1,0,0,1,
    1,0,1,0,0,0,0,0,1,1,
    1,0,0,0,1,1,1,0,0,1,
    1,1,1,1,1,1,1,1,1,1};
/*
x,y代表當前點得位置
回傳值：1代表成功，0代表餵找到路徑
*/

int FindPath (int x, int y)
{
    if(x==5 && y==8)
    {
      maze[x][y]=2;
      return 1;
    }
    else
    {
      if(maze[x][y]==0)
      {
        maze[x][y] = 2;

        if((FindPath(x,y+1)>0 ||
             FindPath(x+1,y)>0 ||
             FindPath(x,y-1)>0 ||
             FindPath(x-1,y)>0 ))
          return 1;
        else
        {
          maze[x][y]=0;
          return 0;
        }

      }
      else
        return 0;
    }
}


void main()
{
    int i,j;
    if(FindPath(1,1))
    {
      printf("找到了一條路徑走出迷宮，其示意圖如下\n");
      for( i=1; i<6; i++ )
      {
        for(j=1;j<9;j++)
          printf("%d  ",maze[i][j]);
        printf("\n");
      }
    }
    else
    {
      printf("沒有合適路徑走出當前迷宮！\n");
    }
}































