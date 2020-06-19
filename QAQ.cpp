#include<bits/stdc++.h>
using namespace std;

int main()
{
    string in;
    cin>>in;

    vector<int> pre(in.size(),0),post(in.size(),0);

    int i=0,p=0;
    for(int j=0;j<pre.size();j++)
    {
        if(in[j]=='Q')
        {
            pre[j]=++i;
        }
        else
        {
            pre[j]=i;
        }

        int k=pre.size()-j-1;

        if(in[k]=='Q')
        {
            post[k]=++p;
        }
        else
        {
            post[k]=p;
        }
    }

    int ans=0;

    for(int j=0;j<in.size();j++)
    {
        if(in[j]=='A')
        {
            // cout<<pre[j]<<" "<<post[j]<<endl;
            ans+=pre[j]*post[j];
        }
    }
    
    cout<<ans<<endl;

    return 0;
}