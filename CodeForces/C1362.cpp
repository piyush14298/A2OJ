#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull getDigits(ull a) {
    ull ret = 0;
    while(a) {
        ret++;
        a= a>>1;
    }
    return ret-1;
}

void solve() {
    ull n;
    cin>>n;
    ull d = getDigits(n);
    ull ans = n;
    while(d>=1) {
        ans += n/(ull)pow(2,d);
        d--;
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