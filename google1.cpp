#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    int index = 1;
    while(t--) {
        int n,b;
        cin>>n>>b;
        vector<int> prices(n);
        for(int i=0;i<n;i++) {
            cin>>prices[i];
        }

        sort(prices.begin(),prices.end());

        int ans=0;

        for(int i=0;i<n;i++) {
            if(prices[i] > b) {
                break;
            }
            b-=prices[i];
            ans++;
        }
        cout<<"Case #"<<index++<<": "<<ans<<endl;
        
    }
    return 0;
}