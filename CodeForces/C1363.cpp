#include<bits/stdc++.h>
using namespace std;



int helper(vector<vector<int>>& graph, int x, int winner, vector<bool> seen, vector<int>& dp) {
    vector<int> leaves;
    for(int i=1;i<graph.size();i++) {
        if(seen[i])
            continue;
        int s = 0;
        for(int j=1;j<graph.size();j++) {
            if(!seen[j] && graph[i][j])
                s++;
            if(s>1)
                break;
        }
        if(s==1) {
            leaves.push_back(i);
            if(i==x) {
                return winner;
            }
        }
    }
    
    for(int i:leaves) {
        int w;
        if(dp[i] != -1)
            w = dp[i]^winner;
        else {
            seen[i] = true;
            w = helper(graph, x, !winner, seen, dp);
            dp[i] = w^winner;
            seen[i] = false;
        }
        
        if(w == winner) {
            return winner;
        }
    }

    return !winner;
}

void solve() {
    int n,x;
    cin>>n>>x;
    
    vector<vector<int>> graph(n+1, vector<int>(n+1,0));
    for(int i=0;i<n-1;i++) {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    if(n==1 || n==2) {
        cout<<"Ayush"<<endl;
        return;
    }
    vector<int> dp(n+1, -1);
    vector<bool> seen(n+1,false);
    int winner = helper(graph,x,0,seen, dp);
    if(winner) {
        cout<<"Ashish"<<endl;
    } else {
        cout<<"Ayush"<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}