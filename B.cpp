#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define u unsigned long long int

int main()
{
    int n;
    cin>>n;
    vector<int> sticks(n);
    int temp=n;
    int i=0;
    while(temp--)
    {
        cin>>sticks[i];
        i++;
    }
    sort(sticks.begin(),sticks.end());
    
    int cut;
    if(n%2==0)
    {
        cut=(n-1)/2;
    }
    else
    {
        cut=(n/2)-1;
    }

    u x=0;
    u y=0;

    for(i=0;i<n;i++)
    {
        if(i<=cut)
        {
            x+=sticks[i];
        }
        else
        {
            y+=sticks[i];
        }
    }

    u ans=x*x+y*y;
    cout<<ans<<endl;
    

    return 0;
}