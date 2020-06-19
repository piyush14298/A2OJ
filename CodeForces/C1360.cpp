#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> s(n);
    unordered_map<int,int> h;
    int o=0,e=0;
    for(int i=0;i<n;i++) {
        cin>>s[i];
        h[s[i]]++;
        if(s[i]&1)
            o++;
        else 
            e++;
    }
    if(e%2==0) {
        cout<<"YES"<<endl;
    } else {
        bool exists= false;
        for(int i:s) {
            if(i&1) {
                if(h[i-1] || h[i+1]) {
                    exists = true;
                    break;
                }
                    
            }
        }
        if(exists)
            cout<<"YES"<<endl;
        else 
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