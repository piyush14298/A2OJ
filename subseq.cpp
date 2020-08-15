//Frustration is the key to Success
// %0|%0 never mess with 5 character.
#include<bits/stdc++.h>
using namespace std;
void solve()
{
	string arr;
    cin>>arr;
    int n = arr.size(), ans=1;
	int T[n];        //create a temp array for pre-processing to calculate answer.
	for(int i=0;i<n;i++)
	T[i]=1;         //here we initalise it with 1 bcz every element is itself a non deceasing subsequence
	for(int i=1;i<n;i++)    //here we run two loop one loop start from index 1 and other loop start from  index 0
		{
		for(int j=0;j<i;j++)
			{                        // this loop will check if we found a element that is greater than the previous element 
			  if(arr[i] >= arr[j])
				{
				T[i]=max(T[i],T[j]+1);   //if we found such element then we will update our temp array
				ans=max(ans,T[i]);      // this will store the length of the longest non-decreasing subsequence so far.
				}
			}
	}
	//for(int i=0;i<n;i++)    //uncomment this to print the temp array
	//cout<<T[i]<<" ";
	// cout<<ans<<endl;

    int extra = n-ans;
    // cout<<ans<<endl;
    string ret="";
    int q=extra/(ans-1);
    while(q--) {
        ret+=string(ans-2,'0')+'1';
    }
    int e = extra%(ans-1);
    if(e)ret+=string(e-1,'0')+'1';
    ret+=string(ans,'0');
    cout<<ret<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}