#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> s(n+1,0);
    for(int i=0;i<n;i++) {
        cin>>s[i+1];
    }
    vector<int> dp(n+1,1);
    // dp[0]=1;dp[1]=1;
    int ret = 1;
    for(int i=1;i<=n;i++) {
        for(int j=i*2;j<=n;j+=i) {
            if(s[i]<s[j]) {
                dp[j] = max(dp[j], 1+dp[i]);
                // ret = max(ret,dp[j*i]);
            }
        }
    }

    for(int i=1;i<=n;i++) {
        ret = max(ret,dp[i]);
    }
    cout<<ret<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}