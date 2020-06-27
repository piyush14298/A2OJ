#include <bits/stdc++.h> 
using namespace std; 
  
#define ll long long
#define FORI(a, b, i, inc) for(ll i = a; i < b; i = i + inc)
#define FOR(a, b, i) for(ll i = a; i < b; i++)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define test ll t; cin>>t; while(t--)
#define vec vector
#define all(v) v.begin(), v.end()
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);


bool compare(ll a, ll b){
    return a > b;
}

int main()
{
    test{
       ll n; cin>>n;
       ll k; cin>>k;
       
       vec<ll> v(n);
 
       FOR(0, n, i){ cin>>v[i];};
       
       sort(all(v));
       
       stack<ll> st;
       
       FOR(0, n, i) st.push(v[i]);
       
       
       
       vec<ll> w(k);
       FOR(0, k, i) cin>>w[i];
       
       sort(all(w));
       
       ll ans = 0;
       
       ll j = 0;
       FOR(0, k, i){
           ll count = w[i];
           
           unordered_set<ll> uniq;
           vec<ll> temp;
           
           ll maxe = LONG_MIN, mine = LONG_MAX;
           
           while(j<n && uniq.size() != count&& st.size() > 0){
                ll prev_size = uniq.size();
                
                ll ele = st.top();
                uniq.insert(st.top());
                st.pop();
                
                ll new_size = uniq.size();
                
                
                if(prev_size == new_size){
                    temp.pb(ele);
                }else{
                    maxe = max(maxe, ele);
                    mine = min(mine, ele);
                }
           }
           
           ll diff = 0;
           if(uniq.size() != count){
              diff = count - uniq.size();
           }
           
           for(j = temp.size()-1 - diff ; j >= 0; j--){
               st.push(temp[j]);
           }
           
           ans+= (maxe + mine);
       }
       
       cout<<ans<<endl;
       
       
    }

	return 0;
}