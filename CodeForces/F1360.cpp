#include<bits/stdc++.h>
using namespace std;

int getDistance(string a, string b) {
    int ret=0;
    int i=0;
    while(i<a.size()) {
        if(a[i] != b[i])
            ret++;
        if(ret>1)
            return ret;
        i++;
    }
    return ret;
}


void getComb(vector<set<char> >& options, int i, string s, vector<string>& ret) {
    if(i==options.size()) {
        ret.push_back(s);
        return;
    }

    for(auto t:options[i]) {
        getComb(options,i+1,s+t,ret);
    }
}

vector<string> getStrings(vector<set<char> >& options) {
    vector<string> ret;
    getComb(options,0,"",ret);
    return ret;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> strings(n);
    for(int i=0;i<n;i++) {
        cin>>strings[i];
    }
    vector<set<char> > options(m);

    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            options[i].insert(strings[j][i]);
        }
    }
    vector<string> comb = getStrings(options);

    for(string s:comb) {
        bool found = true;
        for(string i:strings) {
            if(getDistance(s,i) > 1) {
                found = false;
                break;
            }
        }
        if(found) {
            cout<<s<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}