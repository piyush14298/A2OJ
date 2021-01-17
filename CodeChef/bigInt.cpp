#include<bits/stdc++.h>
using namespace std;

// A function to perform division of large numbers 
string longDivision(string number, int divisor) 
{ 
	// As result can be very large store it in string 
	string ans; 

	// Find prefix of number that is larger 
	// than divisor. 
	int idx = 0; 
	int temp = number[idx] - '0'; 
	while (temp < divisor) 
		temp = temp * 10 + (number[++idx] - '0'); 

	// Repeatedly divide divisor with temp. After 
	// every division, update temp to include one 
	// more digit. 
	while (number.size() > idx) { 
		// Store result in answer i.e. temp / divisor 
		ans += (temp / divisor) + '0'; 

		// Take next digit of number 
		temp = (temp % divisor) * 10 + number[++idx] - '0'; 
	} 

	// If divisor is greater than number 
	if (ans.length() == 0) 
		return "0"; 

	// else return ans 
	return ans; 
} 


string minus(string x,string y){
    bool jjjj=false;
    if(x.length()<y.length() || (x.length()==y.length() && x<y))
        swap(x,y),jjjj=true;
    if(y.length()==0)
        return x;
    int u=y[y.length()-1]-'0',p=x[x.length()-1]-'0';
    string t;
    if(p<u){
        p+=10;
        for(int i=x.length()-2;i>=0;i--)
        if(x[i]>'0'){
        x[i]--;
        break;
        }
        else
        x[i]+=9;
    }
}


int toi(string s){
    int r=s[0]-'0';
    for(int i=1;i<s.length();i++)
        r*=10,r+=s[i]-'0';
    return r;
}


string tos(int n){
    string r;
    while(n>9){
        r.push_back(n%10+'0');
        n/=10;
    }
    r.push_back(n%10+'0');
    reverse(r.begin(),r.end());
    return r;
}


string sum(string s,string p,int m=10,char z='0'){
    string r;
    int b=0;
    reverse(s.begin(),s.end());
    reverse(p.begin(),p.end());
    if(s.size()<p.size())s.swap(p);
    for(int i=0;i<s.size();i++){
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


string multiplyint(string s,int n){
    string r=tos((s[0]-'0')*n);
    for(int i=1;i<s.length();i++){
        r.push_back('0');
        r=sum(r,tos((s[i]-'0')*n));
    }
    return r;
}


string multiply(string s,string p){
    string r=multiplyint(p,s[0]-'0');
    for(int i=1;i<s.length();i++){
        r.push_back('0');
        r=sum(r,multiplyint(p,s[i]-'0'));
    }
    return r;
}

int main() {
    cout<<longDivision( sum("100000000000000", "1000000000000000000000000"), 2)<<endl;

    return 0;
}