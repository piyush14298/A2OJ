
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

struct point { 
    ll x, y; 

    bool operator<(const point& rhs) const {
    if(x == rhs.x) return y<rhs.y;
    return x < rhs.x; 
    }

    bool operator==(const point& rhs) const {
        return x==rhs.x && y==rhs.y;
    }
}; 

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

int orientation(point p, point q, point r) { 
    ll val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 

    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

ll distance(point a, point b) {
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
  
// Returns convex hull of a set of n points. 
vector<point> convexHull(vector<point> points) { 
    int n = points.size();
    // There must be at least 3 points 
    if (n < 3) return {}; 
  
    // Initialize Result 
    vector<point> hull; 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
     
    int p = l, q; 
    set<point> ret;
    do
    { 
        hull.push_back(points[p]); 
        ret.insert(points[p]);
        set<point> temp;
        q = (p+1)%n; 

        for (int i = 0; i < n; i++) 
        { 
            int o = orientation(points[p], points[i], points[q]);
            if (o == 2) {
                temp.clear();
                q=i;
                temp.insert(points[i]);
            }
            else if(o==0) {
                temp.insert(points[i]);
            }
        } 
        
        for(auto i:temp) {
            ret.insert(i);
            hull.push_back(i);
        } 
        p=q;
  
    } while (p != l);  
    return hull;
} 

void solve() {
    int n;
    cin>>n;
    vector<point> points(n);
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        points[i].x=x;
    }
    for(int i=0;i<n;i++) {
        int y;
        cin>>y;
        points[i].y = y;
    }

    auto hull = convexHull(points);

    sort(hull.begin(), hull.end());
    set<point> ret;
    for(auto i: hull) {
        ret.insert(i);
    }

    for(auto i: ret) {
        cout<<i.x<<" "<<i.y<<endl;
    }

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