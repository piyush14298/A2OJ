#include<bits/stdc++.h>
using namespace std;

struct node {
    int l;
    int r;
};

struct comp {
    bool operator()(node const& a, node const& b) {
        if(a.r-a.l == b.r-b.l) return a.l>b.l;
        return a.r-a.l < b.r-b.l;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> ret(n,0);
        priority_queue<node, vector<node>, comp> q;
        node no = {0,n-1};
        q.push(no);
        for(int i=1;i<=n;i++) {
            auto temp = q.top();
            q.pop();
            if((temp.r- temp.l +1) %2 == 0) {
                ret[(temp.r + temp.l - 1)/2]=i;
                int t = (temp.r + temp.l - 1)/2;
                if(t!=temp.l) {
                    no.l =temp.l;
                    no.r =t-1;
                    q.push(no);
                }
                if(t!=temp.r) {
                    // no = {t+1,temp.r};
                    no.l =t+1;
                    no.r =temp.r;
                    q.push(no);
                }
            } else {
                ret[(temp.r + temp.l)/2] = i;
                int t = (temp.r + temp.l)/2;
                if(t!=temp.l) {
                    no.l =temp.l;
                    no.r =t-1;
                    // no = {temp.l,t-1};
                    q.push(no);
                }
                if(t!=temp.r) {
                    // no = {t+1,temp.r};
                    no.l =t+1;
                    no.r =temp.r;
                    q.push(no);
                }
            }

        }

        for(auto i:ret) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}