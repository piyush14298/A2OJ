#include<iostream>
using namespace std;

int main()
{
    int n,t;
    cin >> n >> t;
    int a[n-1];
    for(int i=0;i<n-1;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n-1;)
    {
        int temp=i+a[i-1];
        if(temp==t)
        {
            cout << "YES" << endl;
            return 0;
        }
        i=temp;
    }
    cout << "NO" << endl;

    return 0;
}