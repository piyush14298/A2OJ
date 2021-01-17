#include<bits/stdc++.h>
using namespace std;
const int maxN = 10000;
int n;

int tree[2*maxN];

int max(int a, int b) {
    return a>b?a:b;
}

void build(vector<int>& arr) {
    for(int i=0;i<n;i++) {
        tree[n+i] = arr[i];
    }

    for(int i=n-1;i>0;i--) {
        tree[i] = max(tree[i<<1] , tree[i<<1 | 1]);
    }
}

void updateTreeNode(int p, int value) { 
	tree[p+n] = value; 
	p = p+n; 
	
	for (int i=p; i > 1; i >>= 1) 
		tree[i>>1] = max(tree[i] , tree[i^1]); 
} 

int query(int l, int r) {
    int ret=0;
    for(l+=n, r+=n; l<r; l>>=1,r>>=1) {
        if(l&1) {
            ret=max(ret,tree[l++]);
        }
        if(r&1) {
            ret=max(tree[--r],ret);
        }
    }
    return ret;
}

int main() {
    n = 5;
    vector<int> arr = {1,2,3,4,5};
    build(arr);

    int q;
    cin>>q;
    while(q--) {
        int t,l,r;
        cin>>t>>l>>r;

        if(t==0) cout<<query(l,r)<<endl;
        else updateTreeNode(l,r);
    }
}