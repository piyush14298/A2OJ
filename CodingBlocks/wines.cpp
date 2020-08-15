#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> wines(n);
    for(int i=0;i<n;i++) {
        cin>>wines[i];
    }

    vector<vector<int> > dp(n,vector<int>(n,0));

    for(int i=n-1;i>=0;i--) {
        for(int  j=i;j<n;j++) {
            if(i==j) {
                dp[i][j] = n*wines[i];
            } else {
                dp[i][j] = max((n-j+i)*wines[i]+dp[i+1][j], (n-j+i)*wines[j]+dp[i][j-1]);
            }
        }
    }

    cout<<dp[0][n-1]<<endl;

    return 0;
}