#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;

    vector<int> dp(n+1);
    dp[1] = 0;

    for(int i=2;i<=n;i++) {
        int a = dp[i-1];
        if(i%2==0) {
            a = min(a,dp[i/2]);
        }
        if(i%3==0) {
            a = min(dp[i/3],a);
        }
        dp[i] = a+1;
    }
    cout<<dp[n]<<endl;

    return 0;
}