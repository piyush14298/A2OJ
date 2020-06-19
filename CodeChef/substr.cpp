#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    vector<int> ans;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        map<char,int> h;
        int mini=100000000;
        for(int i=0;i<s.size();i++)
        {
            if(h.find(s[i])!=h.end())
                mini=min(mini,abs(h[s[i]]-i));
            h[s[i]]=i;
        }
        int an;
        if(mini==100000000)
            an=0;
        else
            an=s.size()-mini;
        ans.push_back(an);
    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}