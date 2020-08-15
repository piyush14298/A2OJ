
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

struct Point 
{ 
    int x, y; 
}; 
ll getInt() {
    ll t;
    cin>>t;
    return t;
}
vll getVector(int n) {
    vll temp(n);
    fo(i,0,n) {
        cin>>temp[i];
    }
    return temp;
}
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



void helper(vector<int>& nums, int index, int curr, int& ret, int& sum) {
    if(index == (int) nums.size()) {
        if(curr*2 >= sum) {
            ret = min(curr, ret);
        }
        return;
    }

    helper(nums, index+1, curr, ret, sum);

    curr+=nums[index];

    if(curr*2 >= sum) {
        helper(nums, nums.size(), curr, ret, sum);
    }
    helper(nums, index+1, curr, ret, sum);
}

void solve() {
    string input;
    getline(cin, input);
    // cout<<input<<endl;
    stringstream ss(input);
    int t;
    vector<int> nums;
    while(ss>>t) {
        // cout<<t<<" ";
        nums.push_back(t);
    
    }
    // cout<<end/l;
    sort(nums.begin(), nums.end());
    int sum = accumulate(nums.begin(), nums.end(),0);
    int ret = sum;

    helper(nums,0,0,ret,sum);

    cout<<ret;
}

int32_t main() {
    GO_BABY_GO;
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}