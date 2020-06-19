#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int f() {
    int n,m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    map<pair<int,int>, int> h;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(a>b) {
            swap(a,b);
        }
        if(nums[a] > nums[b]) {
            swap(nums[a], nums[b]);
        }
        h[make_pair(a,b)]++;
    }
    int change = true;
    while(change) {
        change = false;
        for(auto i:h) {
            int a = i.first.first, b=i.first.second;
            if(nums[a] > nums[b]) {
                swap(nums[a], nums[b]);
                change = true;
            }
        }
        
    }
    
    int res = 0;
    for(int i=0;i<n;i++) {
        while(nums[i]-1 != i) {
            if(!h[make_pair(i,nums[i]-1)]) {
                res++;
            }
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    return res;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cout<<f()<<endl;
    }

    return 0;
}