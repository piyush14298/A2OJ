#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    int res = 1;
    for(int i=1;i*i<=n && i<=k;i++) {
        if(n%i==0) {
            int j = n/i;
            if(i>j)
                swap(i,j);
            if(j<=k) {
                res = max(res,j);
            } else if(i<=k) {
                res = max(res,i);
            }
        }
    }
    cout<<n/res<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}