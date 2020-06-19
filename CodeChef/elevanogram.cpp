#include <bits/stdc++.h> 
using namespace std; 

bool findcomb(vector<int> arr,int index,vector<int> data,int n,int i)
{
    if(data.size()==n)
    {
        int sum1=accumulate(arr.begin(),arr.end(),0);
        int sum2=accumulate(data.begin(),data.end(),0);
        if((sum2-(sum1-sum2))%11==0)
        {
            return true;
        }
        return false;
    }
    if (i >= arr.size()) 
		return false; 
    bool t2=findcomb(arr,index,data,n,i+1);
    if(t2)
        return true;
	data.push_back(arr[i]); 

    bool t1=findcomb(arr,index+1,data,n,i+1);
    if(t1)
        return true;

    
    
    return false;

}

bool exists(vector<int> arr)
{
    int n=arr.size()%2==0?arr.size()/2:(arr.size()+1)/2;
    vector<int> data;

    return findcomb(arr,0,data,n,0);
}

int main()
{
    int t,n;
    cin>>t;
    vector<bool> finalans;
    while(t--)
    {
        vector<int> ans;
        for(int i=1;i<=9;i++)
        {
            int te;
            cin>>te;
            if(te)
            {
                while(te--)
                    ans.push_back(i);
            }
        }
        if(exists(ans))
            finalans.push_back(true);
        else
        {
            finalans.push_back(false);
        }
        

    }

    for(int i=0;i<finalans.size();i++)
    {
        cout<<"Case #"<<i+1<<": ";
        if(finalans[i])
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
    

    return 0;
} 

