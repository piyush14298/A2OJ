#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++)
    {
        int t1,t2,t3;
        scanf(" %d %d %d",&t1,&t2,&t3);
        x+=t1;
        y+=t2;
        z+=t3;
    }
    if(x==0&&y==0&&z==0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    
    return 0;
}