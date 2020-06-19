#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> h(n);
    for(int i=0;i<n;i++) {
        cin>>h[i];
    }
    int i=0;
    for(;i<n-1;i++) {
        int low = max(0,h[i+1]-k);
        if(h[i]>=low) {
            m+=(h[i] - low);
        } else {
            if(low - h[i] > m) {
                break;
            } else {
                m -= (low-h[i]);
            }
        }
    }
    if(i==n-1) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}