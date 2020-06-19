#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector<int>
#define vll vector<ll>
#define vull vector<ull>
#define end "\n"
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
    cout<<end;
}
ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}

bool canOut(vector<vector<char>>& mat, int i, int j, vector<vector<bool> >& seen) {
    int n = mat.size(), m = mat[0].size();
    if(i<0||i>=n||j<0||j>=m||seen[i][j]||mat[i][j]=='#') {
        return false;
    }
    if(i==n-1 && j==m-1) {
        // cout<<"here"<<endl;
        return true;
    }
    seen[i][j] = true;
    return canOut(mat,i-1,j,seen) || canOut(mat,i+1,j,seen) || canOut(mat,i,j-1,seen) || canOut(mat,i,j+1,seen);
}

bool canAllG(vector<vector<char> >& mat) {
    int n = mat.size(), m = mat[0].size();
    fo(i,0,n-1) {
        fo(j,0,m-1) {
            if(mat[i][j] == 'G') {
                vector<vector<bool> >seen(n,vector<bool>(m,false));
                if(!canOut(mat,i,j,seen)) return false;
            }
        }
    }
    return true;
}

bool putWall(vector<vector<char> >& mat, int i, int j) {
    int n = mat.size(), m = mat[0].size();
    if(i<0||i>=n||j<0||j>=m||mat[i][j]=='#') {
        return true;
    }
    if(mat[i][j] == 'B') {
        return true;
    }
    if(mat[i][j] == 'G') {
        return false;
    }
    mat[i][j] = '#';
    return true;
}

bool block(vector<vector<char> >& mat, int i, int j) {
    return putWall(mat,i+1,j) && putWall(mat,i-1,j) && putWall(mat,i,j+1) && putWall(mat,i,j-1);
}

bool canAllB(vector<vector<char> >& mat) {
    int n = mat.size(), m = mat[0].size();
    fo(i,0,n-1) {
        fo(j,0,m-1) {
            if(mat[i][j] == 'B') {
                vector<vector<bool> >seen(n,vector<bool>(m,false));
                if(canOut(mat,i,j,seen)) return true;
            }
        }
    }
    // cout<<"here"<<endl;
    return false;
}

void solve() {
    auto n = getInt(), m = getInt();
    vector<vector<char> > mat(n, vector<char>(m));
    fo(i,0,n-1) {
        fo(j,0,m-1) {
            cin>>mat[i][j];
        }
    }

    // cout<<canAllG(mat)<<endl;
    fo(i,0,n-1) {
        fo(j,0,m-1) {
            if(mat[i][j] == 'B') {
                if(!block(mat,i,j)) {
                    cout<<"NO"<<endl;
                    return;
                }    
                if(!canAllG(mat)) {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    if(canAllB(mat)) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    return;
    
}

int main() {
    GO_BABY_GO;
    ll t = getInt();
    while(t--) {
        solve();
    }
    return 0;
}