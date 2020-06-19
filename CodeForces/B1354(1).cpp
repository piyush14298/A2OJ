#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int i=0,j=-1,n=s.size();
    int ans = INT_MAX;
    bool o=false,tw=false,th=false;
    // if(s[0]=='1') o=true;
    // if(s[0]=='2') tw=true;
    // if(s[0]=='3') th=true;

    while(j<n) {
        j++;
        if(s[j] == s[i]&&i<j) {
            i++;
            while(i<j && s[i]==s[i+1]) i++; 
        }
        if(s[j]=='1') o=true;
        if(s[j]=='2') tw=true;
        if(s[j]=='3') th=true;

        if(o && tw && th) {
            ans = min (ans, j-i+1);
            // cout<<ans<<endl;
        }
    }
    if(ans==INT_MAX) {
        cout<<0<<endl;
        return;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}