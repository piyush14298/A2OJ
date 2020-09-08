#include<bits/stdc++.h>
using namespace std;

struct point {
    int x,y;

    bool operator < (point& p) {
        if(x==p.x) return y<p.y;
        return x<p.x;
    }

    bool operator == (point& p) {
        return x==p.x && y==p.y;
    }
};

int orientation(point a, point b, point c) {
    int ret = a.x*(b.y-c.y) + b.x*(c.y-a.y) +c.x*(a.y-b.y);
    return ret;
}

void convexHull(vector<point>& p) {
    if(p.size()<=2) {
        return;
    }
    int n = p.size();

    sort(p.begin(), p.end());

    point p1 = p[0], p2 = p[n-1];

    stack<point> up,down;
    up.push(p1);down.push(p1);

    for(int i=1;i<n-1;i++) {
        if(orientation(p1,p[i],p2) <= 0) {
            while(orientation(p1,up.top(),p[i])>0) {
                up.pop();
            }
            up.push(p[i]);
        } else {
            while(orientation(p1,down.top(),p[i]) < 0) {
                down.pop();
            }
            down.push(p[i]);
        }
    }
    vector<point> ret;
    ret.push_back(p2);
    while(up.size()>0) {
        ret.push_back(up.top());
        up.pop();
    }
    while(down.size()>0) {
        ret.push_back(down.top());
        down.pop();
    }
    sort(ret.begin(), ret.end());
    auto it = unique(ret.begin(), ret.end());
    ret.resize(distance(ret.begin(),it));

    swap(p,ret);
}

int  main() {
    int n;
    cin>>n;
    vector<point> p(n);
    for(int i=0;i<n;i++) {
        cin>>p[i].x>>p[i].y;
    }

    convexHull(p);

    for(auto i:p) {
        cout<<i.x<<" "<<i.y<<endl;
    }

    return 0;
}