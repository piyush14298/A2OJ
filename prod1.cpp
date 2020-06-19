#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    int oddNeg=0;
    long long int ans=0,nZ=0;

    for(int i:v)
    {
        if(i<0)
        {
            ans=ans+(-1-i);
            oddNeg=1-oddNeg;
        }
        else if(i>0)
        {
            ans+=i-1;
        }
        else
        {
            nZ++;
        }
    }

    if(oddNeg && nZ>0)
    {
        ans+=nZ;
    }
    else if(oddNeg && nZ==0)
    {
        ans+=2;
    }
    else
    {
        ans+=nZ;
    }
    
    cout<<ans<<endl;

    return 0;
}