#include<bits/stdc++.h>
using namespace std;

bool has(vector<int> i,int a,int b)
{
    bool hasa=false,hasb=false;
    for(int in=0;in<3;in++)
    {
        if(in==a)
            hasa=true;
        if(in==b)
            hasb=true;
    }

    return hasa&&hasb;
}

bool hasthree(vector<int> i,int a,int b,int c)
{
    bool hasa=false,hasb=false,hasc=false;
    for(int in=0;in<3;in++)
    {
        if(in==a)
            hasa=true;
        if(in==b)
            hasb=true;
        if(in==c)
            hasc=true;
    }
    // cout<<hasa&&(hasb||hasc);
    return hasa&&(hasb||hasc);
}

vector<int> put(vector<int> i,vector<int> ans)
{
    if(has(i,*(ans.end()-1),*(ans.end()-2)))
    {
        for(int in:i)
        {
            if(in!=*(ans.end()-1) && in!=*(ans.end()-2))
            {
                ans.push_back(in);
                return ans;
            }
        }
    }
    int t=*(ans.end()-2);
    *(ans.end()-2)=*(ans.end()-3);
    *(ans.end()-3)=t;

    for(int in:i)
    {
        if(in!=*(ans.end()-1) && in!=*(ans.end()-2))
        {
            ans.push_back(in);
            return ans;
        }
    }
    return ans;
}

bool find(vector<vector<int> > input,vector<int> i)
{
    sort(i.begin(),i.end());
    for(auto itr=input.begin();itr<input.end();itr++)
    {
        sort((*itr).begin(),(*itr).end());
        if(*itr==i)
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<int> taken(n+1,0);
    int end1=0,end2=0;
    vector<vector<int> > input(n-2,vector<int>(3,0));
    vector<vector<int> >seen;
    int temp=n-2;
    int index=0;
    while(temp--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        input[index][0]=a;
        input[index][1]=b;
        input[index][2]=c;
        taken[a]++;
        taken[b]++;
        taken[c]++;
        index++;
    }
    // for(auto in:input)
    // {
    //     for(int i:in)
    //         cout<<i<<" ";
    //     cout<<"\n";
    // }
    // return 0;

    for(int i=1;i<=n;i++)
    {
        if(taken[i]==1)
        {
            if(!end1)
                end1=i;
            else
                end2=i;
        }
    }
    // cout<<"helo";
    // return 0;
    vector<int> ans;

    while(ans.size()!=n)
    {
        if(ans.size()==0)
        {
            cout<<"hr";
            for(auto i:input)
            {
                if(count(i,i,end1))
                {
                    return 0;
                    if(i[0]==end1)
                    {
                        ans.push_back(i[0]);
                        ans.push_back(i[1]);
                        ans.push_back(i[2]);
                        return 0;
                    }
                    else if(i[1]==end1)
                    {
                        ans.push_back(i[1]);
                        ans.push_back(i[0]);
                        ans.push_back(i[2]);
                    }
                    else if(i[2]==end1)
                    {
                        ans.push_back(i[2]);
                        ans.push_back(i[1]);
                        ans.push_back(i[0]);
                    }
                    seen.push_back(i);
                }
                break;
            }
            // return 0;
        }
        else
        {
            return 0;
            for(auto i:input)
            {
                // // cout<<"helo";
                return 0;
                // // cout<<hasthree(i,*(ans.end()-1),*(ans.end()-2),*(ans.end()-3))<<endl;
                // // cout<<(find(seen,i)!=seen.end());
                // // return 0;
                // if(hasthree(i,*(ans.end()-1),*(ans.end()-2),*(ans.end()-3)) && !find(seen,i))
                // {
                //     cout<<"helo";
                //     for(int in:i)
                //     {
                //         cout<<in<<" ";
                //     }
                //     return 0;
                //     ans=put(i,ans);
                //     seen.push_back(i);
                //     break;
                // }
                for(int in:i)
                {
                    cout<<in<<" ";
                }
                cout<<"\n";
                return 0;
            }
            return 0;
        }
        // for(int i:ans)
        // {
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
    }
    
    for(int i:ans)
    {
        cout<<i<<" ";
    }

    return 0;
}

/*
5
4 3 2
2 3 5
4 1 2
*/