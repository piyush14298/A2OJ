#include<bits/stdc++.h>
using namespace std;


int BalancedNode(int n, int root, string pos[], int val[]) {
    int leftSum=0, rightSum=0, ret=0;

    for(int i=0;i<n;i++) {
        if(pos[i][0] == 'L') leftSum+=val[i];
        else rightSum+=val[i];
    }

    if(leftSum%2 == rightSum%2) ret+=root;

    for(int i=0;i<n;i++) {
        leftSum=0;rightSum=0;
        string comp = pos[i];

        for(int j=0;j<n;j++) {
            if(i==j || pos[j].size() <= comp.size()) {
                int l = comp.size();

                if(pos[j].substr(0,l) == comp) {
                    if(pos[j][l] == 'L') leftSum+=val[j];
                    else rightSum+=val[j];
                }
            }
        }

        if(leftSum%2 == rightSum%2) {
            ret+=val[i];
            cout<<val[i]<<endl;
        }
    }

    return ret;
}

int main() {
    int n;
    cin>>n;
    int val[n];
    string pos[n];

    int root;
    cin>>root;

    for(int i=0;i<n-1;i++) {
        cin>>pos[i];
        cin>>val[i];
    }

    cout<<BalancedNode(n, root, pos, val)<<endl;

    return 0;
}