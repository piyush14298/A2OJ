#include<iostream>
using namespace std;

int main()
{
    int n,k,n1;
    cin >> n >> k >> n1;
    int t;
    if(n%n1==0)
    {
        t=n/n1;
    }
    else
    {
        t=n/n1+1;
    }
    if(k<t*t)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }

    return 0;
}