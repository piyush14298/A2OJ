#include<bits/stdc++.h>
using namespace std;

int helper(int i, int j, vector<int>& boys, vector<int>& girls) {
    if(i == boys.size()) {
        return 0;
    }
    if(j == girls.size()) {
        return 1000000;
    }

    return min(abs(boys[i]-girls[j])+helper(i+1,j+1,boys,girls), helper(i,j+1,boys,girls));
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> boys(n), girls(m);
    for(int i=0;i<n;i++) {
        cin>>boys[i];
    }
    for(int i=0;i<m;i++) {
        cin>>girls[i];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    cout<<helper(0,0,boys,girls);
    return 0;
}