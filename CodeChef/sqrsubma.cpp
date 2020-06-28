
/////////////////             ____ ___ _ _  _           *******************************
/////////////////            |  _ \_ _/ | || |          *******************************
/////////////////            | |_) | || | || |_         *******************************
/////////////////            |  __/| || |__   _|        *******************************
/////////////////            |_|  |___|_|  |_|          *******************************

#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<stack>
// #include<queue>
// #include<unordered_map>
// #include<set>
// #include<algorithm>
using namespace std;
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define endl "\n"

struct Point 
{ 
    int x, y; 
}; 
ll getInt() {
    ll t;
    cin>>t;
    return t;
}
vll getVector(int n) {
    vll temp(n);
    fo(i,0,n) {
        cin>>temp[i];
    }
    return temp;
}
void printVector(vector<ll> a) {
    fo(i,0,a.size()) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

int getSum(vector<vector<int> >& mat, int i, int j, int a) {
    return mat[i+a][j+a] - mat[i-1][j+a] - mat[i+a][j-1] + mat[i-1][j-1];
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> nums = getVector(n);
    vector<vector<int> > mat(n+1, vector<int>(n+1,0));
    fo(i,0,n) {
        fo(j,0,n) {
            mat[i+1][j+1] = nums[i] + nums[j];
        }
    }

    fo(i,1,n+1) {
        fo(j,1,n+1) {
            mat[i][j] = mat[i][j] + mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1];
        }
    }

    // int a=n-1, ret=0;
    // while(a>=0) {
    //     for(int i=1;i+a<=n;i++) {
    //         for(int j=1;j+a<=n;j++) {
    //             if(mat[i+a][j+a] - mat[i-1][j+a] - mat[i+a][j-1] + mat[i-1][j-1] == x) {
    //                 ret++;
    //             }
    //         }
    //     }
    //     a--;
    // }
    int ret=0;

    fo(i,1,n+1) {
        fo(j,1,n+1) {
            int sum = getSum(mat,i,j,0), a=1;
            while(sum<x && i+a<=n && j+a<=n) {
                sum = getSum(mat, i,j,a);
                a++;
            }
            // cout<<sum<<endl;
            if(sum==x) {
                ret++;
            }
        }
    }

    cout<<ret<<endl;

}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}