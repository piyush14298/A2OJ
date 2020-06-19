#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

string add(string a, string b) {
    int carry=0;
    int i=a.size()-1, j=b.size()-1;
    string ret = "";

    while(i>=0 && j>=0) {
        int x = a[i]-'0', y = b[j]-'0';
        int z = x+y+carry;
        carry = z/10;
        z=z%10;
        ret = to_string(z) + ret;
        i--;j--;
    }
    if(i>=0) {
        if(carry) {
            int x = a[i]-'0';
            x+=carry;
            carry = x/10;
            x%=10;
            ret=to_string(x)+ret;
        }
        else {
            ret=a.substr(0,i+1)+ret;
            i=0;
        }
        i--;
    }
    if(j>=0) {
        if(carry) {
            int x = b[j]-'0';
            x+=carry;
            carry = x/10;
            x%=10;
            ret=to_string(x)+ret;
        }
        else {
            ret=b.substr(0,j+1)+ret;
            j=0;
        }
        j--;
    }
    if(carry) ret= "1"+ret;
    return ret;
}

void solve() {
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    int x=x2-x1+1,y=y2-y1+1;
    string dp[x][y];
    dp[x-1][y-1] = "1";
    for(int i=0;i<x;i++) {
        dp[i][y-1] = "1";
    } 
    for(int i=0;i<y;i++) {
        dp[x-1][i] = "1";
    }
    // cout<<x<<" "<<y<<endl;
    for(int i=x-2;i>=0;i--) {
        for(int j=y-2;j>=0;j--) {
            dp[i][j] = add(dp[i+1][j], dp[i][j+1]);
        }
    }
    // cout<<y<<endl;
    // for(int i=0;i<x;i++) {
    //     for(int j=0;j<y;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[0][0]<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
