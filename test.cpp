#include<bits/stdc++.h>
 
 
 
using namespace std;
 
#define rep(i,a,b); for(long long int i=a;i<b;i++)
#define mk make_pair        
#define LIMIT 100007
#define MOD 1000000007
#define ll long int
#define endl '\n'
#define min3(a,b,c) ((a>b)?((b>c?c:b):(a>c?c:a)))
#define max3(a,b,c) ((a<b)?((b<c?c:b):(a<c?c:a)))
#define min(a,b) (a>b?b:a)
// #define x.first x.f
// #define x.second x.s
#define max(a,b) (a<b?b:a)
#define pb push_back
#define FAST std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
/*
set<ll> s;
 
void SieveOfEratosthenes(ll n,ll a[],ll m) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
 
    bool prime[n+1]; 
    ll count=0;
    memset(prime, true, sizeof(prime)); 
  
    rep(i,0,m)
    { 
    	ll p=a[i];
        if (prime[p]==true) 
        { 
            for (ll i=2*p; i<=n; i += p) 
              {  
              	prime[i] = false;
              	//cout<<i<<" ";
              } 
        } 
    } 
  
    rep(i,0,m-1)
    {
    	if(a[i]==a[i+1]) prime[a[i]]=false;
    }
 
    rep(i,0,m)
    {
    	if(prime[a[i]]==true) count++;
    }
 
     cout<<count;
} 
 
*/
 
int main() 
{ 
    FAST
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll k;
    cin>>k;
 
    ll sum=1,t=0;
    ll v[10];
    rep(i,0,10) v[i]=1;
    while(sum<k)
    {
    	v[t]++;
    	t=(t+1)%10;
    	sum=1;
    	rep(i,0,10)
    	{
    		sum*=v[i];
    	}
    }
 
    string str="codeforces";
    rep(i,0,10)
    {
    	rep(j,0,v[i])
    	{
    		cout<<str[i];
    	}
    }
 
 
    return 0; 
}