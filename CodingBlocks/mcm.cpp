#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int sizes[n][2];
    for(int i=0;i<n;i++) {
        cin>>sizes[i][0]>>sizes[i][1];
    }

    // int dp[n][n] = {};
    vector<vector<int> > dp(n, vector<int>(n,0));

    for(int i=n-2;i>=0;i--) {
        for(int j=i+1;j<n;j++) {
            if(j-i == 1) {
                dp[i][j] = sizes[i][0] * sizes[i][1] * sizes[j][1];
            } else {
                int temp=INT_MAX;
                for(int k=i;k<j;k++) {
                    int a = dp[i][k] + dp[k+1][j] + sizes[i][0] * sizes[k][1] * sizes[j][1];
                    temp = min(a,temp);
                }
                dp[i][j] = temp;
            }
        }
    }
    for(auto i:dp) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    // cout<<dp[0][n-1]<<endl;
    return 0;
}