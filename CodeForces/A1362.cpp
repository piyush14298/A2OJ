#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a,b;
    cin>>a>>b;
    // if(__builtin_popcount(a) != __builtin_popcount(b)) {
    //     cout<<-1<<endl;
    //     return;
    // }
    if(a==b) {
        cout<<0<<endl;
    } else if(a<b) {
        int count = 0;
        while(a<b) {
            if(a*8<=b)
                a = a*8;
            else if (a*4<=b)
                a = a*4;
            else 
                a= a*2;
            count++;
            // cout<<count<<endl;
        }
        if(a==b)
            cout<<count<<endl;
        else
        {
            cout<<-1<<endl;
        }
    } else {
        int count = 0;
        while(a>b) {
            if(a%8==0 && a/8>=b)
                a = a/8;
            else if (a%4==0 && a/4>=b)
                a = a/4;
            else if(a%2 == 0)
                a= a/2;
            else {
                break;
            }
            count++;
        }
        if(a==b)
            cout<<count<<endl;
        else
        {
            cout<<-1<<endl;
        }
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