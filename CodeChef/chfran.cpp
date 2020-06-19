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
        vector<pair<int,int> > h;
        while(n--)
        {
            int a,b;
            cin>>a>>b;
            pair<int,int> temp;
            temp.first=a;
            temp.second=b;
            h.push_back(temp);
        }
        sort(h.begin(),h.end());

        int del=0;
        if((h.begin())->second >= (h.end()-1)->first)
            del=-1;
        else
        {
            int high=(h.begin())->second;
            int low=(h.end()-1)->first;

            int cont=1;

            for(auto itr=h.begin()+1;itr<h.end()-1;itr++)
            {
                if(itr->first > high)
                {
                    cont=0;
                    break;
                }
                high=max(high,itr->second);
            }
            if((h.end()-2)->second<(h.end()-1)->first)
            {
                cont=0;
            }

            if(cont==0)
                del=0;
            else
                del=1;
        }
        ans.push_back(del);

    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}