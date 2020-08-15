#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair
 
 
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,n,i,j,k;
    cin>>T;
    while(T--)
    {
    	cin>>n;
    	string s;
    	cin>>s;
    	map<int,int> m;
    	int ans=0;
    	m[0]++;
    	k=0;
    	for(i=0;i<n;i++)
    	{
    		k+=(s[i]-'0');
    		ans+=m[k-(i+1)];
    		m[k-(i+1)]++;
    	}
    	cout<<ans<<endl;
 
    }
	return 0;
}