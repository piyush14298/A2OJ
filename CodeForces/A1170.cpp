#include<iostream>
using namespace std;

int main()
{
    int q,x,y;
    cin>>q;
    while(q!=0)
    {
        cin>>x>>y;
        if(x>y)
        {
            int temp=x;
            x=y;
            y=temp;
        }
        cout<<"1 "<<x-1<<" "<<y-x+1<<endl;
        q--;
    }

    return 0;
}