#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,v;
    cin>>n>>v;

    int cost=0,pos=1,reach=0;
    cost=pos*min(v,n-1);
    reach=pos+v;
    while(reach<n)
    {
        pos++;
        cost+=pos;
        reach++;
    }

    cout<<cost<<endl;

    return 0;
}