#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    int sum=0, ret=0;
    for(int i=0;i<n;i++) {
        sum+=nums[i];
        if(sum < 0) {
            sum=0;
        }
        ret = max(ret,sum);
    }
    cout<<ret<<endl;

    return 0;
}