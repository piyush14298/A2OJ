#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define end "\n"
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
vll getVector(int n) {
    vll temp(n);
    fo(i,0,n-1) {
        cin>>temp[i];
    }
    return temp;
}
void printVector(vector<ll> a) {
    fo(i,0,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<end;
}
ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}



void solve() {
    int  n,m;
    cin>>n>>m;
    vector<vector<int> > mat(n+1, vector<int>(m+1));

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>mat[i][j];
        }
    }
    int ans=0;
    int d1i=1,d1j=1,d2i=n,d2j=m;
    int count=n+m-1;
    while(count>1) {
        int ones=0, zeros=0;
        int a=d1i,b=d1j;
        if(d1j==m) {
            d1i++;
        } else {
            d1j++;
        }
        while(a<=n && b>0) {
            ones+=mat[a][b]==1;
            zeros+=mat[a][b]==0;
            a++;b--;
        }
        count--;
        a=d2i,b=d2j;
        if(d2i==1) {
            d2j--;
        } else {
            d2i--;
        }
        while(a<=n && b>0) {
            ones+=mat[a][b]==1;
            zeros+=mat[a][b]==0;
            a++;b--;
        }
        count--;
        ans+=min(ones,zeros);
    }
    cout<<ans<<endl;
}

int main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}