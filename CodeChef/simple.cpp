#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t,n;

    cin>>t;
    vector<int> ans;

    while(t--)
    {
        cin>>n;
        int a;
        cin>>a;
        vector<int> temp(a,0);
        int i=0;
        int tempa=a;
        while(tempa--)
        {
            cin>>temp[i];
            i++;
        }
        int anss=0;
        for(int i=0;i<=(a-1)/2;i++)
        {
            anss+=temp[i];
        }
        ans.push_back(anss);
    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;
}