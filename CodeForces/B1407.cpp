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

vector<int> getVector(int n) {
    vector<int> ret(n);
    for(int i=0;i<n;i++) {
        cin>>ret[i];
    }
    return ret;
}

void printVector(vector<int>& nums) {
    for(int i:nums) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

int getInt() {
    int n;
    cin>>n;
    return n;
}

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
    auto nums = getVector(n);
    if(n==1) {
        printVector(nums);
        return;
    }
    vector<bool> seen(n,false);
    vector<int> sol;
    int a=nums[0],x=0,g;
    for(int i=0;i<n;i++) {
        if(nums[i]>a) {
            a = nums[i];
            x=i;
        }
    }
    sol.push_back(a);
    seen[x] = true;
    g=a;
    while(sol.size() < n) {
        int x = g;
        int nG=0, j;
        for(int i=0;i<n;i++) {
            if(seen[i]) continue;
            int t = gcd(x, nums[i]);
            if(t>nG) {
                j = i;
                nG = t;
            }
        }
        sol.push_back(nums[j]);
        seen[j] = true;
        g = nG;
    }
    printVector(sol);
}

int32_t main() {
    GO_BABY_GO;
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}