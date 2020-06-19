#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int no_zeros(int n)
{
    while(n)
    {
        if(n%10==0)
        {
            return 0;
        }
        n=n/10;
    }
    return 1;
}

int perfect(int n)
{
    int temp=0;
    while(n)
    {
        temp+=(n%10)*(n%10);
        n=n/10;
    }
    int nu=sqrt(temp);
    if(nu*nu==temp)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t,n;
    cin>>t;
    vector<int> ans;

    while(t--)
    {
        cin>>n;

        for(int i=pow(10,n-1);i<pow(10,n);i++)
        {
            if(no_zeros(i)&&perfect(i))
            {
                ans.push_back(i);
                break;
            }
        }
    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}