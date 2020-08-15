#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+1,0);
    dp[n] = 1;
    dp[n-1] = 1;

    for(int i=n-2;i>=0;i--) {
        dp[i] = dp[i+1]*2;
        if(i+k+1<=n) {
            dp[i]-=dp[i+k+1];
        }
    }
    cout<<dp[0]<<endl;

    return 0;
}