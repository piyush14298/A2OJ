// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<cmath>
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

struct Point 
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

// pair<int,int> getOp(int n) {
//     vector<pair<int,int> > dp(n+1);
//     dp[1] = {1,1};
//     dp[2] = {1,2};

//     for(int i=3;i<=n;i++) {
//         auto t = getFact(i);
//         if(t.first+t.second < dp[i-1].first+dp[i-1].second+1) {
//             dp[i] = t;
//         } else {
//             if(dp[i-1].first > dp[i-1].second) {
//                 dp[i] = {dp[i-1].first+1, dp[i-1].second};
//             }
//         }
//     }
// }
// #define MAX 1e16+1
// vector<bool> dp;

// void call(int n) {
//     dp.resize(n+1, false);
//     for(int i=2;i<=n;i++) {
//         if(dp[i]) continue;
//         for(int j=i*i;j<=n;j+=i) {
//             dp[j] = true;
//         }
//     }
// }

bool isPrime(int n) {
    for(int i=2;i<=sqrt(n);i++) {
        if(n%2==0) return false;
    }
    return true;
}

vector<int> getFact(int n) {
    // cout<<"here";
    // call(n);
    vector<int> ret;
    int f = 2, i=0;
    while(n>1) {
        if(n%f==0) {
            ret.push_back(f);
            n/=f;
            // i = (i+1)%10;
        } else {
            f++;
            while(!isPrime(f)) f++;
        }
    }
    return ret;
}

void solve() {
    // cout<<"here1";
    int n;
    cin>>n;
    
    auto p = getFact(n);
    unordered_map<int,char> c = {{0,'c'}, {1,'o'}, {2,'d'},{ 3,'e'}, {4,'f'}, {5,'o'}, {6,'r'}, 
                                    {7,'c'},{8,'e'}, {9,'s'}};

    string s = "";
    while(p.size()<10) {
        p.push_back(1);
    }
    priority_queue<int, vector<int>, greater<int> > pq(p.begin(), p.end());
    while(pq.size()>10) {
        int a=pq.top();pq.pop();
        int b = pq.top();pq.pop();
        pq.push(a*b);
    }
    // cout<<"here";
    vector<int> ne;
    while(!pq.empty()) {
        ne.push_back(pq.top());pq.pop();
    }

    for(int i=0;i<10;i++) {
        while(ne[i]--) {
            s+=c[i];
        }
    }
    cout<<s<<endl;
}

int32_t main() {
    // cout<<"hi";
    // GO_BABY_GO;
    // ll t = 1;
    // while(t--) {
    //     solve();
    // }
    solve();
    return 0;
}