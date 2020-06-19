#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long exponent(long x, long n) {
    if(n==1) {
        return x;
    }
    long ans = exponent(x,n/2) * exponent(x,n/2);

    if(n%2!=0) {
        ans = ans * x;
    }

    return ans;
}

int main() {
    cout<<"Enter number and exponent: ";
    long x,n;
    cin>>x>>n;

    long ans = exponent(x,n);

    cout<<ans<<endl;

    return 0;
}