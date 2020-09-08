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

vector<vector<int> > graph;
vector<vector<vector<int> > > paths;

// void dfs(int start, int curr, vector<int> path, vector<bool> seen) {
//     paths[start][curr] = path;
//     seen[curr] = true;

//     for(auto i:graph[curr]) {
//         if(!seen[i]) {
//             path.push_back(i);
//             dfs(start,i,path,seen);
//             path.pop_back();
//         }
//     }
// }

void reach(int curr, int end, vector<int> path, vector<bool> seen, vector<int>& ret) {
    if(curr == end) {
        ret = path;
        return;
    }
    seen[curr] = true;

    for(auto i:graph[curr]) {
        if(!seen[i]) {
            path.push_back(i);
            reach(i,end,path,seen,ret);
            path.pop_back();
        }
    }
}

void solve() {
    int n = getInt();
    graph.resize(n+1);

    for(int i=1;i<n;i++) {
        int a=getInt(), b=getInt();
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // paths = vector<vector<vector<int> > >(n+1, vector<vector<int> >(n+1));

    // for(int i=1;i<=n;i++) {
    //     vector<bool> seen(n+1,false);
    //     dfs(i,i,{},seen);
    // }

    int q = getInt();

    while(q--) {
        int a,b,c;
        cin>>a>>b>>c;
        vector<bool> seen(n+1,false);
        vector<int> v;
        reach(a,b,{},seen,v);

        if(v.size() <= c) {
            cout<<b<<endl;
        } else {
            cout<<v[c-1]<<endl;
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