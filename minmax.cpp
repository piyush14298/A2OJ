#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

pair<int,int> findMinMax(vector<int>& nums, int low, int high) {
    if(high-low == 1) {
        return {nums[low], nums[low]};
    }

    int mid = low + (high-low)/2;
    auto left = findMinMax(nums,low,mid);
    auto right = findMinMax(nums, mid, high);

    int minimum = min(left.first, right.first);
    int maximum = max(left.second, right.second);

    return {minimum, maximum};
}

int main() {
    cout<<"How many elements are there in the array? ";
    int n;
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: \n";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }

    auto i = findMinMax(nums,0,n);

    cout<<"Maximum element : "<<i.second<<"\nMinimum element : "<<i.first<<endl;

    return 0;
}
