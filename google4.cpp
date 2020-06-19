#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    return a<b?a:b;
}

void manage(vector<string>& strs, int start, int end) {
    // vector<string> ret;
    // for(int i=start;i<start+end;i++) {
    //     strs.erase(strs.begin()+start);
    // }
    // return ret;
    strs.erase(strs.begin()+start,strs.begin()+start+end);
}

int calculateScore(string a, string b) {
    int ans = 0;
    for(int i=0;i<min(a.size(),b.size()); i++) {
        if(a[i] != b[i]) {
            break;
        }
        ans++;
    }
    return ans;
}

int main() {
    int t;
    cin>>t;
    int index = 1;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<string> strs(n);
        for(int i=0;i<n;i++) {
            cin>>strs[i];
        }
        sort(strs.begin(),strs.end());
        int ans = 0;

        while(!strs.empty()) {
            int i=0, j=k-1;
            int score=INT_MIN, index;
            while(j<strs.size()) {
                int tempScore = calculateScore(strs[i],strs[j]);
                if(tempScore > score) {
                    score = tempScore;
                    index = i;
                }
                i++;j++;
            }
            // cout<<score<<endl;
            ans+=score;
            manage(strs,index,k);
            // cout<<strs.size()<<endl;
        }

        cout<<"Case #"<<index++<<": "<<ans<<endl;
    }


    return 0;
}