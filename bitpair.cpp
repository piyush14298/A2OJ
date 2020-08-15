
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

char bitScore(int a) {
    vector<int> digits;
    while(a) {
        digits.push_back(a%10);
        a/=10;
    }
    sort(digits.begin(), digits.end());
    int ret = digits[0]*7 + digits[2]*11;
    string ans = to_string(ret);
    if(ans.size()>2) {
        return ans[1];
    } 
    return ans[0];
}


void solve() {
    int n;
    cin>>n;
    vector<char> nums(n);
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        nums[i] = bitScore(a);
        // cout<<nums[i]<<" ";
    }
    // cout<<endl;

    unordered_map<char,int> even;
    unordered_map<char,int> odd;

    for(int i=0;i<n;i++) {
        if(i&1) {
            odd[nums[i]]++;
        } else {
            even[nums[i]]++;
        }
    }

    int ret=0;

    unordered_map<char,int> res;

    for(auto i: even) {
        if(i.second > 1) {
            if(i.second > 2) {
                res[i.first]++;
            }
            res[i.first]++;
        }
    }
    for(auto i: odd) {
        if(i.second > 1) {
            if(i.second > 2) {
                res[i.first]++;
            }
            res[i.first]++;
        }
    }

    for(auto i: res) {
        ret+=min(2,i.second);
    }

    cout<<ret<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}