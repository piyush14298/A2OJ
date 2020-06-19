#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin>>n>>k;

    vector<int> a(n);

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int deficit=k-a[0],ans=0;

    for(int i=1;i<n;i++)
    {
        if(a[i]<deficit)
        {
            ans+=deficit-a[i];
            a[i]=deficit;
        }
        deficit=k-a[i];
    }

    cout<<ans<<endl;

    for(int i:a)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}