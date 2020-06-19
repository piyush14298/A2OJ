#include<stdio.h>

int mod(int a)
{
    return a>0?a:(-a);
}

int main()
{
    int arr[5][5];
    int r,c;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int temp;
            scanf(" %d",&temp);
            if(temp==1)
            {
                r=i;
                c=j;
            }
        }
    }
    int res=mod(r-2)+mod(c-2);
    printf("%d",res);

    return 0;
}