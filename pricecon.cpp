#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    int ret=0;
    while(n--) {
        int a;
        cin>>a;
        if(a>k) {
            ret+=(a-k);
        }
    }
    cout<<ret<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}