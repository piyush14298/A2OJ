#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ull unsigned long long


ull getDist(int i, int j, int mid, vector<vector<ull> >& h) {
    if(i==mid && j==mid) return 0;
    if(h[i][j]) {
        return h[i][j];
    }
    if(i!=mid && j!=mid) {
        h[i][j] = 1+getDist(i+1,j+1,mid, h);
        return h[i][j];
    } else if(i==mid) {
        h[i][j] = abs(mid-j);
        return (ull)abs(mid-j);
    } else {
        h[i][j] = abs(mid-i);
        return (ull)abs(mid-i);
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        
        // h.resize(n);
        // for(auto i:h) {
        //     i.resize(n);
        // }
        if(n==1) cout<<0<<endl;
        else {
            ull mid=(n-1)/2;
            ull res = 0;
            for(ull i=1;i<=mid;i++) {
                res+=8*i*i;
            }
            cout<<res<<endl;
        }   
    }
    
    return 0;

}