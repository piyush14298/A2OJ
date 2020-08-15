
/////////////////             ____ ___ _ _  _           *******************************
/////////////////            |  _ \_ _/ | || |          *******************************
/////////////////            | |_) | || | || |_         *******************************
/////////////////            |  __/| || |__   _|        *******************************
/////////////////            |_|  |___|_|  |_|          *******************************

#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<stack>
// #include<queue>
// #include<unordered_map>
// #include<set>
// #include<algorithm>
using namespace std;
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"


ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

int dp[201][201][201];
vector<int> red,gre,blu;
int r,g,b;

int helper(int i, int j, int k) {
    if((i>=r&&j>=g) || (j>=g&&k>=b) || (k>=b&&i>=r)) {
        return 0;
    }

    if(dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    int a,b,c;
    a=b=c=-1;
    if(i<r && j<g) {
        a = red[i]*gre[j] + helper(i+1,j+1,k);
    }
    if(i<r && k<b) {
        b =  red[i]*blu[k] + helper(i+1,j,k+1);
    }
    if(k<b && j<g) {
        c = gre[j]*blu[k] + helper(i,j+1,k+1);
    }
    dp[i][j][k] = max({a,b,c});
    // cout<<dp[i][j][k]<<endl;
    return dp[i][j][k];
}

void solve() {
    // int r,g,b;
    cin>>r>>g>>b;
    
    for(int i=0;i<r;i++) {
        int j;
        cin>>j;
        red.push_back(j);
    }
    for(int i=0;i<g;i++) {
        int j;
        cin>>j;
        gre.push_back(j);
    }
    for(int i=0;i<b;i++) {
        int j;
        cin>>j;
        blu.push_back(j);
    }
    sort(red.begin(), red.end());
    sort(gre.begin(), gre.end());
    sort(blu.begin(), blu.end());

    memset(dp, 0, sizeof dp);

    for(int i=0;i<=r;i++) {
        for(int j=0;j<=g;j++) {
            for(int k=0;k<=b;k++) {
                if(i&&j) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j-1][k] + red[i-1]*gre[j-1]);
                if(j&&k) dp[i][j][k] = max(dp[i][j][k], dp[i][j-1][k-1] + gre[j-1] * blu[k-1]);
                if(k&&i) dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-1] + red[i-1] * blu[k-1]);
            }
        }
    }

    cout<<dp[r][g][b]<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}