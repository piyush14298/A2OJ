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
#define int long long
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define MOD 1000000007

vector<int> getVector(int n) {
    vector<int> ret(n);
    for(int i=0;i<n;i++) {
        cin>>ret[i];
    }
    return ret;
}

void printVector(vector<int>& nums) {
    for(int i:nums) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int power(int a, int n) {
    if(n==0) {
        return 1;
    }
    int base=a, ret=a, currP=1, addP=1;

    while(currP < n) {
        if(currP + addP > n) {
            addP=1;
            base=a;
        }
        ret = ret%MOD * base%MOD;
        ret%=MOD;
        base = base%MOD * base%MOD;
        base%=MOD;
        currP+=addP;
        addP+=addP;
    }
    return ret%MOD;
}

int gcd(int a, int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}

int getInt() {
    int n;
    cin>>n;
    return n;
}

int divide(int a, int b) {
    return (a%MOD * power(b,MOD-2)%MOD)%MOD;
}

int C(int n, int r) {
    int ret=1, den=1;
    r = min(r,n-r);
    if(r==1) {
        return n;
    }
    for(int i=1;i<=r;i++) {
        ret = (ret%MOD * (n-i+1)%MOD)%MOD;
        ret = divide(ret, i);
    }
    return ret%MOD;
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
    cin>>n;
    auto nums = getVector(n);

    if(n==1) {
        cout<<2<<endl;
        return;
    }

    int grt=0, num_max=0;

    for(int i: nums) {
        if(i>grt) {
            num_max = 1;
            grt = i;
        } else if(i==grt) {
            num_max++;
        }
    }

    int ret = power(2,n) % MOD;

    if(num_max %2 ==0) {
        ret = ret - (power(2, n - num_max)%MOD * C(num_max, num_max/2)%MOD) %MOD;
    }

    if(ret<0) {
        ret+=MOD;
    }

    cout<<ret%MOD<<endl;

}

int32_t main() {
    GO_BABY_GO;
    ll t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}