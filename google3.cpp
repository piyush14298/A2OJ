#include<bits/stdc++.h>
#define ull long long
#include<unordered_map>
using namespace std;

int mod = 1000000000;
unordered_map<char,int> h;

int MOD(int a) {
    if(a>=0) {
        return a%mod;
    } else {
        int i = abs(a) / mod;
        return mod*(i+1) + a;
    }
}

void parse(string s, int fac) {
    int i=0;
    while(i<s.size()) {
        if(s[i] >='0' && s[i]<='9') {
            int num = s[i] - '0';
            i+=2;
            int b = 1, j=i+1;
            while(b!=0) {
                if(s[j]=='(') {
                    b++;
                } else if(s[j]==')') {
                    b--;
                }
                j++;
            }
            // cout<<"here: "<<s.substr(i,j-i-1)<<fac<<endl;
            parse(s.substr(i,j-i-1),num*fac);
            i=j-1;
        } else {
            // cout<<"there: "<<s[i]<<fac<<endl;
            h[s[i]] += fac;
        }
        i++;
    }
    
}

void f() {
    string s;
    cin>>s;
    h.clear();
    parse(s, 1);
    int vert = h['S'] - h['N'];
    int horz = h['E'] - h['W'];
    cout<<MOD(horz)<<" "<<MOD(vert)<<endl;
}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout<<"Case #"<<i<<": ";
        f();
    }
    return 0;
}