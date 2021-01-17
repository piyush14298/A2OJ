# /////////////////             ____ ___ _ _  _           *******************************
# /////////////////            |  _ \_ _/ | || |          *******************************
# /////////////////            | |_) | || | || |_         *******************************
# /////////////////            |  __/| || |__   _|        *******************************
# /////////////////            |_|  |___|_|  |_|          *******************************

# # include<bits/stdc++.h>
# // #include<iostream>
# // #include<vector>
# // #include<stack>
# // #include<queue>
# // #include<unordered_map>
# // #include<set>
# // #include<algorithm>
# # using namespace std;
# #define int unsigned long long
# #define ll int
# #define ull unsigned long long
# #define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
# #define endl "\n"


k = int(input())
t = int(input())

previous = dict() 
retString=""

def pow(a, p) :
    ret = 1;

    while p>0 :
        ret*=a
        p-=1
    
    return ret


def getSum(n,k) :
    if(k==1) :
        return (n*(n+1))/2;
    elif(k==2) :
        return (n*(n+1)*(2*n+1))/6;
    elif(k==3) :
        return (n*n*(n+1)*(n+1))/4;
    else :
        return (6 * pow(n,5) + 15* pow(n,4) + 10* pow(n,3) - (n))/30;
    


def getNum(l,  h,  tempSum, sum, retString) :
    # // int l=1,h=n;
    ret=0

    while(l<=h):
        mid = int((l+h)/2);
        # print(mid)
        # // cout<<mid<<" ";
        if(mid in previous) :
            mid = previous[mid]
        
        mid = max(mid,l);
        p = pow(mid,k);
        # print(p)
        # print(tempSum)
        # print(sum)
        # print()
        if(retString[mid-1]=='0' and p+tempSum <= sum/2) :
            # print("here")
            if(p+tempSum == sum/2): 
                return mid;
            ret = mid;
            l = mid+1;
        else :
            # print("there")
            h = mid-1;
    # print(ret)
    return ret;


def solve() :
    # int n;
    n = int(input())
    previous.clear();
    sum = getSum(n,k);

    retString= "0"*n;

    tempSum=0 
    curr=n

    while(curr>0) :
        # // cout<<curr<<endl;
        curr = min(curr, getNum(1,curr,tempSum,sum,retString));
        # print(curr)
        if(curr==0): 
            break
        if(curr-1 not in previous):
            previous[curr] = curr - 1
        else:
            previous[curr] = previous[curr-1]
        retString = retString[:curr-1]+'1'+retString[curr:];
        
        tempSum+=pow(curr,k);
    
    # // cout<<sum<<" "<<tempSum<<" ";
    sol = int(sum-2*tempSum);
    # cout<<sol<<endl<<retString<<endl;
    print(str(sol) + "\n" + retString)


while(t > 0):
    solve()
    t-=1

