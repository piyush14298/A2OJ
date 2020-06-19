#include<bits/stdc++.h>
using namespace std;

int mod(int a)
{
    return a>0?a:-a;
}

int main()
{
    int t;
    cin>>t;
    vector<int> ans;
    while(t--)
    {
        int a,b;
        int op=0;
        cin>>a>>b;
        if(a>b)
        {
            if(a-b>3 && a-5>=0)
            {
                
                op+=(a-b)/5+((a-b)%5>3?1:0);
                a=a-5*op;
            }
            if(mod(a-b)==4)
            {
                op+=2;
            }
            else if(mod(a-b)==3)
            {
                op+=2;
            }
            else if(a-b!=0)
            {
                op++;
            }
        }
        else if(a<b)
        {
            if(b-a>3)
            {
                op+=(b-a)/5+((b-a)%5>3?1:0);
                a=a+5*op;
                
            }
            if(mod(a-b)==3)
            {
                op+=2;
            }
            else if(a-b!=0)
            {
                op++;
            }
        }
        ans.push_back(op);

    }

    for(auto it=ans.begin();it<ans.end();it++)
    {
        cout<<*it<<"\n";
    }

    return 0;
}