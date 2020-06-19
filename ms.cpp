#include<iostream>

struct node
{
    int l;
    int r;
    int v;
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {

        vector<node> left;
        vector<node> right;
        vector<node> all;

        int n;
        cin>>n;
        while(n--)
        {
            node temp;
            cin>>temp.l>>temp.r>>temp.v;
            all.push_back(temp);
        }
        for(auto temp: all)
        {
            if(left.isEmpty()&&!right)
        }
    }

    return 0;
}