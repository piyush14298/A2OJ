#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int max(int a, int b) {
    return a>b?a:b;
}

void solve() {
    int n;
    cin>>n;
    set<int> nums;
    unordered_map<int,bool> present;
    // int upper = 0;
    int digits=0;
    for(int i=0;i<n;i++) {
        int m;
        cin>>m;
        nums.insert(m);
        present[m] = true;
        // upper^=m;
        digits = max(digits,log2(m));
    }
    // if(upper==0) {
    //     cout<<-1<<endl;
    //     return;
    // }
    digits++;
    int upper = pow(2,digits)-1;
    int i, ans = 0;
    for( i=upper;i>0;i--) {
        set<int> temp;
        for(int j:nums) {
            if(present[i^j]) {
                temp.insert(i^j);
            } else {
                break;
            }
        }
        if(temp == nums) {
            ans = i;
        }
    }
    if(ans == 0) {
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}