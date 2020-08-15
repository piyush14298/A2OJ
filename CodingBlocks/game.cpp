#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    int dp[n][n] = {};

    for(int i=n-1;i>=0;i--) {
        for(int j=i;j<n;j++) {
            if(i==j) {
                dp[i][j] = nums[i];
            } else {
                
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
            
        }
    }

    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<n;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[0][n-1]<<endl;

    return 0;
}