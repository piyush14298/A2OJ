#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }

    sort(s.begin(), s.end());
    int diff= INT_MAX;

    for(int i=1;i<n;i++) {
        diff = min(diff, s[i]-s[i-1]);
    }
    cout<<diff<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}