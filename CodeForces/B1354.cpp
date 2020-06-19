#include<bits/stdc++.h>
using namespace std;

struct node {
    int one,two,three;
};

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    vector<node> right(s.size()), left(s.size());

    left[0].one=left[0].two=left[0].three = -1;
    right[n-1].one=right[n-1].two=right[n-1].three = -1;

    for(int i=1;i<n;i++) {
        left[i].one = s[i-1]=='1'?1:(left[i-1].one==-1?-2:left[i-1].one)+1;
        left[i].two = s[i-1]=='2'?1:(left[i-1].two==-1?-2:left[i-1].two)+1;
        left[i].three = s[i-1]=='3'?1:(left[i-1].three==-1?-2:left[i-1].three)+1;
    }
    for(int i=n-2;i>=0;i--) {
        right[i].one = s[i+1]=='1'?1:(right[i+1].one==-1?-2:right[i+1].one)+1;
        right[i].two = s[i+1]=='2'?1:(right[i+1].two==-1?-2:right[i+1].two)+1;
        right[i].three = s[i+1]=='3'?1:(right[i+1].three==-1?-2:right[i+1].three)+1;
    }

    int ret = n+1;

    // for(int i=0;i<n;i++) {
    //     cout<<s[i]<<": "<<left[i].one<<" "<<left[i].two<<" "<<left[i].three<<"   "<<right[i].one<<" "<<right[i].two<<" " << right[i].three<<endl;
    // }

    for(int i=0;i<n;i++) {
        switch(s[i]) {
            case '1':
                if(left[i].two!=-1 && left[i].three!=-1) {
                    // cout<<"here1\n";
                    ret = min(ret,1+left[i].two+left[i].three);
                } if(right[i].two!=-1 && right[i].three!=-1) {
                    // cout<<"here2\n";
                    ret = min(ret,1+right[i].two+right[i].three);
                } if(left[i].two!=-1 && right[i].three!=-1) {
                    // cout<<"here3\n";
                    ret = min(ret,1+left[i].two+right[i].three);
                }  if(right[i].two!=-1 && left[i].three!=-1) {
                    // cout<<"here4\n";
                    ret = min(ret,1+right[i].two+left[i].three);
                }
                break;
            case '2':
                if(left[i].one!=-1 && left[i].three!=-1) {
                    ret = min(ret,1+left[i].one+left[i].three);
                }  if(right[i].one!=-1 && right[i].three!=-1) {
                    ret = min(ret,1+right[i].one+right[i].three);
                }  if(left[i].one!=-1 && right[i].three!=-1) {
                    ret = min(ret,1+left[i].one+right[i].three);
                }  if(right[i].one!=-1 && left[i].three!=-1) {
                    ret = min(ret,1+right[i].one+left[i].three);
                }
                break;
            case '3':
                if(left[i].one!=-1 && left[i].two!=-1) {
                    ret = min(ret,1+left[i].one+left[i].two);
                }  if(right[i].one!=-1 && right[i].two!=-1) {
                    ret = min(ret,1+right[i].one+right[i].two);
                }  if(left[i].one!=-1 && right[i].two!=-1) {
                    ret = min(ret,1+left[i].one+right[i].two);
                }  if(right[i].one!=-1 && left[i].two!=-1) {
                    ret = min(ret,1+right[i].one+left[i].two);
                }
                break;
        }
    }
    if(ret==n+1) {
        cout<<0<<endl;
        return;
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