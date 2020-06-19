#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define endl "\n"
// #define int int64_t
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
    cin>>n;
    vector<int> a(1000001), position(1000001,0), used(1000001,0);
    fo(i,1,n) {
        cin>>a[i];
        position[a[i]]++;
    }
    int p=0;
    vector<int> ans;
    queue<int> q ;
    fo(i,0,n) {
        if(position[i]==0) continue;

        while(position[i]) {
        if(q .size() > 0) {
            position[i]--;
            ans.push_back(q .front());
            used[q .front()]++;
            q .pop();
            continue;
        }
        while(position[p] or used[p]) p++;
        used[p]++;
        ans.push_back(p++);
        position[i]--;
        }
        q .push(i);
    }
    for(auto it:ans) cout<<it<<" ";
    cout<<endl;
}

int main() {
    GO_BABY_GO;
    solve();
    return 0;
}