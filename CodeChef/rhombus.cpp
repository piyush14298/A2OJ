#include<bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+4*(i-2)+4;
    }

    cout<<dp[n]<<endl;

    return 0;
}