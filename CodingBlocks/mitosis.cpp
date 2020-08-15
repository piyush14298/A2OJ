#include<bits/stdc++.h>
using namespace std;

int getWays(int n, int curr, int x, int y, int z) {
    int dp[n+1] = {};

    for(int i=2;i<=n;i++) {
        if(i%2==0) {
            dp[i] = min(dp[i/2]+x, dp[i-1]+y);
        } else {
            dp[i] = min(dp[i-1]+y, dp[(i+1)/2]+x+z);
        }
    }

    return dp[n];
}

// int getWaysBU(int n) {
//     vector<int> dp(n+1,0);
    
// }

int main() {
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    int ret = getWays(n,1,x,y,z);

    cout<<ret<<endl;

    return 0;
}