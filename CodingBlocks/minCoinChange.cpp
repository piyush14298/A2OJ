#include<bits/stdc++.h>
using namespace std;

long long min(long long a, long long b) {
    return a<b?a:b;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> coins(m);
    for(int i=0;i<m;i++) {
        cin>>coins[i];
    }

    vector<long long> dp(n+1);
    dp[0]=0;

    for(int i=1;i<=n;i++) {
        int ans = INT_MAX;
        for(int j:coins) {
            if(i-j >=0) {
                ans = min(ans, dp[i-j]+1);
            } 
        }
        dp[i] = ans;
    }
    cout<<dp[n]<<endl;

    return 0;
}