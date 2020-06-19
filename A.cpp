#include<iostream>
#include<vector>
using namespace std;
#define ulli unsigned long long int

int main()
{
    int t,n,m;
    cin>>t;
    vector<ulli> ans(t);
    int index=0;
    while(t--)
    {
        cin>>n;
        vector<int> dls(n);
        ulli oddd=0,evend=0;
        int i=0;
        while(n--)
        {
            cin>>dls[i];
            if(dls[i]%2==0)
                evend++;
            else
                oddd++;
            
            i++;
        }

        cin>>m;
        vector<int> jls(m);
        ulli evenj=0,oddj=0;
        i=0;
        while(m--)
        {
            cin>>jls[i];
            if(jls[i]%2==0)
                evenj++;
            else
                oddj++;
            
            i++;
        }

        ulli anss=(evend*evenj)+(oddd*oddj);

        // for(int c1:dls)
        // {
        //     for(int c2:jls)
        //     {
        //         if((c1+c2)%2==0)
        //         {
        //             anss++;
        //         }
        //     }
        // }
        ans[index]=anss;
        index++;
    }
    for(ulli i:ans)
    {
        cout<<i<<endl;
    }

    return 0;
}
/*3
3
1 3 2
2
0 3
1
1
1
1
1
2
1
1*/