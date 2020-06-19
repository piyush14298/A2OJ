#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(a*n != b*m) {
        cout<<"NO"<<endl;
        return;
    }
    // int rows[n];
    // int cols[m];
    // for(int i=0;i<n;i++) rows[i] = a;
    // for(int i=0;i<m;i++) cols[i] = b;
    // int mat[n][m];
    vector<int> rows(n,a);
    vector<int> cols(m,b);
    vector<vector<int> > mat(n, vector<int>(m,0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(rows[i] && cols[j]) {
                mat[i][j] = 1;
                rows[i]--;
                cols[j]--;
            }
        }
    }

    // for(int i=0;i<n;i++) {
    // //     for(int j=0;j<m;j++) {
    // //         if(mat[i][j]) {
    // //             rows[i]++;
    // //             cols[j]++;
    // //         }
    // //     }
    // // }

    // for(auto i:rows) {
    //     if(i!=0) {
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }

    // for(auto i:cols) {
    //     if(i!=0) {
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }

    cout<<"YES"<<endl;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout<<mat[i][j];
        }
        cout<<endl;
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