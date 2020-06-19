#include<bits/stdc++.h>
using namespace std;

int min(int a, int b) {
    return a<b?a:b;
}

int findMax(vector<int> plates, int start, int depth) {
    int maxim = INT_MIN;
    int index;
    for(int i=start;i<min(plates.size(),start+depth);i++) {
        if(plates[i] > maxim) {
            maxim = plates[i];
            index = i;
        }
    }
    return index;
}

int getSum(vector<vector<int> > plates, vector<int> start, int vectNum, int plateNum) {
    int sum = 0;

    for(int i=start[vectNum]; i<=plateNum; i++) {
        sum += plates[vectNum][i];
    } 

    return sum;
} 

int main() {    
    int t;cin>>t;
    int index = 1;
    while(t--) {
        int n,k,p;
        cin>>n>>k>>p;

        vector<int> start(n,0);
        vector<vector<int> > plates(n,vector<int>(k));
        for(int i=0;i<n;i++) {
            for(int j=0;j<k;j++) {
                cin>>plates[i][j];
            }
        }

        // int iterations = n*k - p;
        int sum = 0;

        while(p>0) {
            int maxim = INT_MIN;
            int indexVector,indexPlate;
            for(int i=0;i<n;i++) {
                int tempMax = findMax(plates[i],start[i],p+1);
                if(plates[i][tempMax] > maxim) {
                    maxim = plates[i][tempMax];
                    indexPlate = tempMax;
                    indexVector = i;
                }
            }
            p = p - (indexPlate - start[indexVector] + 1);
            sum += getSum(plates, start, indexVector, indexPlate);
            start[indexVector] = indexPlate+1;
            
        }

        
        // for(int i=0;i<n;i++) {
        //     for(int j=start[i];j<k;j++) {
        //         sum += plates[i][j];
        //     }
        // }

        cout<<"Case #"<<index++<<": "<<sum<<endl;

    }

    return 0;
}