// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
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

vector<int> getFact(int n) {
    int i=sqrt(n);
    while(i>1) {
        if(n%i==0) {
            return {i,n/i};
        }
        i--;
    }
    return {1,n};
}

void print(int i, int curr, int total) {
    if(curr==total) {
        cout<<i<<" "<<i<<endl;
        return;
    }
    cout<<i<<" "<<i<<endl;
    cout<<i+1<<" "<<i<<endl;
    cout<<i<<" "<<i+1<<endl;
    print(i+1, curr+1, total);
}

void solve() {
    int n;
    cin>>n;
    cout<<3*n+4<<endl;
    print(0,0,n+1);
    return;
    // auto t = getFact(n);
    
    // if(t[0]==1) {
    //     cout<<3*n+4<<endl;
    //     print(0,0,n+1);
    //     return;
    // } else {
    //     cout<<(t[0]+2)*(t[1]+2) - 4 <<endl;
    //     for(int i=0;i<t[0]+2;i++) {
    //         for(int j=0;j<t[1]+2;j++) {
    //             if((i==0&&j==0)||(i==0&&j==t[1]+1)||(i==t[0]+1&&j==0)||(i==t[0]+1&&j==t[1]+1))
    //                 continue;
    //             cout<<i<<" "<<j<<endl;
    //         }
    //     }
    // }
}

int32_t main() {
    GO_BABY_GO;
    ll t = 1;
    while(t--) {
        solve();
    }
    return 0;
}