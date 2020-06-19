#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        } 
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }  
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        int i=0;
        while(k-- && a[i] < b[i]) {
            swap(a[i],b[i]);
            i++;
        }

        cout<<accumulate(a.begin(),a.end(),0)<<endl;

    }
    
    return 0;

}