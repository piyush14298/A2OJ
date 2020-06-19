#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define endl "\n"
// #define int int64_t
struct Point 
{ 
    int x, y; 
}; 
ll getInt() {
    ll t;
    cin>>t;
    return t;
}
vi getVector(int n) {
    vi temp(n);
    fo(i,0,n-1) {
        cin>>temp[i];
    }
    return temp;
}
void printVector(vector<ll> a) {
    fo(i,0,a.size()-1) {
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

// int helper(vector<int>& v, int i, int j, int sum, int x) {
//     if(i==j) {
//         if(v[i]%x==0) {
//             return -1;
//         }
//         return 1;
//     }
//     if(sum%x!=0) {
//         return j-i+1;
//     }
//     return max(helper(v, i+1,j,sum-v[i],x), helper(v,i,j-1,sum-v[j],x));
// }

void solve() {
    int n,x;
    cin>>n>>x;
    auto v = getVector(n);
    int sum = accumulate(v.begin(), v.end(),0);
    if(sum%x!=0) {
        cout<<n<<endl;
        return;
    }
    int grt = -1;
    for(int i=0;i<n;i++) {
        if(v[i]%x!=0) {
            grt = max({grt, i+1, n-i-1});
            break;
        }
    }
    for(int i=n-1;i>=0;i--) {
        if(v[i]%x!=0) {
            grt = max({grt, i, n-i});
            break;
        }
    }
    cout<<grt<<endl;
}

int main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}