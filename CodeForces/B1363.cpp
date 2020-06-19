#include<bits/stdc++.h>
using namespace std;

struct node {
    int one;
    int zero;
};

void solve() {
    string s;
    cin>>s;
    vector<int> sizes;
    int last = 1;
    for(int i=1;i<s.size();i++) {
        if(s[i]!=s[i-1]) {
            sizes.push_back(last);
            last = 1;
        } else {
            last++;
        }
    }
    sizes.push_back(last);
    if(sizes.size()<=2) {
        cout<<0<<endl;
        return;
    }
    stack<int> st;
    st.push(sizes[0]);
    st.push(sizes[1]);
    int i=2, ret=0;
    while(i<sizes.size()) {
        if(i==sizes.size()-1) {
            int a = st.top();st.pop();
            int b = st.top();st.pop();
            ret+= min({a,b,sizes[i]});
        } else {
            if(sizes[i] < st.top()) {
                int n = st.top();st.pop();
                ret+=sizes[i];
                n+=sizes[i]+sizes[i+1];
                i++;
                st.push(n);
            } else {
                ret+=st.top();
                int a = st.top();st.pop();
                int b = st.top();st.pop();
                int n = a+b+sizes[i];
                st.push(n);
                st.push(sizes[i+1]);
                i++;
            }
        }
        i++;
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