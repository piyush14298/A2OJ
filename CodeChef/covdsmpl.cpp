#include<bits/stdc++.h>
using namespace std;

int getSum(vector<vector<int> >& mat, int i, int j, int limit) {
    int ans=0;
    for(int x=i;x<=i+limit;x++) {
        for(int y=j;y<=j+limit;y++) {
            ans+=mat[x][y];
        }
    }
    return ans;
}

void display(vector<vector<int> >& t) {
    for(int i=1;i<t.size();i++) {
        for(int j=1;j<t.size();j++) {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solve() {
    int n,p;
    cin>>n>>p;
    vector<vector<int>> mat(n+1,vector<int>(n+1,0));
    int maxInf;
    cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<n<<endl;
    cin>>maxInf;
    vector<int> rows(n+1,0), cols(n+1,0);
    int top=0;
    for(int i=1;i<=(n+1)/2;i++) {
        int r;
        if(top == maxInf) {
            r = 0;
        } else {
            cout<<1<<" "<<i+1<<" "<<1<<" "<<n<<" "<<n<<endl;
            cin>>r;
        }
        rows[i] = maxInf - r - top;
        top+=rows[i];
    }
    top=0;
    for(int i=n;i>(n+1)/2;i--) {
        int r;
        if(top == maxInf) {
            r = 0;
        } else {
            cout<<1<<" "<<1<<" "<<1<<" "<<i-1<<" "<<n<<endl;
            cin>>r;
        }
        rows[i] = maxInf - r - top;
        top+=rows[i];
    }

    top=0;
    for(int i=1;i<=(n+1)/2;i++) {
        int r;
        if(top == maxInf) {
            r = 0;
        } else {
            cout<<1<<" "<<1<<" "<<i+1<<" "<<n<<" "<<n<<endl;
            cin>>r;
        }
        cols[i] = maxInf - r - top;
        top+=cols[i];
    }
    top=0;
    for(int i=n;i>(n+1)/2;i--) {
        int r;
        if(top == maxInf) {
            r = 0;
        } else {
            cout<<1<<" "<<1<<" "<<1<<" "<<n<<" "<<i-1<<endl;
            cin>>r;
        }
        cols[i] = maxInf - r - top;
        top+=cols[i];
    }
    
    int curr=0;
    vector<vector<int> > ret(n+1, vector<int>(n+1,0));
    vector<vector<int> > dp(n+1, vector<int>(n+1,0));
    vector<int> tempR(n+1,0), tempC(n+1,0);
    for(int i=1;i<=n;i++) {
        tempR[i] = tempR[i-1] + rows[i];
    }
    for(int i=1;i<=n;i++) {
        tempC[i] = tempC[i-1] + cols[i];
    }

    // for(int i=n;i>0;i--) {
    //     for(int j=n;j>0;j--) {
    //         if(i==n || j==n) {
    //             if(i==n) {
    //                 dp[i][j] = tempC[j];
    //             } else {
    //                 dp[i][j] = tempR[i];
    //             }
    //         }

    //         else {
    //             int num;
    //             if((i-1+j-1) > (n-i+n-j)) {
    //                 cout<<1<<" "<<1<<" "<<1<<" "<<i<<" "<<j<<endl;  
    //                 cin>>num;
    //             } else {
    //                 cout<<1<<" "<<i<<" "<<j<<" "<<n<<" "<<n<<endl;
    //                 int x;
    //                 cin>>x;

    //                 num = (tempR[j]+tempC[i]-maxInf+x)/2; 
    //             }
    //             dp[i][j] = num;
    //         }
    //     }
    // }

    while(curr<n*n) {
        int i=(curr/n)+1, j=(curr%n)+1;
        if(rows[i]==0 || cols[j]==0) {
            ret[i][j]=0;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            curr++;
            continue;
        }
        int num=0;
        if(i==n || j== n) {
            if(i==n) {
                num = tempC[j];
            } else {
                num = tempR[i];
            }
        }
        else {
            if((i-1+j-1) > (n-i+n-j)) {
                cout<<1<<" "<<1<<" "<<1<<" "<<i<<" "<<j<<endl;  
                cin>>num;
            } else {
                cout<<1<<" "<<i+1<<" "<<j+1<<" "<<n<<" "<<n<<endl;
                int x;
                cin>>x;

                num = (tempR[i]+tempC[j]-maxInf+x); 
            }
        }
        dp[i][j] = num;

        int currVal = dp[i][j] - dp[i-1][j] - dp[i][j-1] + dp[i-1][j-1];
        rows[i]-=currVal;
        cols[j]-=currVal;
        ret[i][j] = currVal;
        // dp[i][j]
        curr++;
    }
    
    cout<<2<<endl;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
        int x;
        cin>>x;
        if(x==-1) {
            return 0;
        }
    }
    return 0;
}