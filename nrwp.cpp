#include<bits/stdc++.h>
using namespace std;

struct Node {
    int x,y,val;
};

bool evaluate(vector<vector<int> >& mat, Node i, map<pair<int,int>,int>& h) {
    int value = i.val;
    // cout<<value<<" ";
    int x = i.x, y = i.y;
    int psum, nsum;
    //positive sum
    psum = value*mat[x][y] + value*(h[make_pair(x-1,y)]+h[make_pair(x+1,y)]+h[make_pair(x,y-1)]+h[make_pair(x,y+1)]);
    // cout<<psum<<" ";
    return psum>0;

}

void f() {
    int h,w,n;
    cin>>h>>w>>n;
    vector<vector<int> > mat(h,vector<int>(w));
    vector<Node> particles(n);
    map<pair<int,int>,int> hash;
    vector<int> sign(n);
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            cin>>mat[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        int x,y,p;
        cin>>x>>y>>p;
        x--;y--;
        hash[make_pair(x,y)] = p;
        Node temp = {x,y,p};
        particles[i] = temp;
    }

    int ret = 0;
    // cout<<particles.size()<<endl;
    // for(int i=0;i<n;i++) {
    //     cout<<particles[i].val<<endl;
    // }

    for(int i=0;i<n;i++) {
        auto t = evaluate(mat,particles[i],hash);
        // cout<<t<<endl;
        if(t) {
            sign[i]=1;
        } else {
            // cout<<"here"<<endl;
            sign[i]=-1;
        }
        hash[make_pair(particles[i].x, particles[i].y)]*=sign[i];
    }
    int e = 0 ;
    for(int i=0;i<n;i++) {
        int value = particles[i].val;
        int x = particles[i].x, y= particles[i].y;
        ret+= (value*sign[i])*mat[x][y];
        e+= (value*sign[i])*(hash[make_pair(x-1,y)]+hash[make_pair(x+1,y)]+hash[make_pair(x,y-1)]+hash[make_pair(x,y+1)]);
    }
    ret+=(e/2);
    cout<<ret<<endl;
    for(auto i:sign) {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        f();
    }

    return 0;
}