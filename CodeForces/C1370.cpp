// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
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
vector<bool> dp;
void callseive(int n) {
    dp.resize(n+1,false);

    for(int i=2;i<=n;i++) {
        if(dp[i]) continue;

        for(int j=i*i;j<=n;j+=i) {
            dp[j] = true;
        }
    }
}

bool isPrime(int n) {
    for(int i=3;i*i<=n;i++) {
        if(n%i==0)
        return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    if(n==1) {
        cout<<"FastestFinger"<<endl;
        return;
    } else if(n==2) {
        cout<<"Ashishgup"<<endl;
        return;
    }

    if(n%2==1) {
        cout<<"Ashishgup"<<endl;
        return;
    }

    if(__builtin_popcount(n)==1) {
        cout<<"FastestFinger"<<endl;
        return;
    }  
    
    int twos=0;
    while(n && n%2==0) {
        n/=2;
        twos++;
    }
    if(twos > 1) {
        cout<<"Ashishgup"<<endl;
        return;
    }

    if(isPrime(n)) {
        cout<<"FastestFinger"<<endl;
        return;
    } else {
        cout<<"Ashishgup"<<endl;
        return;
    }
    

}

int32_t main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}