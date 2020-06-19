#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll max(ll a, ll b) {
    return a>b?a:b;
} 

void solve() {
    int n;
    cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    ll ret=0;
    bool p=nums[0]>0, ne=nums[0]<0;
    int i=1, maxP=p?nums[0]:0, maxN=ne?nums[0]:INT_MIN;
    while(i<n) {
        if(nums[i-1]>0) {
            if(nums[i]>0)
                maxP = max(maxP,nums[i]);
            else {
                ret+=maxP;
                maxP=0;
                maxN = max(maxN,nums[i]);
            }
        } else {
            if(nums[i]<0)
                maxN = max(maxN,nums[i]);
            else {
                ret+=maxN;
                maxN = INT_MIN;
                maxP = max(maxP,nums[i]);
            }
        }
        i++;
    }
    if(maxP!=0)
        ret+=maxP;
    else
        ret+=maxN;
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