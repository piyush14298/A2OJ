#include<bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin>>s;
    int i=0,j=1;
    int ret =0;
    while(j<s.size()) {
        if(s[i] != s[j]) {
            ret++;
            i=j;
            j++;
        }
        i++;
        j++;
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