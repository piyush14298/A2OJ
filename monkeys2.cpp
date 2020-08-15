
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
// #define int int64_t
#define ll long long
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define endl "\n"

// struct Point 
// { 
//     int x, y; 
// }; 
// ll getInt() {
//     ll t;
//     cin>>t;
//     return t;
// }
// vll getVector(int n) {
//     vll temp(n);
//     fo(i,0,n) {
//         cin>>temp[i];
//     }
//     return temp;
// }
// void printVector(vector<ll> a) {
//     fo(i,0,a.size()) {
//         cout<<a[i]<<" ";
//     }
//     cout<<endl;
// }
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

ull gcd(ull a, ull b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}

// ull findLCM(vector<int>& times) {
//     ull ret = times[0];
//     int n = times.size();

//     for(int i=1;i<n;i++) {
//         ret = (ret*times[i])/gcd(ret,times[i]);
//     }

//     return ret;
// }

string toString(vector<int>& nums) {
    string ret="";

    for(int i:nums) {
        ret+=to_string(i)+":";
    }
    return ret;
}

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        nums[i] = a-1;
    }
    // vector<int> times;
    ull ret=0;
    map<string, bool> seen;
    vector<int> pos(n);
    for(int i=0;i<n;i++) {
        pos[i] = i;
    } 

    while(!seen[toString(pos)]) {
        vector<int> temp(n);
        for(int i=0;i<n;i++) {
            temp[nums[i]] = pos[i];
        }
        seen[toString(pos)] = true;
        swap(temp,pos);
        ret++;
    }

    cout<<ret;
}

int32_t main() {
    GO_BABY_GO;
    ll t ;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}