#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
const long MAX = 1e10;

long min(long  a,  long b) { return a<b?a:b;}

// long divide(long a, long b) {
//     if(b==0)
//         return 1;
//     long ret = a/b;
//     return ret;
// }

// void getMin(long a, long b, long c, long p, long q, long r , long curr, long& ans) {
//     if(curr>ans) {
//         return;
//     }
//     if(a==p && b==q && c==r) {
//         ans = min(ans,curr);
//         return;
//     }
//     long d1 = a-p, d2 = b-q, d3 = c-r;
//     if(d1 == d2 && d1==d3) {
//         ans = min(ans,curr+1);
//         return;
//     }
//     if(a==b && b==c) {
//         ans=min(curr+2,ans);
//         return;
//     }

//     int temp = 0;
//     if(d1!=0) {
//         temp++;
//     }
//     if(d2!=0 && d2!=d1) {
//         temp++;
//     }
//     if(d3!=0 && d1!=d3 && d2!=d3) {
//         temp++;
//     }
//     if(temp==1) {
//         ans = min(ans, curr+temp);
//         return;
//     }
//     long q1 = divide(a,p), q2 = divide(b,q), q3 = divide(c,r);
//     if(q1 == q2 && q2==q3 && q1>1) {
//         getMin(a,b,c,p*q1,q*q1,r*q1, curr+1,ans);
//     } else if(q1==q2) {
//         getMin(a,b,c,p*q1, q*q1, r, curr+1,ans);
//         if(q3>1) getMin(a,b,c,p,q,r*q3,curr+1,ans);
//     } else if(q2==q3) {
//         if(q1>1)  getMin(a,b,c,p*q1, q, r, curr+1, ans);
//         getMin(a,b,c,p,q*q2,r*q3, curr+1, ans);
//     } else if(q1==q3) {
//         getMin(a,b,c,p*q1, q, r*q3, curr+1, ans);
//         if(q2>1) getMin(a,b,c,p,q*q2,r, curr+1, ans);
//     } else {
//         if(q1>1) getMin(a,b,c,p*q1, q, r, curr+1, ans);
//         if(q3>1) getMin(a,b,c,p,q,r*q3,curr+1,ans);
//         if(q2>1) getMin(a,b,c,p,q*q2,r,curr+1,ans);
//     }
//     // ans = min(ans, getMin(a,b,c,p*(q1<=1?1:Q), q*(q2<=1?1:Q), r*(q3<=1?1:Q))+1);
//     // return ans;
// }

// long getDiffVal(int a, int b, int c, int p, int q, int r) {
//     long d1 = a-p, d2 = b-q, d3 = c-r;
//     int temp = 0;
//     if(d1!=0) {
//         temp++;
//     }
//     if(d2!=0 && d2!=d1) {
//         temp++;
//     }
//     if(d3!=0 && d1!=d3 && d2!=d3) {
//         temp++;
//     }
//     return temp;
// }

vector<pair<int,int> > getComb(int a, int b) {
    vector<pair<int,int> > ret;
    int i=0;
    while(a*i <= b) {
        ret.push_back({i,(b-(a*i))});
        i++;
    }
    return ret;
}

// void bfs(vector<pair<int,int> >& A, vector<pair<int,int> >& B, vector<pair<int,int> >& C, 
//         int i, int j, int k, unordered_map<int, bool> seenMul, unordered_map<int,bool> seenAdd, 
//         int mul, int add, int& ret) {
//     if(i==A.size() || j==B.size() || k==C.size()) {
//         ret = min(ret, mul+add);
//         return;
//     }
//     if(k<C.size()) {
//         int m = C[k].first;
//         int a = C[k].second;
//         if(!seenMul[m]) {
//             seenMul[m] = true;
//             mul++;
//         }
//         if(!seenAdd[a]) {
//             seenAdd[a] = true;
//             add++;
//         }
//     }
// }

// void display(vector<pair<int,int> > A) {
//     for(int i=0;i<A.size();i++) {
//         cout<<"X"<<A[i].first<<"  +"<<A[i].second<<endl;
//     }
//     cout<<"\n\n";
// }

void solve() {
    long a,b,c,p,q,r;
    cin>>p>>q>>r>>a>>b>>c;
    auto A = getComb(p,a), B =getComb(q,b), C = getComb(r,c);
    if(A.size()>B.size())
        swap(A,B);
    if(A.size()>C.size()) {
        swap(A,C);
    }
    if(B.size()>C.size()) {
        swap(B,C);
    }
    // display(A);display(B);display(C);
    int ret=4;
    // unordered_map<int,bool> seenMul, seenAdd;
    // bfs(A,B,C,0,0,0,seenMul,seenAdd,0,0,ret);
    for(int i=0;i<A.size();i++) {
        unordered_map<int,int> seenAdd, seenMul;
        seenMul[A[i].first]++;
        seenAdd[A[i].second]++;
        for(int j=0;j<B.size();j++) {
            seenMul[B[j].first]++;
            seenAdd[B[j].second]++;
            int tm=0, ta=0;
            for(auto i:seenMul) {
                if(i.second>0 && i.first!=1)
                    tm++;
            }
            for(auto i:seenAdd) {
                if(i.second>0 && i.first!=0)
                    ta++;
            }
            if(tm+ta>=3) {
                seenMul[B[j].first]--;
                seenAdd[B[j].second]--; 
                continue;
            }
            for(int k=0;k<C.size();k++) {
                seenMul[C[k].first]++;
                seenAdd[C[k].second]++;
                int m=0, a=0;
                for(auto i:seenMul) {
                    if(i.second>0 && i.first!=1)
                        m++;
                }
                for(auto i:seenAdd) {
                    if(i.second>0 && i.first!=0)
                        a++;
                }
                // cout<<"m="<<m<<"  a="<<a<<endl;
                ret = min(ret,m+a);
                if(ret==1) {
                    cout<<1<<endl;
                    return;
                }
                // cout<<"here"<<endl;
                seenMul[C[k].first]--;
                seenAdd[C[k].second]--;
            }
            seenMul[B[j].first]--;
            seenAdd[B[j].second]--;
        }
    }
    cout<<ret<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

/*
Tests

6
3 3 3
4 4 4
3 4 5
6 6 6
2 3 4
4 6 8
2 3 4
5 7 9
2 3 4
4 9 12
2 3 4
4 6 7

*/