#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define ulli unsigned long long int

ulli to_dec(ulli x)
{
    int i=0;
    int ans=0;
    while(x)
    {
        ans+=(x%10)*pow(2,i);
        x=x/10;
        i++;
    }
    return ans;
}

int main()
{
    int t,n;
    cin>>t;
    vector<int> anss;
    while(t--)
    {
        cin>>n;
        vector<ulli> nums(n,0);int i=0;
        while(n--)
        {
            ulli temp;
            cin>>temp;
            nums[i]=to_dec(temp);
            i++;
        }
        ulli ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        anss.push_back(__builtin_popcount(ans));
    }

    for(auto itr=anss.begin();itr<anss.end();itr++)
    {
        cout<<*itr<<endl;
    }

    return 0;

}
/*
2
3
1110001101
1010101011
0000000011
3
1110001101
1010101011
0000000011
*/