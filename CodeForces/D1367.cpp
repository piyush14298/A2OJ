#include<bits/stdc++.h>
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

void solve() {
    int n;
    string s;
    cin>>s;
    sort(s.begin(), s.end(), greater<char>());
    cin>>n;
    vi nums(n);
    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        nums[i] = a;
    }
    vector<pair<int, char> > placed;
    int currI=0;
    vector<char> f(n);
    vector<bool> filled(n,false);
    while(placed.size() < n) {
        for(int i=0;i<n;i++) {
            if(filled[i]) continue;
            int sum=0;
            for(auto j:placed) {
                if(j.second > s[currI]) {
                    sum+=abs(i - j.first);
                }
            }
            if(sum == nums[i]) {
                placed.push_back({i,s[currI]});
                f[i] = s[currI];
                filled[i] = true;
            }
        }
        currI++;
    }

    // for(int i=0;i<placed.size();i++) {
    //     cout<<placed[i].first<<" "<<placed[i].second<<endl;
    // }

    string ret="";
    for(char c:f) {
        ret+=c;
    }
    cout<<ret<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}