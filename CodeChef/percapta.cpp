// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
using namespace std;
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define endl "\n"

struct point 
{ 
    int x, y; 
}; 
ll getInt() {
    ll t;
    cin>>t;
    return t;
}
vll getVector(int n) {
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

vector<int> canReach(unordered_map<int, bool> p, unordered_map<int, unordered_map<int, bool> > & connected) {
    vector<int> ret;
    unordered_map<int, bool> seen;
    set<int> s;
    for(auto i:p) {
        s.insert(i.first);
    }
    for(auto i:p) {
        int c = i.first;
        if(seen[c]) continue;
        vector<int> temp;
        queue<int> q;
        q.push(c);
        while(!q.empty()) {
            int f = q.front();q.pop();
            temp.emplace_back(f);
            seen[f] = true;
            s.erase(f);
            // for(auto j : connected[f]) {
            //     if(p[j] && !seen[j]) {
            //         q.push(j);
            //     }
            // }
            for(auto i:s) {
                if(connected[f][i]) {
                    q.push(i);
                }
            }
        }
        if(ret.size()< temp.size()) {
            swap(ret, temp);
        }
    }
    return ret;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<double> income(n), population(n);
    for(int i=0;i<n;i++) {
        cin>>income[i];
    }
    for(int i=0;i<n;i++) {
        cin>>population[i];
    }
    unordered_map<int, unordered_map<int, bool> > connected;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        connected[a][b]= true;
        connected[b][a] = true;
    }
    double p=0;
    unordered_map<int, bool> c;
    for(int i=0;i<n;i++) {
        if(income[i]/population[i] > p) {
            p = income[i]/population[i];
            c.clear();
            c[i+1] = true;
        } else if(income[i]/population[i] == p) {
            c[i+1] = true;
        }
    }
    
    auto ret = canReach(c, connected);

    cout<<ret.size()<<endl;
    for(int i:ret) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}