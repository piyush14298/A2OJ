#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int t;
    cin>>t;
    vector<int> finalans;
    
    while(t--)
    {
        int n;
        cin>>n;
        unordered_map<int,int> h;
        int temp=n;
        while(temp--)
        {
            int p,s;
            cin>>p>>s;
            if(p>8)
                continue;
            else
                h[p]=max(h[p],s);
        }
        int ans=0;
        for(int i=1;i<=8;i++)
        {
            ans+=h[i];
        }
        finalans.push_back(ans);
    }

    for(auto itr=finalans.begin();itr<finalans.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}
/*
2
5
2 45
9 100
8 0
2 15
8 90
1
11 1
*/