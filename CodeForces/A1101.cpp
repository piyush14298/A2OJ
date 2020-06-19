#include<iostream>
using namespace std;

int main()
{
    int n;
    long l,r,d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>l>>r>>d;
        if((d<l||d>r))
        {
            cout<<d<<endl;
        }
        else
        {
            cout<<d*((r/d)+1)<<endl;
        }
    }

    return 0;
}