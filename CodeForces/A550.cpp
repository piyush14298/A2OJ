#include<iostream>
#include<string>
using namespace std;

int main()
{
    string temp;
    cin >> temp;
    int ba=0;
    int ab=0;
    int both=0;
    // cout << temp <<endl;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]=='B' && temp[i+1]=='A' && ba!=1)
        {
            ba=1;
            
            if(temp[i+2]=='B')
            {
                if(both==1)
                {
                    cout << "YES";
                    return 0;
                }
                both=1;
                ba=0;
                i++;
            }
            i++;
        }
        else if(temp[i]=='A' && temp[i+1]=='B' && ab!=1)
        {
            ab=1;

            if(temp[i+2]=='A')
            {
                if(both==1)
                {
                    cout << "YES";
                    return 0;
                }
                both =1;
                ab=0;
                i++;
            }
            i++;
        }
    }
    if((ab==1 && ba==1) || (both==1 && (ab==1||ba==1)))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }


    return 0;
}