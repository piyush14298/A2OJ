#include<bits/stdc++.h>
using namespace std;

void f() {
    int n;
    cin>>n;
    vector<int> dist(n);
    for(int i=0;i<n;i++) {
        cin>>dist[i];
    }

    int sm=9,gr=0;
    int t=1;
    for(int i=1;i<n;i++) {
        if(dist[i]-dist[i-1] > 2) {
            sm = min(sm,t);
            gr = max(gr,t);
            t = 1;
            if(i==n-1) {
                sm = min(sm,t);
                gr = max(gr,t);
            }
        } else {
            t++;
            if(i==n-1) {
                sm = min(sm,t);
                gr = max(gr,t);
            }
        }
    }

    cout<<sm<<" "<<gr<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        f();
    }

    return 0;
}