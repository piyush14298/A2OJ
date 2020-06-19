#include<bits/stdc++.h>
using namespace std;

int main()

{
    int t;
    cin>>t;
    vector<int> p;
    while(t--)
    {
        int n;
        cin>>n;
        int num2=0,num0=0;
        while(n--)
        {
            int temp;
            cin>>temp;
            if(temp==2)
                num2++;
            if(temp==0)
                num0++;
        }
        int ans2;
        if(num2==0 || num2==1)
            ans2=0;
        else
            ans2= num2%2==0?(num2/2)*(num2-1):num2*((num2-1)/2);
        
        int ans0;
        if(num0==0 || num0==1)
            ans0=0;
        else
            ans0= num0%2==0?(num0/2)*(num0-1):num0*((num0-1)/2);

        
        p.push_back(ans0+ans2);
    }

    for(auto itr=p.begin();itr<p.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}