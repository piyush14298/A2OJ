#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>


int main() {
    int n,m;
    cin>>n>>m;
    vector<unordered_map<int,bool>> mat(n+1);

    for(int i=0;i<m;i++) {
        int a, b;
        cin>>a>>b;
        mat[a][b] = true;
        mat[b][a] = true;
    }
    unordered_map<int,int> topic;
    vector<pair<int,int>> ret;
    for(int i=1;i<=n;i++) {
        int a;
        cin>>a;
        topic[i] = a;
        ret.push_back({a,i});
    }

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            if(mat[i][j] && topic[i] == topic[j]) {
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    sort(ret.begin(), ret.end());

    for(int i=0;i<ret.size();i++) {
        cout<<ret[i].second<<" ";
    }
    cout<<endl;
    return 0;
}