#include<bits/stdc++.h>
using namespace std;

string exor(string a,string b)
{
    string ans="";
    int i;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
    if(a.size()>b.size())
    {
        for(i=0;i<b.size();i++)
        {
            if(a[i]==b[i])
                ans+="0";
            else
                ans+="1";
        }
        ans+=a.substr(i,a.size()-1);
    }
    else
    {
        for(i=0;i<a.size();i++)
        {
            if(a[i]==b[i])
                ans+="0";
            else
                ans+="1";
        }
        ans+=b.substr(i,b.size()-1);
    }
	reverse(ans.begin(),ans.end());
    return ans;
}

string and1(string a,string b)
{
    string ans="";
    int i;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
    if(a.size()>b.size())
    {
        for(i=0;i<b.size();i++)
        {
            if(a[i]=='1'&&b[i]=='1')
                ans+="1";
            else
                ans+="0";
        }
    }
    else
    {
        for(i=0;i<a.size();i++)
        {
            if(a[i]=='1'&&b[i]=='1')
                ans+="1";
            else
                ans+="0";
        }
    }
	reverse(ans.begin(),ans.end());
    return ans;
}

bool value(string b)
{
    for(char c:b)
    {
        if(c=='1')
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    vector<int> ans;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        int an=0;
        while(value(b))
        {
            string u=exor(a,b);
            string v=and1(a,b);
            a=u;
            b=v+"0";
            an++;
        }
        // cout<<"trst";
        ans.push_back(an);
    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}