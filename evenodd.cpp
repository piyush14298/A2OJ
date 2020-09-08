
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
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"


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

const int mod = 1e9+7;

int power(int a, int n) {
    if(n==0) {
        return 1;
    }
    int ret = a;
    int base = a, add=1, curr=1;

    while(curr < n) {
        if(curr + add >n) {
            base = a;
            add = 1;
        }
        ret = ((ret%mod) * (base%mod))%mod;
        curr+=add;
        base = ((base%mod)*(base%mod))%mod;
        add*=2;
    }

    return ret;
}

int C(int n, int r) {
    
    r = min(r, n-r);
    if(r==0) {
        return 1;
    }
    int ret=1,k=1;

    while(r) {
        ret*=n;
        k*=r;

        int g = __gcd(ret,k);

        ret/=g;
        k/=g;
        n--;r--;
    }

    return ret%mod;
}

int dp[1000001][2];

int helper(int even, int odd, int k, int wantEven) {
    if(k==1) {
        if(wantEven) {
            return even;
        } else {
            return odd;
        }
    }

    if(dp[k][wantEven] != -1) {
        return dp[k][wantEven];
    }

    int ret;

    if(wantEven) {
        ret = (odd * (helper(even, odd, k-1, 0)%mod))%mod;
        ret+= (even * (helper(even, odd, k-1, 1) %mod))%mod;
    } else {
        ret = (odd * (helper(even, odd, k-1, 1)%mod))%mod;
        ret+= (even * (helper(even, odd, k-1, 0) %mod))%mod;
    }

    

    return dp[k][wantEven] = ret%mod;
}

void solve() {
    int l,r,k;
    cin>>l>>r>>k;

    if(l==r && l%2==1) {
        if(k%2==0) {
            cout<<1<<"";
        } else {
            cout<<0<<"";
        }
        return;
    }



    int even,odd,ret;
    int length = r - l +1;
    if(l%2==0) {
        if(r%2==0) {
            even = (length-1)/2 + 1;
            odd = even-1;
        } else {
            even = odd = length/2;
        }
    } else {
        if(r%2==1) {
            even = (length-1)/2;
            odd = even+1;
        } else {
            even = odd = length/2;
        }
    }

    // memset(dp, -1, sizeof dp);

    // ret = helper(even, odd, k, 1);
    dp[1][0] = odd;
    dp[1][1] = even;
    for(int i=2;i<=k;i++) {
        dp[i][0] = (odd * dp[i-1][1]) + (even * dp[i-1][0]);
        dp[i][0] %= mod;

        dp[i][1] = (odd * dp[i-1][0]) + (even * dp[i-1][1]);
        dp[i][1]%=mod;
    }
    cout<<dp[k][1]<<endl;

    
    // if(length&1) {
    //     if(k&1) {
    //         ret = ((power(length,k)-1)%mod * power(2,mod-2))%mod;
    //     } else {
    //         ret = ((power(length,k)+1)%mod * power(2,mod-2))%mod;
    //     }
        
    // }else {
    //     ret = (power(length,k) * power(2,mod-2))%mod;
    // }

    // cout<<ret<<endl;
    // if(l%2==0) {
    //     if(r%2==0) {
    //         even = (length-1)/2 + 1;
    //         odd = even-1;
    //     } else {
    //         even = odd = length/2;
    //     }
    // } else {
    //     if(r%2==1) {
    //         even = (length-1)/2;
    //         odd = even+1;
    //     } else {
    //         even = odd = length/2;
    //     }
    // }

    // int ret = 0;

    // for(int i=0;k-i>=0;i+=2) {
    //     int a = power(even,k-i);
    //     int b = power(odd,i);
    //     int c = C(k,i);

    //     // cout<<a<<" "<<b<<" "<<c<<endl;

    //     int ans = ((((a%mod)*(b%mod))%mod) * (c%mod)) % mod;

    //     ret+=ans;
    //     ret%=mod;
    // }

    // cout<<ret<<"";
}

int32_t main() {
    GO_BABY_GO;
    ll t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}