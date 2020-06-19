#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int ans=((1+(a+b-2))*2)%(1000000007);
    cout<<ans<<endl;

    return 0;
}