#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

double min(double x,double y)
{
    return x<y?x:y;
}

double dist(double x1,double y1,double x2,double y2)
{
    return (sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2))));
}

double find_best(vector<double> N,vector<double> M,vector<double> K,double x,double y)
{
    double mini=10000000000000;

    for(int i=0;i<K.size()-1;i+=2)
    {
        for(int j=0;j<M.size()-1;j+=2)
        {
            for(int k=0;k<N.size()-1;k+=2)
            {
                mini=min(mini,dist(K[i],K[i+1],M[j],M[j+1])+dist(M[j],M[j+1],N[k],N[k+1])+dist(N[k],N[k+1],x,y));
                // mini=min(mini,dist(K[i],K[i+1],N[k],N[k+1])+dist(N[k],N[k+1],M[j],M[j+1])+dist(M[j],M[j+1],x,y));
            }
        }
    }
    for(int i=0;i<K.size()-1;i+=2)
    {
        for(int j=0;j<N.size()-1;j+=2)
        {
            for(int k=0;k<M.size()-1;k+=2)
            {
                mini=min(mini,dist(K[i],K[i+1],N[j],N[j+1])+dist(N[j],N[j+1],M[k],M[k+1])+dist(M[k],M[k+1],x,y));
                // mini=min(mini,dist(K[i],K[i+1],N[k],N[k+1])+dist(N[k],N[k+1],M[j],M[j+1])+dist(M[j],M[j+1],x,y));
            }
        }
    }
    return mini;
}

int main()
{
    int t,n,m,k;
    double x,y;
    vector<double> ans;
    cin>>t;

    while(t--)
    {
        cin>>x>>y>>n>>m>>k;
        vector<double> N(2*n),M(2*m),K(2*k);
        int temp=2*n,i=0;
        while(temp--)
        {
            cin>>N[i];
            i++;
        }

        temp=2*m;i=0;
        while(temp--)
        {
            cin>>M[i];
            i++;
        }

        temp=2*k;i=0;
        while(temp--)
        {
            cin>>K[i];
            i++;
        }

        ans.push_back(find_best(N,M,K,x,y));
    }

    for(auto itr=ans.begin();itr<ans.end();itr++)
    {
        cout.precision(12);
        cout<<*itr<<endl;
    }

    return 0;
}