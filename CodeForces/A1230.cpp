#include<iostream>
using namespace std;

int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    int t=a[0]+a[1]+a[2]+a[3];
    if((t)%2!=0)
    {
        cout << "NO" <<endl;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int j=i+1;
            int sum=a[i];
            if(sum==t/2)
            {
                cout << "YES" <<endl;
                return 0;
            }
            int temp=0;
            while(j<4)
            {
                sum+=a[j+temp];
                if(sum==t/2)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                temp++;
                if(j+temp==4 || sum>t/2)
                {
                    j++;
                    temp=0;
                    sum=a[i];
                }
            }
        }
        cout << "NO" << endl;
        
    }
    

    return 0;
}

