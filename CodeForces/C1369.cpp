// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define endl "\n"

struct Point 
{ 
    int x, y; 
}; 
ll getInt() {
    ll t;
    cin>>t;
    return t;
}
vll getVector(int n) {
    vll temp(n);
    fo(i,0,n-1) {
        cin>>temp[i];
    }
    return temp;
}
void printVector(vector<ll> a) {
    fo(i,0,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

int getScore(unordered_map<int, vector<int> >& allot) {
    int ret=0;

    for(auto i: allot) {
        auto v = i.second;
        ret+=*max_element(v.begin(), v.end());
        ret+=*min_element(v.begin(), v.end());
    }
    return ret;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    fo(i,0,n) {
        cin>>nums[i];
    }
    sort(nums.begin(), nums.end());
    vector<int> sizes(k);
    fo(i,0,k) {
        cin>>sizes[i];
    }
    sort(sizes.begin(), sizes.end());
    int x=0;
    while(sizes[x]==1)x++;
    sort(sizes.begin()+x, sizes.end(),greater<int>());
    int ret=0;
    int maxIndex=n-1, minIndex=0;
    int index=0;
    while(index < k) {
        if(sizes[index] == 1) {
            ret+=(2*nums[maxIndex]);
            maxIndex--;
        } else if (sizes[index] == 2)  {
            ret+=nums[maxIndex]+nums[maxIndex-1];
            maxIndex-=2; 
        } else {
            ret+=nums[maxIndex]+nums[minIndex];
            maxIndex--;
            minIndex+=(sizes[index]-1);
        }
        index++;
    }
    cout<<ret<<endl;

    // unordered_map<int, vector<int> > allot;
    // int i=n-1;
    // while(i>=0) {
    //     for(int j=0;j<k;j++) {
    //         if(allot[j].size()<sizes[j]) {
    //             allot[j].push_back(nums[i]);
    //             i--;
    //         }
    //     }
    // }

    // cout<<getScore(allot)<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}