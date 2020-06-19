#include<bits/stdc++.h>
using namespace std;

pair<int,string> numWins(string seq,int r, int p, int s, string curr) {
    if(r<0 || p<0 || s<0) return {-1,""};
    if(seq.size()==0) {
        return {0,curr};
    }
    if(seq[0] == 'R') {
        if(p) {
            auto t = numWins(seq.substr(1),r,p-1,s,curr+"P");
            return {t.first+1,t.second};
        } else {
            auto t1 = numWins(seq.substr(1),r-1,p,s,curr+"R");
            auto t2 = numWins(seq.substr(1),r,p,s-1,curr+"S");

            if(t1.first > t2.first) {
                return t1;
            } else {
                return t2;
            }
        }
    }
    if(seq[0] == 'P') {
        if(s) {
            auto t = numWins(seq.substr(1),r,p,s-1,curr+"S");
            return {t.first+1,t.second};
        } else {
            auto t1 = numWins(seq.substr(1),r,p-1,s,curr+"P");
            auto t2 = numWins(seq.substr(1),r-1,p,s,curr+"R");
            if(t1.first > t2.first) {
                return t1;
            } else {
                return t2;
            }
        }
    }
    if(seq[0] == 'S') {
        if(r) {
            auto t = numWins(seq.substr(1),r-1,p,s,curr+"R");
            return {t.first+1,t.second};
        } else {
            auto t1 = numWins(seq.substr(1),r,p,s-1,curr+"S");
            auto t2 = numWins(seq.substr(1),r,p-1,s,curr+"P");

            if(t1.first > t2.first) {
                return t1;
            } else {
                return t2;
            }
        }
    }
    return {0,""};
}

void solve() {
    int n;
    cin>>n;
    int r,p,s;
    cin>>r>>p>>s;
    string seq;
    cin>>seq;
    
    unordered_map<char,char> losesTo = {'R':'P', 'P':'S', 'S':'R'};
    int oppR=0, oppS=0, oppP=0;
    for(int i=0;i<seq.size();i++) {
        seq[i]=='R'?oppR++:seq[i]=='S'?oppS++:oppP++;
    }
    int wins = 0;
    wins+= min(oppR,p) + min(oppS,r) + min(oppP,s);

    if(wins < (n+1)/2) {
        cout<<"NO"<<endl;
    } else {
        r -= min(r,oppS);
        p -= min(p,oppR);
        s -= min(s,oppP);

        
    }

}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}