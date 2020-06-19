#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void f() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    unordered_map<char,int> h;
    for(char c:s) {
        h[c]++;
    }

    while(q--) {
        int k;
        cin>>k;
        int res = 0;
        for(auto i:h) {
            res+=max(0,i.second - k);
        }
        cout<<res<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        f();
    }
    return 0;
}