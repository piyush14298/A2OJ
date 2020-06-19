#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// #define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
// #define fo(i,a,b) for(ll i=a;i<=b;i++)
// #define vi vector<int>
// #define vll vector<ll>
// #define vull vector<ull>
// #define endl "\n"
// #define int int64_t
ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}

// vector<int> arr(1000000001,0);

void solve() {
    ll n,x,m;
    cin>>n>>x>>m;
    int l=x, h=x;
    while(m--) {
        ll a,b;
        cin>>a>>b;
        if((a>=l && a<=h) || (b>=l && b<=h) || (a<=l && b>=h)) {
            l = min(l,a);
            h = max(h,b);
        }
    }
    cout<<h-l+1<<endl;
}

int main() {
    GO_BABY_GO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}