#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf(" %d %d",&a,&b);
        arr[i]=a+b;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}