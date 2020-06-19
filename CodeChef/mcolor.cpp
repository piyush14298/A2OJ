#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int mod(int a)
{
    return a<0?-a:a;
}

int same(int i,int j,int m)
{
    return (i-j)%m==0?1:0;
}

int check(vector<pair<int,int> > &chosen,int n, int j,int minimum)
{
    int mini;
    int m=chosen.size();

    if(same(chosen[0].second,j,m) && n>chosen[0].first && mod(chosen[1].first-n)<minimum)
    {
        mini=chosen[m-1].first-min(n,chosen[1].first);
        chosen[0]=make_pair(n,j);
        sort(chosen.begin(),chosen.end());
        return mini;
    }
    if(same(chosen[m-1].second,j,m) && n<chosen[m-1].first && mod(chosen[m-2].first-n)<minimum)
    {
        mini=max(chosen[m-2].first,n) - chosen[0].first;
        chosen[m-1]=make_pair(n,j);
        sort(chosen.begin(),chosen.end());
        return mini;
    }
    return minimum;
}

int main()
{
    int t,n,m;
    int minimum;
    cin>>t;

    vector<int> ans;

    while(t--)
    {
        cin>>n>>m;
        vector<int> boxes(n,0);
        int i=0,temp=n;
        while(temp--)
        {
            cin>>boxes[i];
            i++;
        }

        vector<pair<int,int> > chosen;

        for(int i=0;i<m;i++)
        {
            chosen.push_back(make_pair(boxes[i],i));
        }

        sort(chosen.begin(),chosen.end());

        minimum=chosen[m-1].first - chosen[0].first;

        for(int j=m;j<n;j++)
        {
            minimum= min(minimum,check(chosen,boxes[j],j,minimum));
        }

        ans.push_back(minimum);
    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout<<*itr<<endl;
    }


    return 0;
}