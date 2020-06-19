#include<bits/stdc++.h>
using namespace std;



void solve() {
    int n,x;
    cin>>n>>x;
    int odd=0;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        if(nums[i]%2!=0)
            odd++;
    }
    int even = n - odd;
    if(odd==0) {
        cout<<"NO"<<endl;
        return;
    }
    if(odd%2==0)
        odd--;
    // int y = (odd%2==0?odd-1:odd) + even;
    if(x%2==0) {
        if(even > 0 && even+odd>=x) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    } else {
        if(even+odd >= x) {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
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