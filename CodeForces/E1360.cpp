#include<bits/stdc++.h>
using namespace std;

bool isBlock(vector<vector<char> >& mat, int i, int j) {
    int n = mat.size();

    if(i>=n || j>=n) 
        return true;
    if(mat[i][j] == '1')
        return true;
    return false;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<char> > mat(n, vector<char>(n));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>mat[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(mat[i][j] == '1') {
                if(!isBlock(mat,i,j+1) && !isBlock(mat,i+1,j)) {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}