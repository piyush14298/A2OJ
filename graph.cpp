
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

int distanceFromTo(int a, int b) {
    if(a==b) {
        return 0;
    }
    int ret=0;
    while(a!=b) {
        int ans=1;
        for(int i=2;i*i<=a;i++) {
            if(a%i==0) {
                ans = a/i;
                break;
            }
        }
        a =ans;
        ret++;
    }

    return ret;
}

void solve() {
    int m,n;
    cin>>n>>m;
    int g = __gcd(m,n);

    int ret = distanceFromTo(m,g)+distanceFromTo(n,g);

    cout<<ret<<"";
}

int32_t main() {
    GO_BABY_GO;
    ll t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}