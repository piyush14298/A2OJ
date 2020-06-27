#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<unordered_set>
using namespace std;
#define int long long
#define uint unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
#define vint vector<int>
#define vuint vector<uint>
#define endl "\n"

struct Point 
{ 
    int x, y; 
}; 
int getInt() {
    int t;
    cin>>t;
    return t;
}
vint getVector(int n) {
    vint temp(n);
    fo(i,0,n-1) {
        cin>>temp[i];
    }
    return temp;
}
void printVector(vector<int> a) {
    fo(i,0,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int min(int a, int b) {return a<b?a:b;}
int max(int a, int b) {return a>b?a:b;}

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| UintONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| intONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| intONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

void solve() {
    int n; cin>>n;
    int k; cin>>k;
    
    vector<int> v(n);

    fo(i, 0, n){ cin>>v[i];};
    
    sort(v.begin(), v.end());
    
    stack<int> st;
    
    fo(i, 0, n) st.push(v[i]);
    
    
    
    vector<int> w(k);
    fo(i, 0, k) cin>>w[i];
    
    sort(w.begin(), w.end());
    
    int ret = 0;
    
    int j = 0;
    fo(i, 0, k){
        int count = w[i];
        
        unordered_set<int> unq;
        vector<int> temp;
        
        int maxe = -1e9, mine = 1e9;
        
        while(j<n && unq.size() != count&& st.size() > 0){
            int prev_size = unq.size();
            
            int ele = st.top();
            unq.insert(st.top());
            st.pop();
            
            int new_size = unq.size();
            
            
            if(prev_size == new_size){
                temp.push_back(ele);
            }else{
                maxe = max(maxe, ele);
                mine = min(mine, ele);
            }
        }
        
        int diff = 0;
        if(unq.size() != count){
            diff = count - unq.size();
        }
        
        for(j = temp.size()-1 - diff ; j >= 0; j--){
            st.push(temp[j]);
        }
        
        ret+= (maxe + mine);
    }
    
    cout<<ret<<endl;
}

int32_t main() {
    GO_BABY_GO;
    int t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}