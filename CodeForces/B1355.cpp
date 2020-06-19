#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    int ret = 0;

    // int i=n-1;
    // while(i>=0) {
    //     i-=nums[i];
    //     ret++;
    // }

    int i=0,j=0, grt = nums[0];
    vector<int> sizes;
    while(j<n) {
        grt=max(grt,nums[j]);
        if(grt <= j-i+1) {
            sizes.push_back(j-i+1);
            ret++;
            j++;
            i=j;
            // if(j==n-1)
            //     break;
            grt = -1;
        } 
        // else if(j==n-1){
        //     sort(sizes.begin(),sizes.end(),greater<int>());
        //     grt -= (j-i+1);
        //     int p=0;
        //     while(p<sizes.size() && grt > 0) {
        //         grt-=sizes[p];
        //         p++;
        //     }
        //     ret-=(p-1);
        //     j++;
        // } 
        else {
            j++;
        }
    }

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