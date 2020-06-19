#include<iostream>
#include<cmath>
using namespace std;

#define V 1000000007

int main()
{
    int h,w;
    cin>>h>>w;
    int r[h],c[w];
    for(int i=0;i<h;i++)
    {
        cin>>r[i];
    }
    for(int i=0;i<w;i++)
    {
        cin>>c[i];
    }

    int free=0;

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(r[i]<0&&c[j]<0)
            {
                free++;
            }
            if((r[i]==0&&c[j]>0)||(r[i]>0&&c[j]==0))
            {

                cout<<"0";
                return 0;
            }
            r[i]--;
            c[j]--;
        }
    }
    int ans=1;
    for(int i=0;i<free;i++)
    {
        ans=(ans*2)%V;
    }
    cout<<ans<<endl;

    return 0;
}