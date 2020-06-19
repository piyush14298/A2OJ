#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> nums(n), dp(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        dp[i] = nums[i]?-1:1;
    }
    int i=0, tempSum=0, sum=-1;
    while(i<n) {
        tempSum+=dp[i];
        sum=max(sum,tempSum);
        if(tempSum<0) {
            tempSum=0;
        }
        i++;
    }
    int ret = accumulate(nums.begin(),nums.end(),0);
    ret+=sum;
    cout<<ret<<endl;
    return 0;
}