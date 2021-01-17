#include<bits/stdc++.h>
using namespace std;

vector<int> distanceP, petrol;

unordered_map<int, unordered_map<int,int>> dp;

int calculateTime(int dist, int pet) {
    return min(dist, pet) + 5*max(dist-pet, 0);
}

int minTime(int curr, int currPetrol, int timePetrol) {
    if(curr == distanceP.size()-1) {
        return 0;
    }

    if(dp[curr][currPetrol] !=0) {
        return dp[curr][currPetrol];
    }

    int dist = distanceP[curr+1] - distanceP[curr];

    int case1 = calculateTime(dist, currPetrol);
    int case2 = calculateTime(dist, currPetrol + petrol[curr]) + timePetrol;
    return dp[curr][currPetrol] = min(case1 + minTime(curr+1, max(currPetrol-dist, 0), timePetrol), 
                                    case2 + minTime(curr+1, max(currPetrol+petrol[curr]-dist, 0), timePetrol));
}

int main() {
    int n, d, p, k;
    cin>>n>>d>>p>>k;

    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        distanceP.push_back(a);
    }

    for(int i=0;i<n;i++) {
        int a;
        cin>>a;
        petrol.push_back(a);
    }

    distanceP.push_back(d);
    petrol.push_back(0);

    int t = calculateTime(distanceP[0], p);

    cout<<t+minTime(0, max(p-distanceP[0], 0), k)<<endl;
    return 0;
}