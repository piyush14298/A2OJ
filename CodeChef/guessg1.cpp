#include<bits/stdc++.h>
using namespace std;

void clear( queue<pair<int,int> > &q )
{
   queue<pair<int,int> > empty;
   swap( q, empty );
}

void update(vector<int>& pastInts, vector<char>& pastChars, int &upperLimit, int& lowerLimit) {
    // cout<<"\nCurrent==> "<<lowerLimit<<"---"<<upperLimit<<endl;
    int n = pastChars.size();
    if(pastChars.size()>=2) {
        if(pastChars[n-1]=='L' && pastChars[n-2] == 'L') {
            upperLimit = min(upperLimit, max(pastInts[n-2],pastInts[n-1]));
        }
        if(pastChars[n-1]=='G' && pastChars[n-2] == 'G') {
            lowerLimit = max(lowerLimit, min(pastInts[n-2],pastInts[n-1]));
        }
    }

    bool change = true;

    while(change) {
        change = false;
        for(int i=0;i<n;i++) {
            if(pastInts[i] <= lowerLimit && pastChars[i]=='L') {
                
                if(i<n-1 && pastChars[i+1] == 'G') {
                    if(lowerLimit < pastInts[i+1]) {
                        lowerLimit = pastInts[i+1];
                        change = true;
                    }
                } else if(i<n-1 && pastChars[i+1] == 'L') {
                    if(upperLimit > pastInts[i+1]) {
                        upperLimit = pastInts[i+1];
                        change = true;
                    }
                }

                if(i && pastChars[i-1] == 'G') {
                    if(lowerLimit < pastInts[i-1]) {
                        lowerLimit = pastInts[i-1];
                        change = true;
                    }
                } else if(i && pastChars[i-1] == 'L') {
                    if(upperLimit > pastInts[i-1]) {
                        upperLimit = pastInts[i-1];
                        change = true;
                    }
                }
            }
            else if(pastInts[i] >= upperLimit && pastChars[i]=='G') {
                
                if(i<n-1 && pastChars[i+1] == 'G') {
                    if(lowerLimit < pastInts[i+1]) {
                        lowerLimit = pastInts[i+1];
                        change = true;
                    }
                } else if(i<n-1 && pastChars[i+1] == 'L') {
                    if(upperLimit > pastInts[i+1]) {
                        upperLimit = pastInts[i+1];
                        change = true;
                    }
                }

                if(i && pastChars[i-1] == 'G') {
                    if(lowerLimit < pastInts[i-1]) {
                        lowerLimit = pastInts[i-1];
                        change = true;
                    }
                } else if(i && pastChars[i-1] == 'L') {
                    if(upperLimit > pastInts[i-1]) {
                        upperLimit = pastInts[i-1];
                        change = true;
                    }
                }
            }
        }
    }
    // cout<<"New==> "<<lowerLimit<<"---"<<upperLimit<<endl<<endl;
    
}

int main() {
    int n;
    cin>>n;
    queue<pair<int,int> > q;
    q.push({1,n});
    int upperLimit = n;
    int lowerLimit = 1;
    vector<int> pastInts;
    vector<char> pastChars;
    while(!q.empty()) {
        auto t = q.front();q.pop();
        
        int l = t.first, h=t.second;
        if(l>h || l>upperLimit || h<lowerLimit) {
            continue;
        } else if(l==h) {
            cout<<l<<endl;
            pastInts.push_back(l);
            char c;
            cin>>c;
            pastChars.push_back(c);
            if(c=='E') {
                return 0;
            }
            update(pastInts, pastChars, upperLimit, lowerLimit);
            continue;
        } else if(l+1==h) {
            char t;
            cout<<l<<endl;
            pastInts.push_back(l);
            cin>>t;
            if(t=='E') {
                return 0;
            }
            pastChars.push_back(t);
            update(pastInts, pastChars, upperLimit, lowerLimit);
            if(l>upperLimit || h<lowerLimit) {
                continue;
            }
            if(t!='E') {
                cout<<h<<endl;
                pastInts.push_back(l);
                cin>>t;
                if(t=='E') {
                    return 0;
                }
                pastChars.push_back(t);
                update(pastInts, pastChars, upperLimit, lowerLimit);
                if(l>upperLimit || h<lowerLimit) {
                    continue;
                }
                
            }
            if(t=='E') {
                break;
            }
            continue;
        }
        if(l<lowerLimit) {
            l=lowerLimit;
        }
        if(h>upperLimit) {
            h = upperLimit;
        }
        int mid = l + (h-l)/2;
        int midL = l + (mid-l)/2;
        int midR = mid + (h-mid)/2;

        cout<<mid<<endl;
        pastInts.push_back(mid);
        char c;
        cin>>c;
        pastChars.push_back(c);
        update(pastInts, pastChars, upperLimit, lowerLimit);
        if(l>upperLimit || h<lowerLimit) {
            continue;
        }

        if(c=='E') {
            break;
        }
        q.push({l,mid-1});
        q.push({mid+1,h});
    }

    return 0;
}