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

    for(int i=0;i<l;i++) {
        for(int j=0;j+(1<<i) < rmq[i].size();j++) {
            rmq[i+1].push_back(min(rmq[i][j] , rmq[i][j+(1<<i)]));
        }
    }

    for(auto v:rmq) {
        for(int i:v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    int q;
    cin>>q;

    while(q--) {
        int l,r;
        cin>>l>>r;
        int lg = log2(r-l+1);
        int sml = min( rmq[lg][l], rmq[lg][r-(1<<lg)+1]);
        cout<<sml<<endl;
    }

    return 0;
}