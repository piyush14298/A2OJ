#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long table[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>table[i][j];
        }
    }

    int a[n];
    a[0]=sqrt((table[0][(1)]*table[0][(2)])/table[(1)][(2)]);
    for(int i=1;i<n;i++)
    {
        a[i]=table[i][0]/a[0];
    }

    for(int i:a)
    {
        cout<<i<<" ";
    }

    return 0;
}