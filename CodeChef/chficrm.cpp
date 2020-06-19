#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int fives=0, tens=0;
    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        // int a
        cin>>coins[i];
    }
    for(int i=0;i<n;i++) {
        int a = coins[i];
        if(a==5) {
            fives++;
        } else if(a==10) {
            if(fives==0) {
                cout<<"NO"<<endl;
                return;
            }
            tens++;
            fives--;
        } else {
            if(tens) {
                tens--;
            } else if(fives>1) {
                fives-=2;
            } else {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}