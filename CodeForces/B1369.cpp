// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
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
    fo(i,0,n-1) {
        cin>>temp[i];
    }
    return temp;
}
void printVector(vector<ll> a) {
    fo(i,0,a.size()-1) {
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

void solve() {
    int n;
    string s;
    cin>>n>>s;
    string z="";
    string o="";
    int i=0;
    while(i<n && s[i]=='0') {
        z+="0";
        i++;
    }
    int j=n-1;
    while(j>=0 && s[j]=='1') {
        o+='1';
        j--;
    }
    string ret="";
    if(i<j) {
        ret = z+"0"+o;
    } else {
        ret = z+o;
    }
    
    // vector<pair<char, int> > rep;
    // int z=s[0]=='0'?1:0;
    // int o = 1-z;
    // int temp = 1;
    // for(int i=1;i<s.size();i++) {
    //     if(s[i]!=s[i-1]) {
    //         if(o) {
    //             rep.push_back({'o',temp});
    //             temp=1;
    //             o=0;
    //             z=1;
    //         } else {
    //             rep.push_back({'z',temp});
    //             temp=1;
    //             o=1;
    //             z=0;
    //         }
    //     } else {
    //         temp++;
    //     }
    // }
    // if(o) {
    //     rep.push_back({'o',temp});
    //     temp=1;
    //     o=0;
    //     z=1;
    // } else {
    //     rep.push_back({'z',temp});
    //     temp=1;
    //     o=1;
    //     z=0;
    // }
    // string ret="";
    // for(int i=0;i<rep.size();i++) {
    //     if(i==rep.size()-1) {
    //         while(rep[i].second--) {
    //             ret+="1";
    //         }
    //     } else {
    //         if(rep[i].first == 'o' && rep[i+1].first=='z') {
    //             ret+="0";
    //             i++;
    //         } else {
    //             while(rep[i].second--) {
    //                 ret+="0";
    //             }
    //         }
    //     }
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