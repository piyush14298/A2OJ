#include<bits/stdc++.h>
using namespace std;
int n,pr,rp;
struct node {
    int val=-1;
};
unordered_map<string,node> dp;

int helper(string s) {
    if(s=="") {
        return 0;
    }

    if(dp[s].val != -1) {
        return dp[s].val;
    }

    int ret=0;

    for(int i=0;i<s.size()-1;i++) {
        if(s[i]=='p' && s[i+1]=='r') {
            string t = s.substr(0,i) + (i==n-2?"":s.substr(i+2));
            ret = max(ret,pr+helper(t));
        }
        if(s[i]=='r' && s[i+1]=='p') {
            string t = s.substr(0,i) + (i==n-2?"":s.substr(i+2));
            ret=  max(ret, rp+helper(t));
        }
    }

    return dp[s].val = ret;
}

void solve() {
    string s;
    cin>>s>>pr>>rp;
    int ret = helper(s);
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