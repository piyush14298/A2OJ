#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int fb=-1,lb=-1,fc=-1,lc=-1;
    for(int i=0;i<n;i++)
    {
        // cout<<s[i];
        if(s[i]=='[')
        {
            fb=i;
        }
        if(s[i]==':' && fb!=-1)
        {
            fc=i;
            break;
        }
    }
    for(int i=n-1;i>fc;i--)
    {
        // cout<<s[i];
        if(s[i]==']')
        {
            lb=i;
        }
        if(s[i]==':' && lb!=-1)
        {
            lc=i;
            break;
        }
    }
    if(fb==-1||fc==-1||lb==-1||lc==-1)
    {
        cout << "-1";
        return 0;
    }
    int ans=4;
    for(int i=fc;i<lc;i++)
    {
        if(s[i]=='|')
        {
            ans++;
        }
    }
    cout<<ans;

    return 0;
}