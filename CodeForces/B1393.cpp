
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

void solve() {
    int n;
    cin>>n;
    unordered_map<int, int> planks;
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        planks[a]++;
    }
    
    int q;
    cin>>q;
    int fours=0, twos=0;
    for(auto i: planks) {
        fours+=(i.second)/4;
        twos+=(i.second % 4) /2;
    }

    while(q--) {
        char c;
        int a;
        cin>>c>>a;
        int prev = planks[a];
        if(c=='+') {
            int c = planks[a]%4;

            if(c==1) {
                twos++;
            } else if(c==3) {
                twos--;
                fours++;
            }
            
            planks[a]++;

        } else {
            planks[a]--;
            int c = prev%4;
            if(c==0) {
                fours--;
                twos++;
            } else if(c==2) {
                twos--;
            }
        }
        
        if(fours>1 || (fours==1 && twos>1)) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
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