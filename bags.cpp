#include<bits/stdc++.h>
using namespace std;

vector<int> sizes,nums;
int mask=0,sum=0;
vector<vector<int> > ret;

void getVector(int i, int currSum,int s, vector<int> curr, vector<int> indices) {
    if(currSum == sum && (int)curr.size()==s) {
        for(int j:indices) {
            // cout<<j<<" ";
            mask = mask | (1<<j);
        }
        // cout<<mask<<endl;
        // cout<<curr.size()<<" "<<s<<endl;
        // swap(curr,ret);
        ret.push_back(curr);
        return;
    }
    if(currSum > sum) {
        return;
    }

    if(i==(int)nums.size()) {
        return;
    }

    getVector(i+1,currSum,s,curr,indices);

    if(mask & (1<<i)) {
        return;
    }

    curr.push_back(nums[i]);
    indices.push_back(i);
    getVector(i+1,currSum+nums[i],s,curr,indices);
} 

int main() {

    int n;
    cin>>n;
    sizes = vector<int> (n);
    for(int i=0;i<n;i++) {
        cin>>sizes[i];
        for(int j=0;j<sizes[i];j++) {
            int a;
            cin>>a;
            sum+=a;
            nums.push_back(a);
        }
    }

    sum/=n;

    for(int i=0;i<n;i++) {
        vector<int> temp;
        getVector(0,0,sizes[i],{},{});
        // // cout<<temp.size()<<endl;
        // // for(int i:temp) {
        // //     cout<<i<<" ";
        // // }
        // // cout<<endl;
        // // cout<<mask<<endl;
        // // cout<<temp.size()<<endl;
        // ret.push_back(temp);
        sort(ret[i].begin(), ret[i].end());
    }
    sort(ret.begin(), ret.end(), [](auto a, auto b) {
        return a[0] < b[0];
    });

    for(auto v:ret) {
        for(int i:v) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}