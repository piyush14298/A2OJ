#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> coins(n);
    for(int i=0;i<n;i++) {
        cin>>coins[i];
    }
    ull ret = 0;
    for(int i=0;i<n;i++) {
        ret+=coins[i] - (coins[i]/k)*k;
        coins[i] = (coins[i]/k)*k;
    }
    for(int i=n-1;i>=0;i--) {
        if(((coins[i]/k)+1)*k - coins[i] > ret) {
            break;
        }
        ret-=((coins[i]/k)+1)*k - coins[i];
    }

    cout<<ret<<endl;
}

int main() {
    int t;
    cin>>t;

    while(t--) solve();
    return 0;
}