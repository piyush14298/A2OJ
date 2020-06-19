#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<bool> seive(10000001,false);

void fill() {
    for(ll i=2;i<=10000000;i++) {
        if(!seive[i]) {
            for(ll j=i*i;j<=10000000;j+=i) {
                seive[j] = true;
            }
        }
    }
}

vector<int> getDiv(int n) {
    vector<int> ret;
    for(int i=2;i<sqrt(n);i++) {
        if(n%i==0) {
            if(!seive[i]) {
                ret.push_back(i);
            }
            if(!seive[n/i]) {
                ret.push_back(n/i);
            }
        }
        
        if(ret.size()==2) {
            break;
        }
    }
    return ret;
}

int main() {
    int n;
    cin>>n;
    
    fill();
    vector<int> nums(n);
    int grt = -1;
    for(int i=0;i<n;i++) {
        cin>>nums[i];
        grt = max(grt,nums[i]);
    }
    // fill(grt);
    vector<int> z,o;
    for(int i=0;i<n;i++) {
        auto t = getDiv(nums[i]);
        if(t.size()<2) {
            z.push_back(-1);o.push_back(-1);
        } else {
            z.push_back(t[0]);o.push_back(t[1]);
        }
    }
    for(int i=0;i<n;i++) {
        cout<<z[i]<<" ";
    }
    
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<o[i]<<" ";
    }
    cout<<endl;
    // cout<<seive[24].size();
    return 0;
}