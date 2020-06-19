#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
void solve() {
    ull ts;
    cin>>ts;
    while(ts%2==0) {
        ts/=2;
    }
    cout<<ts/2<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}