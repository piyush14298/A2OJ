#include<bits/stdc++.h>
using namespace std;

int add(int curr, int a) {
    return (curr+a)%360;
}

int sub(int curr, int a) {
    if(curr >= a) {
        return curr-a;
    }
    return curr-a+360;
}

bool possible(vector<int>& deg, int i, int currDeg) {
    if(i==deg.size()) {
        if(currDeg == 0)
            return true;
        return false;
    }

    return possible(deg, i+1, add(currDeg,deg[i])) || possible(deg, i+1, sub(currDeg, deg[i]));
}

int main() {
    int n;
    cin>>n;
    vector<int> deg(n);
    for(int i=0;i<n;i++) {
        cin>>deg[i];
    }

    if(possible(deg,0,0))
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
    return 0;
}