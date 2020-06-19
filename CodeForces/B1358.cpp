#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> g(n);
    for(int i=0;i<n;i++) {
        cin>>g[i];
    }
    sort(g.begin(), g.end());

    int currG = 1;
    int ret=1;
    for(int i=0;i<n;i++) {
        if(g[i]<=currG) {
            ret++;
            currG++;
        } else {
            int tempCurr = currG;
            while(i<n && g[i]>tempCurr) {
                tempCurr++;
                i++;
            }
            if(i<n) {
                ret = i+2;
                currG = ret;
            }
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