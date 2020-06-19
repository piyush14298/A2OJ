#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int z = 0, o = 0;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n;i++){
            cin >> a[i];
        }
        for (int j = 0; j < n;j++){
            cin >> b[j];
            if(b[j]==0)
                z++;
            else
                o++;
        }
        if((z==0||o==0)&&!is_sorted(a.begin(),a.end()))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}