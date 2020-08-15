#include<bits/stdc++.h>
using namespace std;
#define int int64_t

// vector<vector<int>> factors;

vector<int> getFactors(int a) {
    vector<int> ret;
    for(int i=1;i<sqrt(a);i++) {
        if(a%i==0) {
            ret.push_back(i);
            ret.push_back(a/i);
        }
    }

    int s = sqrt(a);

    if(s*s == a) {
        ret.push_back(s);
    }

    return ret;
}

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    vector<int> ret(n,0);

    for(int i=0;i<n;i++) {
        for(int j=1;j*(i+1)<=n;j++) {
            ret[((i+1)*j)-1]+=nums[i];
        }
    }

    for(int i:ret) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main() {
    // factors.resize(100001);
    // for(int i=1;i<factors.size();i++) {
    //     for(int j=1;i*j<factors.size();j++) {
    //         factors[i*j].push_back(i);
    //     }
    // }
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}