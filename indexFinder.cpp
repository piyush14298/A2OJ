#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    int check;
    cin>>check;

    while(check!=-1)
    {
        if(check<v[0])
            cout<<0<<endl<<endl;
        else if(check>v[n-1])
            cout<<n<<endl<<endl;
        else
        {
            int l=0,h=n-1;
            int ans;
            while(l<=h)
            {
                int mid=l+(h-l)/2;

                if(v[mid]==check)
                {
                    ans=mid+1;
                    break;
                }
                else if(v[mid]>check)
                {
                    ans=mid;
                    h=mid-1;
                }
                else
                {
                    l=mid+1;
                }
                
            }
            cout<<ans<<endl<<endl;
        }

        cin>>check;
    }

    return 0;
}