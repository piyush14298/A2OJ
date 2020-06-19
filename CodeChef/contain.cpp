#include<bits/stdc++.h>
using namespace std;
// #define int int64_t
#define ll long long int
// #define ull unsigned long long
#define GO_BABY_GO ios::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,a,b) for(ll i=a;i<=b;i++)
// #define vi vector<int>
// #define vll vector<ll>
// #define vull vector<ull>
#define endl "\n"
// #define int int64_t

ll min(ll a, ll b) {return a<b?a:b;}
ll max(ll a, ll b) {return a>b?a:b;}


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
set<point> convexHull(vector<point> points, vector<vector<point> >& hulls) { 
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
        } 
        p=q;
  
    } while (p != l);  
    hulls.push_back(hull);
    return ret;
} 


// Returns true if the point p lies strictly inside the polygon with n vertices 
bool isInside(point p, vector<point>& polygon) { 
    int n = polygon.size();
    // There must be at least 3 vertices in polygon[] 
    if (n < 3)  return false; 
  
    // Count intersections of the above line with sides of polygon 
    int countL = 0, countR = 0, i = 0;
    do { 
        int next = (i+1)%n; 

        if(orientation(polygon[i], polygon[next], p)!=2) {
            return false;
        }
        i = next; 
    } while (i != 0); 

    return true;
} 

vector<point> checkT(vector<point> points, vector<vector<point> >& hulls) {
    auto hull = convexHull(points,hulls);
    
    // Print hull
    // cout<<"HULL: \n";
    // for(auto i:hull) {
    //     cout<<i.x<<" "<<i.y<<"......";
    // }
    // cout<<endl<<endl;

    // Get points inside the hull
    set<point> pointInside(points.begin(), points.end());
    for(auto i:hull) {
        pointInside.erase(i);
    }
    // Print points inside Hull
    // cout<<"Points inside: \n";
    // for(auto i:pointInside) {
    //     cout<<i.x<<" "<<i.y<<"......";
    // }
    // cout<<endl;

    if(pointInside.size()==0) {
        return {};
    }

    // create hull for inner points
    vector<point> pass(pointInside.begin(), pointInside.end());
    // pointInside.clear();/
    return pass;
}

int indexOf(point p, vector<vector<point> >& hulls) {
    int l=0, h=hulls.size()-1;
    int ans=-1;

    while(l<=h) {
        int mid = l + (h-l)/2;
        
        if(isInside(p,hulls[mid])) {
            ans=mid;
            l=mid+1;
        } else {
            h=mid-1;
        }
    }

    return ans+1;
}

void solve() {
    int n, q;
    cin>>n>>q;
    
    set<point> input;
    fo(i,0,n-1) {
        ll x,y;
        cin>>x>>y;
        point nn;
        nn.x = x;
        nn.y = y;
        input.insert(nn);
    }
    vector<point> points(input.begin(), input.end());
    vector<vector<point> > hulls;
    while(points.size() >=3)
        points = checkT(points, hulls);

    while (q--)
    {
        ll x,y;
        cin>>x>>y;
        point p = {x,y};
        cout<<indexOf(p,hulls)<<endl;
    }
    
}

int main() {
    GO_BABY_GO;
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

/*
Tests
1
12 10
-1000000000 -1000000000         
-1000000000 0
-1000000000 1000000000
1000000000 0
1000000000 1000000000
0 1000000000
1000000000 -1000000000
0 -1000000000
50 30
1000 22494393
43232 14243423
231232123 1231233

2
6 6
0 0
1 1
2 2
3 3
4 0
2 1
0 0
1 1
2 2
3 3
4 0
2 1
4 4
0 0
2 1
4 2
6 3
0 0
2 1
4 2
6 3

1
10 0 
0 -4
1 -7
2 -5
3 -3
4 -1
5 -4
6 -5
7 -3
8 -6
9 -2

1
13 5
0 0
1 0
2 0
3 0
0 1
0 2
0 3
-1 0
-2 0
-3 0
0 -1
0 -2
0 -3

1
12 4
0 0
0 5
5 0
1 1
1 4
4 1
4 4
5 5
2 2
2 3
3 2
3 3

*/
