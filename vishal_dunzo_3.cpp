#include<bits/stdc++.h>
using namespace std;

// int helper(vector<vector<int>> mat) {
//     int ret=0;
//     int n = mat.size();

//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//             if(i && j && mat[i][j]) {
//                 mat[i][j] += min({mat[i-1][j], mat[i-1][j-1], mat[i][j-1]});
//             } 

//             ret = max(ret, mat[i][j]);
//         }
//     }

//     return ret;
// }

// void fill(vector<string>& mat, int i, int j, char c) {
//     int n = mat.size();
//     if(i<0 || i>=n || j<0 || j>=mat[i].size() || mat[i][j] != c) {
//         return;
//     }
//     mat[i][j] = '.';
//     fill(mat, i-1, j, c);
//     fill(mat, i+1, j, c);
//     fill(mat, i, j-1, c);
//     fill(mat, i, j+1, c);
// }

// int helper(vector<string> mat) {
//     int ret=0;
//     int n = mat.size();

//     for(int i=0;i<n;i++) {
//         for(int j=0;j<mat[i].size();j++) {
//             if(mat[i][j] != '.') {
//                 ret++;
//                 fill(mat, i, j, mat[i][j]);
//             }
//         }
//     }

//     return ret;
// }

bool isNum(char a) {

    if(a>='0' && a<='9') {
        return true;
    }

    return false;
}



void helper(string arr[], int size) {
    double perc=0;
    vector<vector<string>> dirNames;

    for(int i=0;i<size;i++) {
        string name, rating, director, length="", watched="";
        int limit=arr[i].size();
        int dirLimit;
        // for(int j=arr[i].size()-1;j--;j>=0) {
        //     if(arr[i][j] == ' ') {
        //         if(watched=="") {
        //             watched = arr[i].substr(j+1);
        //             limit = j;
        //         } else if(length=="") {
        //             length = arr[i].substr(j+1, limit-j-1);
        //         } else {
        //             dirLimit=j;
        //             break;
        //         }
        //     }
        // }
        int j=arr[i].size()-1;
        while(arr[i][j] != ' ')
            j--;
        watched = arr[i].substr(j+1);
        arr[i] = arr[i].substr(0, j);
        j--;
        while(arr[i][j] != ' ') 
            j--;
        length = arr[i].substr(j+1);
        arr[i] = arr[i].substr(0, j);

        limit=0;
        while(! isNum(arr[i][limit])) {
            limit++;
        }
        name = arr[i].substr(0, limit);
        limit+=2;
        director = arr[i].substr(limit);

        watched = watched.substr(0, watched.size()-3);
        length = length.substr(0, length.size()-3);

        cout<<name<<endl<<director<<endl<<dirLimit<<endl<<length<<endl<<watched<<endl<<endl;

        double dWatched = stoi(watched);
        double dLength = stoi(length);
        
        double tempPerc = dWatched/dLength;

        cout<<dWatched<<" "<<dLength << " " << tempPerc <<" "<<perc<<endl<<endl;
        if(tempPerc > perc) {
            dirNames.clear();
            dirNames.push_back({director, name});
            perc = tempPerc;
        } else if(tempPerc==perc) {
            dirNames.push_back({director, name});
        }
    }

    sort(dirNames.begin(), dirNames.end());

    cout<<dirNames[0][1]<<endl<<dirNames[0][0]<<endl;
}

int main() {
    string arr[2];
    arr[0] = "ABc add ada 8 chosen adasa 10min 5min";
    arr[1] = "Bas  adaa  7 not adaa 10min 7min";
    helper(arr, 2);
    return 0;
}