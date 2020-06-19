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
    int maxi=-1,temp=1;

    for(int i=1;i<n;i++)
    {
        if(v[i]<v[i-1])
        {
            maxi=max(maxi,temp);
            temp=0;
        }
        temp++;
    }
    maxi=max(maxi,temp);

    cout<<maxi<<endl;

    return 0;
}