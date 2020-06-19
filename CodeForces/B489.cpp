#include<bits/stdc++.h>
using namespace std;



int main() {
    int n,m;
    cin>>n;
    vector<int> boy(n);
    for(int i=0;i<n;i++) {
        cin>>boy[i];
    }
    cin>>m;
    vector<int> girl(m);
    for(int i=0;i<m;i++) {
        cin>>girl[i];
    }
    sort(boy.begin(), boy.end());
    sort(girl.begin(), girl.end());
    int i=0,j=0;
    int ret=0;
    while(i<n&&j<m) {
        if(abs(boy[i]-girl[j])<=1) {
            ret++;
            i++;j++;
        } else if(boy[i]<girl[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout<<ret<<endl;
    return 0;
}
