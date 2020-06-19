#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    int t = 1;
    for(int i=0;i<n;i++) {
        for(int j=(i&1?(n-1):0);j>=0&&j<n;j=j+(i&1?-1:1)) {
            mat[i][j] = t++;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}