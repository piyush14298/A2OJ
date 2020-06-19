#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull btol(string a) {
    ull ret = 0;
    for(int i=a.size()-1;i>=0;i--) {
        if(a[i] == '1') {
            ret+=(1<<(a.size()-i-1));
        }
    }
    return ret;
}

string tostr(ull a, int m) {
    string ret="";
    while(a) {
        if(a&1)
            ret="1"+ret;
        else 
            ret="0"+ret;
        a=a>>1;
    }
    while(ret.size()!=m) {
        ret = "0"+ret;
    }
    return ret;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> rem(n);
    for(int i=0;i<n;i++) {
        cin>>rem[i];
    }

    ull h = (1<<m)-1;
    ull med = h/2;

    vector<ull> s;

    for(string i:rem) {
        s.push_back(btol(i));
    }
    sort(s.begin(),s.end());
    set<ull> del;
    bool onceO = false;
    bool onceE = true;
    for(auto i:s) {
        if(i > med) {
            if(!onceO) {
                onceO = true;
            } else {
                med--;
                while(del.count(med)) med--;
                onceO = false;
            }
            
        } else {
            // med++;
            // while(del.count(med)) med++;
            if(!onceE) {
                onceE = true;
            } else {
                med++;
                while(del.count(med)) med++;
                onceE = false;
            }
        }
        del.insert(i);
    }

    cout<<tostr(med,m)<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}