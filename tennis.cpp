
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
using namespace std;
#define int int64_t
#define ll int
#define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"


ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/
bool matchStart = true, service = true, advantageA=false,advantageB=false;
int scoreA=0, scoreB=0, currServer=1, serviceFault = 0,hittingTurn;
int setScoreA=0, setScoreB=0, setNumber=0;
vector<int> AScores, BScores;

bool fault(string s) {
    if((currServer==0 && setNumber%2==0) || (currServer==1 && setNumber%2==1))
        return !(s=="Q3"||s=="Q4");
    else 
        return !(s=="Q1"||s=="Q2");
}

void incrementScore(int hitter) {
    if(hitter==0) {
        if(scoreA == 40) {
            if(scoreB==40) {
                if(advantageB) {
                    advantageB=false;
                    service=true;
                    return;
                }
                else if(!advantageA) {
                    advantageA =true;
                    service=true;
                    return;
                }
            }
            setScoreA++;
            advantageA=false;
            advantageB=false;
            if((setScoreA==6 && setScoreA-setScoreB >=2) || setScoreA==7) {
                AScores.push_back(setScoreA);
                BScores.push_back(setScoreB);
                setScoreB = 0;
                setScoreA = 0;
                setNumber++;
            }
        
            scoreA = 0;
            scoreB = 0;
            matchStart = true;
        } else {
            if(scoreA==0 || scoreA==15) {
                scoreA+=15;
            } else{
                scoreA=40;
            }
        }
    } else {
        if(scoreB == 40) {
            if(scoreA==40) {
                if(advantageA) {
                    advantageA=false;
                    service=true;
                    return;
                }
                else if(!advantageB) {
                    advantageB =true;
                    service=true;
                    return;
                }
            }
            setScoreB++;
            advantageA=false;
            advantageB=false;1 
            if((setScoreB==6 && setScoreB-setScoreA >=2) || setScoreB==7) {
                AScores.push_back(setScoreA);
                BScores.push_back(setScoreB);
                setScoreB = 0;
                setScoreA = 0;
                setNumber++;
            }
            scoreA = 0;
            scoreB = 0;
            // setNumber++;
            matchStart = true;
        } else {
            if(scoreB==0 || scoreB==15) {
                scoreB+=15;
            } else{
                scoreB=40;
            }
        }
    }
    service = true;
}

bool illegal(string s, int hitter) {
    if((hitter==0 && setNumber%2==0) || (hitter==1)&&setNumber%2!=0) {
        return !(s=="Q3"||s=="Q4"||s=="H2");
    } else {
        return !(s=="Q1"||s=="Q2"||s=="H1");
    }
}

void displayScore() {
    
    if(advantageA) {
        if(currServer == 0) {
            cout<<"Advantage Server"<<endl;
        } else {
            cout<<"Advantage Receiver"<<endl;
        }
    } else if(advantageB) {
        if(currServer == 1) {
            cout<<"Advantage Server"<<endl;
        } else {
            cout<<"Advantage Receiver"<<endl;
        }
    } else if(scoreA == 40 && scoreB == 40) {
        cout<<"Deuce"<<endl; 

    } else {
        if(currServer==0)
            cout<<scoreA<<" "<<scoreB<<endl;
        else 
            cout<<scoreB<<" "<<scoreA<<endl;
    }
}

void solve() {
    string s;
    getline(cin,s);
    // cout<<serves<<endl;
    vector<string> serves;
    stringstream ss(s);
    string t;
    while(ss>>t) {
        serves.push_back(t);
    }

    for(int i=0;i<(int)serves.size();i++) {
        if(matchStart) {
            currServer = 1 - currServer;
            // cout<<"\nServer: "<<currServer<<endl;
            matchStart = false;
        }
        // cout<<serves[i]<<": ";
        if(service) {
            if(fault(serves[i])) {
                if(serviceFault == 1) {
                    // cout<<"Twice fault"<<endl;
                    incrementScore(1-currServer);
                    serviceFault = 0;
                } else {
                    // cout<<"Once fault"<<endl;
                    serviceFault++;
                    continue;
                }
            } else {
                // cout<<"Served"<<endl;
                hittingTurn = 1 - currServer;
                service = false;
                serviceFault = 0;
            }
        } else {
            if(illegal(serves[i], hittingTurn)) {
                // cout<<"illegal hit"<<endl;
                incrementScore(1-hittingTurn);
            } else {
                // cout<<"legal hit"<<endl;
                hittingTurn = 1 - hittingTurn;
            }
        }
    }
    if(matchStart) {
        currServer = 1 - currServer;
        matchStart = false;
    }
    
    if(currServer==0) {
        for(auto i=AScores.begin();i<AScores.end();i++) {
            cout<<*i<<" ";
        }
        cout<<setScoreA<<endl;
        for(auto i=BScores.begin();i<BScores.end();i++) {
            cout<<*i<<" ";
        }
        cout<<setScoreB<<endl;
    } else {
        for(auto i=BScores.begin();i<BScores.end();i++) {
            cout<<*i<<" ";
        }
        cout<<setScoreB<<endl;
        for(auto i=AScores.begin();i<AScores.end();i++) {
            cout<<*i<<" ";
        }
        cout<<setScoreA<<endl;
    }
    
    displayScore();
}

int32_t main() {
    GO_BABY_GO;
    ll t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}