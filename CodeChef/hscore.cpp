#include<bits/stdc++.h>

using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    int t,n;
    vector<vector<int> > ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> tempans;
        vector<int> temp;
        while(n--)
        {
            int t;
            cin>>t;
            temp.push_back(t);
            sort(temp.begin(),temp.end());
            int maxi=0;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]+i-1>=temp.size())
                {
                    maxi=max(maxi,temp.size()-i);
                }
                else
                {
                    maxi=max(maxi,temp[i]);
                }
                
            }
            tempans.push_back(maxi);
        }
        ans.push_back(tempans);
    }


    for(int i=0;i<ans.size();i++)
    {
        cout<<"Case #"<<i+1<<": ";
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}