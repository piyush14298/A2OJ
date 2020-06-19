#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin>>n;
    vector<ll> stones(n), sortedStones(n);
    for(int i=0;i<n;i++) {
        cin>>stones[i];
        sortedStones[i] = stones[i];
    }
    sort(sortedStones.begin(), sortedStones.end());
    vector<ll> dp(n+1), dpSorted(n+1);
    dp[0] = dpSorted[0] = 0;

    for(int i=0;i<n;i++) {
        dp[i+1] = dp[i]+stones[i];
        dpSorted[i+1] = dpSorted[i]+sortedStones[i];
    }

    int t;
    cin>>t;
    while(t--) {
        int type, l, r;
        cin>>type>>l>>r;
        if(type == 1) {
            cout<<dp[r]-dp[l-1]<<endl;
        } else {
            cout<<dpSorted[r] - dpSorted[l-1]<<endl;
        }
    }
    return 0;
}