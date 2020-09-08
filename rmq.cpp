#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);

    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    int l = log2(n);
    vector<vector<int> > rmq(l+1);
    rmq[0] = nums;

    for(int i=1;i<=l;i++) {
        rmq[i].resize(rmq[i-1].size()-i);
        for(int j=0;j<rmq[i-1].size()-i;j++) {
            rmq[i][j] = min(rmq[i-1][j],rmq[i-1][j+i]);
        }
    }

    // for(auto v:rmq) {
    //     for(int i:v) {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    int q;
    cin>>q;

    while(q--) {
        int l,r;
        cin>>l>>r;
        int lg = log2(r-l+1);
        int sml = rmq[lg][l];
        for(int j=l+1;j+(1<<lg)-1<=r;j++) {
            sml = min(sml, rmq[lg][j]);
        }
        cout<<sml<<endl;
    }

    return 0;
}