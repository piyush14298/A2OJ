#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> rates(n);

    for(int i=0;i<n;i++)
    {
        cin>>rates[i];
    }

    sort(rates.begin(),rates.end());

    int days;
    cin>>days;
    while(days--)
    {
        int m;
        cin>>m;
        int ans=0;
        if(m<rates[0])
        {
            cout<<0<<endl;
        }
        else if(m>=rates[n-1])
        {
            cout<<n<<endl;
        }
        else
        {
            int l=0,h=n-1;
            while(l<h)
            {
                int mid=l+(h-l)/2;
                
                if(rates[mid]==m)
                {
                    ans=mid+1;
                    break;
                }
                else if(rates[mid]>m)
                {
                    ans=mid;
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            cout<<ans<<endl;
        }   

    }
    return 0;
}