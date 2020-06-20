#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define lld long long double
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define f(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(ll i=a;i>=b;i--)
#define repd(i,n) fd(i,n,0)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define printv(v)         \
    for (auto x : v)      \
        cout << x << ' '; \
    br;
#define br cout << "\n";
#define testc() \
    ll t;       \
    cin >> t;   \
    while (t--)
#define maxd1 998244353
#define basP 233
#define eps 1e-8 
#define INF INT_MAX
#define INFL LLONG_MAX
#define puts(n) cout << n;
#define vl2d vector<vector<ll>>
#define vi2d vector<vector<int>>
#define mset(m, v) memset(m, v, sizeof(m))
#define setbits(x) __builtin_popcount(x)
#define primeDEN 727999983
int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];
	int result;
	int i;
	rep(i,n)
		cin>>a[i];
	int b=a[k-1];
	if(b>0)
	{
		for(i=k;i<n && a[i]==b;i++);
		result = i-1;
	}
	else{
		for(i=k;i>=0 && a[i]<=0;i--);
		result = i+1;
	}
	cout<<result;
	return 0;
}