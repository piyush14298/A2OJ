#include<bits/stdc++.h>
using namespace std;





int main() 
{ 
	int n;
    cin>>n;
    vector<vector<int> > edges(n, vector<int> (n));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>edges[i][j];
        }
    }

	for(int remove=0;remove<n;remove++) {
        vector<bool> seen(n,false);
        int reached = 0;

        queue<int> q;
        q.push((remove+1)%n);

        while(!q.empty()) {
            int t = q.front();q.pop();
            seen[t] = true;
            reached++;
            for(int j=0;j<n;j++) {
                if(j==remove) continue;
                if(edges[t][j] && !seen[j]) {
                    q.push(j);
                    seen[j] = true;
                }
            }
        }

        if(reached < n-1) {
            cout<<remove<<" ";
        }
    }
} 
