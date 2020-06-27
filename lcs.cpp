#include<bits/stdc++.h>
using namespace std;

int main() {
    cout<<"Enter the strings:\n";
    string s1, s2;
    cin>>s1>>s2;
    int l1 = s1.size(), l2 = s2.size();
    vector<vector<pair<char,int> > > dp(l1+1, vector<pair<char,int> >(l2+1,{'a',0}));

    for(int i=1;i<=l1;i++) {
        for(int j=1;j<=l2;j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = {'D', dp[i-1][j-1].second + 1};
            } else {
                if(dp[i-1][j].second > dp[i][j-1].second) {
                    dp[i][j] = {'U', dp[i-1][j].second};
                } else {
                    dp[i][j] = {'L', dp[i][j-1].second};
                }
            }
        }
    }
    cout<<"LCS length is : "<<dp[l1][l2].second<<endl;
    string lcs="";

    int i=l1, j=l2;
    while(i>0 && j>0) {
        switch (dp[i][j].first)
        {
        case 'D':
            lcs+=s1[i-1];
            i--;j--;
            break;
        
        case 'L':
            j--;
            break;

        case 'U':
            i--;
            break;
        
        default:
            break;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout<<"LCS is : "<<lcs<<endl;
    return 0;
}