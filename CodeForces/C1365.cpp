// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long int
// #define ull unsigned long long
// #define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
// #define fo(i,a,b) for(ll i=a;i<=b;i++)
// #define vi vector<int>
// #define vll vector<ll>
// #define vull vector<ull>
// #define end "\n"
// ll getInt() {
//     ll t;
//     cin>>t;
//     return t;
// }
// vll getVector(int n) {
//     vll temp(n);
//     fo(i,0,n-1) {
//         cin>>temp[i];
//     }
//     return temp;
// }
// void printVector(vector<ll> a) {
//     fo(i,0,a.size()-1) {
//         cout<<a[i]<<" ";
//     }
//     cout<<end;
// }
// ll min(ll a, ll b) {return a<b?a:b;}
// ll max(ll a, ll b) {return a>b?a:b;}

// ll mod(ll a, ll b) {
//     if(a<0) {
//         return b+a;
//     } else {
//         return a%b;
//     }
// }


// void solve() {
//     int n = getInt();
//     auto A = getVector(n);
//     auto B = getVector(n);

//     vector<vector<ll>> mat(n, vll(n,0));

//     fo(i,0,n-1) {
//         fo(j,0,n-1) {
//             if(i==0) {
//                 mat[i][j] = A[i] == B[j];
//             } else {
//                 if(A[i] == B[j]) {
//                     mat[i][j] = mat[mod(i-1,n)][mod(j-1,n)] + 1;
//                 } else {
//                     mat[i][j] = max(mat[i-1][j], j==0?mat[i][n-1]:mat[i][j-1]);
//                     // mat[i][j] = 0;
//                 }
//             }
//         }
//     }

//     cout<<mat[n-1][n-1];
// }

// int main() {
//     GO_BABY_GO;
//     // ll t = getInt();
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
    using namespace std;
    const int MX=200005;
    int tab[200005];
    int main(){
     int n,HH=0;
     cin>>n;
     vector<int> A(n),B(n);
     for(auto& it:A)cin>>it;
     for (int i = 0; i < n; ++i)
      cin>>B[i],tab[B[i]]=i;
     map<int,int> h;
     for (int i = 0; i < n; ++i)
     {
      if(tab[A[i]]>i)
       h[n-(tab[A[i]]-i)]++;
      else h[i-tab[A[i]]]++;
     }
     for(auto it:h)
      HH=max(HH,it.second);
     cout<<HH<<"\n";
     return 0;
    }