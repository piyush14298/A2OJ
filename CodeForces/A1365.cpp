#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define end "\n"
ll getInt() {
    ll t;
    cin>>t;
    return t;
}
vll getVector(ll n) {
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
    ll n = getInt(), m = getInt();
    vector<vll> mat(n);
    fo(i,0,n-1) {
        mat[i] = getVector(m);
    }
    set<int> rows, cols;
    fo(i,0,n-1) {
        fo(j,0,m-1) {
            if(mat[i][j]) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    auto ans = min(n-rows.size(), m-cols.size());
    
    if(ans%2==0 ) {
        cout<<"Vivek"<<endl;
    } else {
        cout<<"Ashish"<<endl;
    }
}

int main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}


    // #include<bits/stdc++.h>
     
    // #define ll long long
    // #define ld long double
     
    // #define mod 1000000007
    // #define f first
    // #define s second
    // #define pb push_back
    // #define mp make_pair
     
    // #define endl "\n"
     
    // #define mii map<int,int>
    // #define mll map<ll,ll>
    // #define pii pair<int,int>
    // #define pll pair<<ll,ll>
    // #define vii vector<int>
    // #define vll vector<ll>
     
    // #define rep(i,end) for(int i=0;i<end;i++)
    // #define repi(i,start,end) for(int i=start;i<=end;i++)
    // #define repd(i,start,end) for(int i=start;i>=end;i--)
     
    // #define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
     
    // using namespace std;
     
    // int main()
    // {
    //  fast;
    //  int t;
    //  cin>>t;
    //  while(t--)
    //  {
    //      int n,m;
    //      cin>>n>>m;
    //      int a[n][m];
    //      rep(i,n)
    //          rep(j,m)
    //              cin>>a[i][j];
    //      int count=0;
    //      vector<bool> r(n,true);
    //      vector<bool> c(m,true);
    //      rep(i,n)
    //      {
    //          rep(j,m)
    //          {
    //              if(a[i][j]==1)
    //                  r[i]=c[j]=false;
    //          }
    //      }
    //      rep(i,n)
    //      {
    //          rep(j,m)
    //          {
    //              if(a[i][j]==0 && r[i]==true && c[j]==true)
    //              {
    //                  count++;
    //                  r[i]=false;
    //                  c[j]=false;
    //              }
    //          }
    //      }
    //      //cout<<count<<endl;
    //      if(count%2==0)
    //          cout<<"Vivek"<<endl;
    //      else
    //          cout<<"Ashish"<<endl;
    //  }
    //  return 0;
    // }