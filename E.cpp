#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,p;
    cin>>n>>p;
    vector<int> times(n);
    int index=0;
    int temp=n;
    vector<int> result(n);
    vector<int> waiting(n);
    while(temp--)
    {
        cin>>times[index];
        index++;
    }
    int time=0;

    return 0;
}