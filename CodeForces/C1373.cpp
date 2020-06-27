
/////////////////             ____ ___ _ _  _           *******************************
/////////////////            |  _ \_ _/ | || |          *******************************
/////////////////            | |_) | || | || |_         *******************************
/////////////////            |  __/| || |__   _|        *******************************
/////////////////            |_|  |___|_|  |_|          *******************************

#include<bits/stdc++.h>
using namespace std;
#define int int64_t
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
void printVector(vector<ll> a) {
    fo(i,0,a.size()) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
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

// int abs(int a) {
//     return a<0?-a:a;
// }

void solve() {
    string s;
    cin>>s;
    // cout<<s<<endl;
    int sm = 1;
    int present = 0;
    vector<int> currs(s.size());
    for(int i=0;i<s.size();i++) {
        char c = s[i];
        if(c=='+'){
            present++;
            // cout<<c;
        }
        else if(c=='-'){
            present--;
            // cout<<c;
        }
        // cout<<present<<endl;
        currs[i] = present;
        sm = min(sm,present);
    }
    // cout<<sm<<endl;
    // int limit = abs(sm);
    if(sm >= 0) {
        cout<<s.size()<<endl;
        return;
    }
    // cout<<limit<<endl;
    int ret=0;
    int limit = abs(sm)+1;
    ret+=limit;
    int last=ret;
    for(int i=1;i<currs.size();i++) {
        if(currs[i-1] >= 0) {
            ret+=last=min(last,limit);
        } else {
            ret+=last = min(last,(limit - abs(currs[i-1])));
        }

    }

    // fo(i,sm,1) {
    //     int temp=0;
    //     // i *= -1;
    //     do {
    //         temp++;
    //     }
    //     while(temp < currs.size() && i<=currs[temp-1]);
    //     ret+=temp;
    // }
    cout<<ret<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}