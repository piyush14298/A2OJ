#include<bits/stdc++.h>
using namespace std;

void solve() {
    int a,b;
    cin>>a>>b;
    if(a>b) 
    swap(a,b);
    if(2*a >= b) {
        cout<<4*a*a<<endl;
    } else {
        cout<<b*b<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}