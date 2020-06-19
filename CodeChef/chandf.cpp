#include<bits/stdc++.h>
using namespace std;

unsigned long long f() {
    unsigned long long x,y,l,r;
    cin>>x>>y>>l>>r;
    if(x==0 || y==0) {
        return 0;
    }

    unsigned long long OR = x|y;
    unsigned long long AND = x&y;
    // return (x|y);
    if((x|y) >=l && (x|y) <=r) {
        return (x|y);
    }
    if(x<y) {
        swap(x,y);
    }
    if(r>=y) {
        return y;
    }
    if(r>=x) {
        return x;
    }
    if(AND > r) {
        return 0;
    }
    unsigned long ma=0,mi=l;
    for (int i = AND; i<=r; i++)
    {
        unsigned long temp; //12= 1100 6=0110
        temp = x & i;
        temp *= (y & i);
        if(temp>ma)
            ma = temp, mi = i;
    //     cout << temp << endl;
    }
    return mi;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        cout<<f()<<endl;
    }

    return 0;
}