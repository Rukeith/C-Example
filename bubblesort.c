/*bubblesort*/
void BubbleSort( int *Array, int n )
{
    int a,i,j;
    for( i=n-1; i>0; i-- )
        for( j=0; j<i; j++ )
            if( *(Array+j) > *(Array+j+1))
            {
                a=*(Array+j);
                *(Array+j)=*(Array+j+1);
                *(Array+j+1)=a;
            }
}

void main()
{
    int Array[8]={5,9,2,16,7,4,12,15};
    int i;
    printf("待排序數組為: \n");
    for(i=0;i<8;i++)
        printf("%d ",*(Array+i));
        

}
