#include<iostream>
using namespace std;
#define ulli unsigned long long int 

int isPrime(ulli x)
{
    if(x==2)
    {
        return 1;
    }
    if(x%2==0)
    {
        return 0;
    }
    for(ulli i=3;i*i<=x;i+=2)
    {
        if(x%i==0)
        {
            return 0;
        }
    }
    return 1;
    
}

int main()
{
    ulli x,y,z;
    int t;
    int isp=1;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        z=x-y;
        if(z==1)
            cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
        }
    }
    

    return 0;
}