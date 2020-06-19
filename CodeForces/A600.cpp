#include<iostream>
#include<string>
using namespace std;

int main()
{
    char sc=char(59);
    char co=char(44);
    string s,a,b;
    string sub[1000000];
    int count=0;
    cin >> s;
    for(char c:s)
    {
        if(c==sc || c==co)
        {
            count++;
            continue;
        }
        sub[count]+=c;

    }
    // cout << sub[0]<<endl<<sub[1]<<endl<<sub[2]<<endl<<sub[3]<<endl;
    
    for(int i=0;i<=count;i++)
    {
        string subs=sub[i];
        if(subs.empty())
        {
            if(b.empty())
            {
                b+="\"";
                b+=subs;
            }
            else
            {
                b+=",";
                b+=subs;
            }
            continue;
        }
        try
        {
            
            // int num=stoi(subs);
            int temp=1;
            for(char c:subs)
            {
                if(c!='0'&&c!='1'&&c!='2'&&c!='3'&&c!='4'&&c!='5'&&c!='6'&&c!='7'&&c!='8'&&c!='9')
                {
                    temp=0;
                }
            }
            
            // cout << temp <<"  "<<subs.length()<<"  "<<"  "<<num<<endl;
            if(subs[0]=='0'&&subs.length()>1)
            {
                temp=0;
            }
            if(temp!=0)
            {
                if(a.empty())
                {
                    a+="\"";
                    a+=subs;
                }
                else
                {
                    a+=",";
                    a+=subs;
                }
                continue;
            }
            if(b.empty())
            {
                b+="\"";
                b+=subs;
            }
            else
            {
                b+=",";
                b+=subs;
            }
            
            continue;
        }
        catch(exception a)
        {
            if(b.empty())
            {
                b+="\"";
                b+=subs;
            }
            else
            {
                b+=",";
                b+=subs;
            }
            
            continue;
        }
        
    }
    a+="\"";
    b+="\"";
    string test="\"";
    // cout << test<<endl<<endl;
    if(!a.compare(test))
    {
        // cout << "A is empty"<<endl;
        a="-";
    }
    if(!b.compare(test))
    {

        b="-";
    }
    cout << a << endl << b << endl;

    return 0;
}