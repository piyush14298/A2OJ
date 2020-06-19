#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> make()
{
    vector<int> ans(130);
    ans[0]=0;
    ans[1]=0;
    for(int i=2;i<130;i++)
    {
        if(count(ans.begin(),ans.begin()+i,ans[i-1])==1)
        {
            ans[i]=0;
        }
        else
        {
            for(int j=i-2;j>=0;j--)
            {
                if(ans[i-1]==ans[j])
                {
                    ans[i]=i-j-1;
                    break;
                }
            }
        }
    }
    return ans;
}


int main()
{
    int t,n;
    vector<int> seq(130);
    seq=make();
    // cout<<seq[0]<<seq[1]<<seq[2]<<seq[3]<<seq[4];
    
    cin>>t;
    int temp=t;
    vector<int> ans(t,0);

    while(t--)
    {
        cin>>n;
        int match=seq[n-1];
        for(int i=0;i<n;i++)
        {
            if(match==seq[i])
            {
                ans[t]++;
            }
        }
    }

    for(int i=temp-1;i>=0;i--)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}