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
#define endl "\n"

vector<int> getVector(int n) {
    vector<int> ret(n);
    for(int i=0;i<n;i++) {
        cin>>ret[i];
    }
    return ret;
}

int getInt() {
    int n;
    cin>>n;
    return n;
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

int x; 
unordered_map<int, unordered_map<int,bool> > corner;
int present;
  
// Sets maxCount as maximum distance from node. 
void dfsUtil(int node, int count, bool visited[], 
                   int& maxCount, vector<vector<int> >& adj) 
{ 
    visited[node] = true; 
    count++; 
    for (auto i = adj[node].begin(); i != adj[node].end(); ++i) { 
        if (!visited[*i]) { 
            if (count > maxCount) { 
                maxCount = count; 
                x = *i; 
                corner[present].clear();
                corner[present][x] = true;
            } else if(count==maxCount) {
                corner[present][*i]=true;
            }
            dfsUtil(*i, count, visited, maxCount, adj); 
        } 
    } 
} 
  
// The function to do DFS traversal. It uses recursive 
// dfsUtil() 
void dfs(int node, int n, vector<vector<int> >& adj, int& maxCount) 
{ 
    bool visited[n + 1]; 
    int count = 0; 
  
    // Mark all the vertices as not visited 
    for (int i = 1; i <= n; ++i) 
        visited[i] = false; 
  
    // Increment count by 1 for visited node 
    dfsUtil(node, count , visited, maxCount, adj); 
} 
  
// Returns diameter of binary tree represented 
// as adjacency list. 
int diameter(vector<vector<int> >& adj, int n) 
{ 
    int maxCount = INT_MIN; 
  
    /* DFS from a random node and then see 
    farthest node X from it*/
    present=0;
    dfs(1, n, adj, maxCount); 
  
    /* DFS from X and check the farthest node 
    from it */
    present++;
    dfs(x, n, adj, maxCount); 
  
    return maxCount; 
} 


void solve() {
    int n;
    cin>>n;
    if(n==1) {
        cout<<1<<endl;
        return;
    }
    vector<vector<int> > graph(n+1);
    for(int i=0;i<n-1;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int d = diameter(graph, n);

    for(int i=1;i<=n;i++) {
        if(corner[0][i] || corner[1][i]) {
            cout<<d+1<<endl;
        } else {
            cout<<d<<endl;
        }
    }
}

int32_t main() {
    GO_BABY_GO;
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}