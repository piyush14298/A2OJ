#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,m;
    cin>>n>>m;
    if(n%2!=0) 
        swap(n,m);
    cout<<n*(m/2) +( m%2==0?0:(n+1)/2)<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}