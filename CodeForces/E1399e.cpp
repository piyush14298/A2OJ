
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

struct Node 
{ 
    int node;
    int weight; 
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

vector<int> cnt, w;
vector<vector<pair<int,int > > > graph;

void dfs(int v, int p=-1) {
    if(graph[v].size()==1) {
        cnt[p] = 1;
    }

    for(auto i: graph[v]) {
        if(i.second == p) {
            continue;
        }
        dfs(i.first,i.second);
        if(p!=-1) {
            cnt[p]+=cnt[i.second];
        }
    }
}

long long getdiff(int id) {
    return w[id] * 1ll * cnt[id] - (w[id]/2) * 1ll * cnt[id];
}

void solve() {
    int n;
    long long s;
    cin>>n>>s;
    w = cnt = vector<int>(n-1);
    graph = vector<vector<pair<int,int> > >(n);

    for(int i=0;i<n-1;i++) {
        int u,v,wei;
        cin>>u>>v>>wei;
        w[i] = wei;
        --u;--v;
        graph[u].push_back({v,i});
        graph[v].push_back({u,i});
    }
    dfs(0);
    set<pair<long long, int>> st;
    long long cur = 0;
    for (int i = 0; i < n - 1; ++i) {
        st.insert({getdiff(i), i});
        cur += w[i] * 1ll * cnt[i];
    }
    // cerr << cur << endl;
    int ans = 0;
    while (cur > s) {
        int id = st.rbegin()->second;
        st.erase(prev(st.end()));
        cur -= getdiff(id);
        w[id] /= 2;
        st.insert({getdiff(id), id});
        ++ans;
    }
    cout << ans << endl;
    // int n;
	// 	long long s;
	// 	cin >> n >> s;
	// 	w = cnt = vector<int>(n - 1);
	// 	graph = vector<vector<pair<int, int>>>(n);
	// 	for (int i = 0; i < n - 1; ++i) {
	// 		int x, y;
	// 		cin >> x >> y >> w[i];
	// 		--x, --y;
	// 		graph[x].push_back({y, i});
	// 		graph[y].push_back({x, i});
	// 	}
	// 	dfs(0);
	// 	set<pair<long long, int>> st;
	// 	long long cur = 0;
	// 	for (int i = 0; i < n - 1; ++i) {
	// 		st.insert({getdiff(i), i});
	// 		cur += w[i] * 1ll * cnt[i];
	// 	}
	// 	// cerr << cur << endl;
	// 	int ans = 0;
	// 	while (cur > s) {
	// 		int id = st.rbegin()->second;
	// 		st.erase(prev(st.end()));
	// 		cur -= getdiff(id);
	// 		w[id] /= 2;
	// 		st.insert({getdiff(id), id});
	// 		++ans;
	// 	}
	// 	cout << ans << endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}