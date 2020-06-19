#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define l unsigned long long

l getComb(l i) {
    if(i==0) return 0;

    return i%2==0?(i/2)*(i+1):i*((i+1)/2);
}

int main() {
    int n,k;
    cin>>n>>k;
    string st;
    cin>>st;
    unordered_map<char,int> h;
    while(k--) {
        char c;
        cin>>c;
        h[c]=1;
    }
    vector<int> sizes;
    int t=0;
    for(int i=0;i<n;i++) {
        if(!h[st[i]]) {
            if(t) sizes.push_back(t);
            t=0;
        } else {
            t++;
        }
    }
    if(t) sizes.push_back(t);
    l ret=0;

    for(int i:sizes) {
        // cout<<i<<" ";
        ret+=getComb(i);
    }

    cout<<ret<<endl;

    return 0;
}