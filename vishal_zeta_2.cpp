#include<bits/stdc++.h>
using namespace std;

vector<vector<double>> adj;
const int INF = 1000000000;

struct Edge {
    double w = INF;
    int to = -1;
};

int n;

void prim() {
    double total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        if (min_e[v].w == INF) {
            // cout << "No MST!" << endl;
            exit(0);
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        // if (min_e[v].to != -1)
            // cout << v << " " << min_e[v].to << endl;

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }
    cout<<fixed<<showpoint;
    cout << setprecision(6) << total_weight << endl;
}

int manDist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

double dist(pair<int,int> a, pair<int,int> b) {
    return sqrt(pow((double)abs(a.first-b.first), 2) + pow((double)abs(a.second-b.second), 2));
}

void solve() {
    cin>>n;
    vector<pair<int,int>> points(n);

    for(int i=0;i<n;i++) {
        int a,b;
        cin>>a>>b;
        points[i] = make_pair(a,b);
    }

    adj.resize(n);

    for(int i=0;i<n;i++) {
        adj[i].resize(n);
        for(int j=0;j<n;j++) {
            if(i==j) {
                adj[i][j] = 0;
            } else if(manDist(points[i], points[j]) == 1) {
                adj[i][j] = 0;
            } else {
                adj[i][j] = dist(points[i], points[j]);
                // cout<<adj[i][j]<<" ";
            }
            
        }
    }

    prim();
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}