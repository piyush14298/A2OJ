#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    int ret=1, t=1;
    for(int i=1;i<n;i++) {
        if(nums[i] <= nums[i-1]*2) {
            t++;
        } else {
            t=1;
        }
        ret = max(ret, t);
    }

    cout<<ret<<endl;
    return 0;
}