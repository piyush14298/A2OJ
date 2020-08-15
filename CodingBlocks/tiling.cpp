//Given a floor of size n x m. Find the number of ways to tile the floor with tiles of size 1 x m . 
//A tile can either be placed horizontally or vertically.

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

void solve() {
    int n,m;
    cin>>n>>m;
    vector<long> dp(n+1);
    dp[0]=1;

    for(int i=1;i<=n;i++) {
        dp[i] = dp[i-1];
        if(i-m>=0) {
            dp[i]+=dp[i-m];
            dp[i]%=mod;
        }
    }

    cout<<dp[n]<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }

    return 0;
}