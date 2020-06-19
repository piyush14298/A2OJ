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
        // l = max(l, lowerLimit);
        // h = min(h, upperLimit);
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
            if(l>upperLimit || h<lowerLimit) {
                continue;
            }
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
        // l = max(l, lowerLimit);
        // h = min(h, upperLimit);
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
        else if(l==h) {
            continue;
        }
        else if(c=='G') {
            char cR;
            cout<<midR<<endl;
            pastInts.push_back(midR);
            cin>>cR;
            pastChars.push_back(cR);
            update(pastInts, pastChars, upperLimit, lowerLimit);
            if(l>upperLimit || h<lowerLimit) {
                continue;
            }

            if(cR=='E') {
                break;
            } else if(cR=='G') {
                // auto t = getNumberSureShot(midR+1, h);
                // if(!t) t = getNumberSureShot(mid+1, midR-1);
                // return t;
                // q.push({midR+1,h});
                // clear(q);
                // cout<<"Sure shot between "<<mid+1<<" and "<<h<<endl<<endl;
                q.push({mid+1,h});
            } else {
                // bool t = getNumberSureShot(mid+1,midR-1);
                // if(!t) t = getNumberSureShot(midR+1,h);
                // if(!t) t = getNumberSureShot(l,mid-1);
                // return t;
                q.push({mid+1,midR-1});
                q.push({midR+1,h});
                q.push({l,mid-1});
            }
        } else {
            char cL;
            cout<<midL<<endl;
            pastInts.push_back(midL);
            cin>>cL;
            pastChars.push_back(cL);
            update(pastInts, pastChars, upperLimit, lowerLimit);
            if(l>upperLimit || h<lowerLimit) {
                continue;
            }

            if(cL=='E') {
                break;
            } else if(cL=='L') {
                // auto t = getNumberSureShot(l, mid-1);
                // if(!t) t = getNumberSureShot(midL+1, mid-1);
                // return t;
                // clear(q);
                // cout<<"Sure shot between "<<l<<" and "<<mid-1<<endl<<endl;
                q.push({l, mid-1});
                // q.push({midL+1, mid-1});
            } else {
                // bool t = getNumberSureShot(midL+1,mid-1);
                // if(!t) t = getNumberSureShot(l,midL-1);
                // if(!t) t = getNumberSureShot(mid+1,h);
                // return t;
                q.push({midL+1,mid-1});
                q.push({l,midL-1});
                q.push({mid+1,h});
            }
        }
    }

    return 0;
}