/////////////////             ____ ___ _ _  _           *******************************
/////////////////            |  _ \_ _/ | || |          *******************************
/////////////////            | |_) | || | || |_         *******************************
/////////////////            |  __/| || |__   _|        *******************************
/////////////////            |_|  |___|_|  |_|          *******************************

#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<stack>
// #include<queue>
// #include<unordered_map>
// #include<set>
// #include<algorithm>
// #include <boost/multiprecision/ull.hpp>
// using boost::multiprecision::ull;
using namespace std;
#define ull unsigned long long
// #define ll ull
// #define ull unsigned long long
// #define ull ull
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"


ull min(ull a, ull b) {return a<b?a:b;}
ull max(ull a, ull b) {return a>b?a:b;}

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| ull_MAX    | Maximum value ull               | 2,147,483,647 (10^10)
 * |5.| ull_MIN    | Minimum value ull               |-2,147,483,648 (10^10)
*/

struct node {
    ull i=-1;
};

ull k;
string sum;
unordered_map<ull,node> previous; 

ull toi(string s){
    ull r=s[0]-'0';
    for(ull i=1;i<s.length();i++)
        r*=10,r+=s[i]-'0';
    return r;
}


string tos(ull n){
    string r;
    while(n>9){
        r.push_back(n%10+'0');
        n/=10;
    }
    r.push_back(n%10+'0');
    reverse(r.begin(),r.end());
    return r;
}

string longDivision(string number, ull divisor) 
{ 
	string ans; 

	ull idx = 0; 
	ull temp = number[idx] - '0'; 
	while (temp < divisor) 
		temp = temp * 10 + (number[++idx] - '0'); 

	while (number.size() > idx) { 
		ans += (temp / divisor) + '0'; 

		temp = (temp % divisor) * 10 + number[++idx] - '0'; 
	} 

	if (ans.length() == 0) 
		return "0"; 

	return ans; 
} 

string findDiff(string str1, string str2) 
{ 
    ull n1 = str1.length(), n2 = str2.length(); 
    string str = "";
    
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    ull carry = 0; 
    for (ull i=0; i<n2; i++) 
    { 
          
        int sub = ((str1[i]-str2[i])-carry); 
          
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        char added = (char)(sub+'0');
        if(added >='0' && added <='9')
            str+= added; 
        else 
            cout<<sub<<" "<<i<<endl; 
    } 
  
    for (ull i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
        char added = (char)(sub+'0');
        if(added >='0' && added <='9')
            str+= added; 
        else 
            cout<<sub<<" "<<i<<endl;
    } 
//   cout<<"here"<<endl;
    reverse(str.begin(), str.end()); 
    ull i=0;
    while(str[i]=='0') i++;
    // cout<<str<<endl;
    return str.substr(i);
} 

string add(string s,string p,ull m=10,char z='0'){
    string r;
    ull b=0;
    reverse(s.begin(),s.end());
    reverse(p.begin(),p.end());
    if(s.size()<p.size())s.swap(p);
    for(ull i=0;i<s.size();i++){
        if(i>=p.size()){
        r.push_back((s[i]-z+b)%m+z);
        if(s[i]-z+b>=m)b=1;
        else b=0;
        }
        else{
        r.push_back((p[i]-z+s[i]-z+b)%m+z);
        if(p[i]-z+s[i]-z+b>=m)b=1;
        else b=0;
        }
    }
    if(b>0)r.push_back(b+z);
    reverse(r.begin(),r.end());
    return r;
}


string multiplyull(string s,ull n){
    string r=tos((s[0]-'0')*n);
    for(ull i=1;i<s.length();i++){
        r.push_back('0');
        r=add(r,tos((s[i]-'0')*n));
    }
    return r;
}


string multiply(string s,string p){
    string r=multiplyull(p,s[0]-'0');
    for(ull i=1;i<s.length();i++){
        r.push_back('0');
        r=add(r,multiplyull(p,s[i]-'0'));
    }
    return r;
}

string pow(string a, ull p) {
    string ret = "1";

    while(p--) {
        ret = multiply(ret,a);
    }
    return  ret;
}

string getSum(ull a) {
    string n = to_string(a);
    if(k==1) {
        // return (n*(n+1))/2;  
        return longDivision( multiply(n, add(n,"1")) , 2);
    } else if(k==2) {
        // return (n*(n+1)*(2*n+1))/6;
        return longDivision( multiply(n, multiply(add(n,"1"), add(multiplyull(n,2), "1"))), 6);
    } else if(k==3) {
        // return (n*n*(n+1)*(n+1))/4;
        return longDivision(multiply(multiply(n,n) , multiply(add(n,"1"), add(n,"1"))) , 4);
    } else {
        // return (6 * pow(n,5) + 15* pow(n,4) + 10* pow(n,3) - (n))/30;
        string x = multiplyull(pow(n,5), 6);
        string y = multiplyull(pow(n,4), 15);
        string z = multiplyull(pow(n,3), 10);
        x = add(x,y);
        x = add(x,z);
        x = findDiff(x,n);
        return longDivision(x,30);
    }
}

bool lessThan(string a, string b) {
    if(a.size() < b.size()) {
        return true; 
    } else if(a.size()> b.size()) {
        return false;
    } else if(a==b) {
        return true;
    }
    ull i=0;

    while(a[i] == b[i]) i++;

    return a[i] < b[i];    
}

ull getNum(ull l, ull h, string tempSum, string& str) {
    // ull l=1,h=n;
    ull ret=0;

    while(l<=h) {
        ull mid = (l+h)/2;
        // cout<<mid<<" ";
        mid = previous[mid].i==-1?mid:previous[mid].i;
        mid = max(mid,l);
        string p = pow(to_string(mid),k);
        if(str[mid-1]=='0' && lessThan(multiplyull(add(p,tempSum),2), sum)) {
            ret = mid;
            l = mid+1;
        } else {
            h = mid-1;
        }
    }

    return ret;
}

void solve() {
    ull n;
    cin>>n;
    previous.clear();
    sum = getSum(n);
    // cout<<sum<<endl;

    string str= string(n,'0');

    string tempSum="0";
    ull curr=n;

    while(curr>0) {
        // cout<<curr<<endl;
        curr = min(curr, getNum(1,curr,tempSum,str));
        if(curr==0) break;
        previous[curr].i = previous[curr-1].i==-1?curr-1:previous[curr-1].i;
        str[curr-1] = '1';
        tempSum = add(tempSum, pow(to_string(curr),k));
    }
    // cout<<sum<<" "<<tempSum<<" ";
    tempSum = multiplyull(tempSum,2);
    string sol = findDiff(sum, tempSum);
    cout<<sol<<endl<<str<<endl;
}

int32_t main() {
    GO_BABY_GO;
    ull t;
    cin>>k>>t;
    // k=2;t=1;
    while(t--) {
        // n=1000000;
        solve();
    }
    return 0;
}