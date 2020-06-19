#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define fi first
#define se second
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
const int mod = 1e9 + 7;
int n, k, a[N], p[N], b[N];
bool vis[N];
void upd(int x, int y, int z)
{
	assert(x!=y); assert(y!=z); assert(x!=z);
	int tmp = a[z];
	a[z] = a[y];
	p[a[y]] = z; 
	a[y] = a[x]; 
	p[a[x]] = y;
	a[x] = tmp;
	p[tmp] = x;
}
void solve()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++) 
	{
		scanf("%d", a+i);
		p[a[i]] = i;
	}
	vector<vector<int> > op;
	for(int i=1; i<=n; i++)
	{
		vis[i] = 0;
		if(i!=p[i])
		{
			int x = p[i], y = i, z = a[i];
			if(z==x) continue;
            vector<int> temp = {y, z, x};
			op.pb(temp);
			upd(y, z, x);
		}
	}
	vector <pii> loop;
	for(int i=1; i<=n; i++)
	{
		if(i!=p[i] && p[i]==a[i] && !vis[p[i]])
		{
            vector<int> temp = {i, p[i]};
			loop.pb(temp);
			vis[i] = vis[p[i]] = 1;
		}
	}
	if(sz(loop)&1) 
	{
		puts("-1");
		return;
	}
	for(int i=0; i<sz(loop); i+=2)
	{
		int a = loop[i].fi, b = loop[i].se, c = loop[i+1].fi, d = loop[i+1].se;
		op.pb({b, c, d});
		upd(b, c, d);
		op.pb({a, b, c});
		upd(a, b, c);
	}
	if(sz(op)>k || !is_sorted(a+1, a+n+1)) puts("-1");
	else
	{
		cout << sz(op) << '\n';
		for(auto it : op) printf("%d %d %d\n", it[0], it[1], it[2]);
	}
}
int main()
{
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}