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

int allZero(string s, int i, int j) {
    for(int x=j;x>=i;x--) {
        if(s[x]=='1') {
            return x;
        }
    }
    return -1;
}

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    // int last = -1;
    // for(int i=0;i<k;i++) {
    //     s = '0'+s;
    // }
    // for(int i=0;i<k;i++) {
    //     s = s + '0';
    // }

    vector<bool> check(s.size(), false);

    int i=0;
    while(i<s.size()) {
        if(s[i] == '1') {
            check[i]= true;
            for(int j=1;j<=k && i+j<s.size();j++) {
                check[i+j] = true;
            }
            i+=k;
        }
        i++;
    }

    i=n-1;
    while(i>=0) {
        if(s[i] == '1') {
            check[i]= true;
            for(int j=1;j<=k && (i-j)>=0;j++) {
                check[i-j] = true;
            }
            i-=k;
        }
        i--;
    }

    int count = 0, ret = 0;
    for (i = 0; i < s.size(); i++) {
        if (!check[i]) {
            count++;
        }
        else {
            if (count % (k+1) == 0)	
                ret += (count / (k+1));
            else 
                ret += (count / (k+1) + 1);
            count = 0;
        }
    }
    if (count % (k+1) == 0)	
        ret += (count / (k+1));
    else 
        ret += (count / (k+1) + 1);
    cout << ret << endl;
}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}