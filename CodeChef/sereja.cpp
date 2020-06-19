#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<int> v(n),post(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    map<int,int> h;
    post[n-1]=1;
    h[v[n-1]]++;
    for(int i=n-2;i>=0;i--)
    {
        if(h[v[i]]++==0)
        {
            post[i]=post[i+1]+1;
        }
        else
        {
            post[i]=post[i+1];
        }
    }

    while(m--)
    {
        int l;
        cin>>l;

        cout<<post[l-1]<<endl;
    }


    return 0;
}