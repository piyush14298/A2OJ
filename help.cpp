#include<bits/stdc++.h>
using namespace std;

int main() {
    int minMarks, s, n;
    cin>>minMarks>>s>>n;

    vector<int> currMarks(s);
    for(int i=0;i<s;i++) {
        cin>>currMarks[i];
    }

    vector<vector<int>> questions(n, vector<int>(3));
    for(int i=0;i<n;i++) {
        cin>>questions[i][0]>>questions[i][1];
        questions[i][2] = i; // store the index of the question
    }

    // sort according to condition given
    sort(questions.begin(), questions.end(), [](vector<int> a, vector<int> b) {
        if(a[1] == b[1]) {
            return ((float)a[0]/a[1]) < ((float)b[0]/b[1]);
        } else {
            return a[1] > b[1];
        }
    });

    for(int i=0;i<s;i++) {
        vector<int> questionsToAnswer;
        int q=0; // question number to attempt
        while(currMarks[i] < minMarks) {
            currMarks[i]+=questions[q][0];
            questionsToAnswer.push_back(questions[q][2]);
            q++;
        }
        sort(questionsToAnswer.begin(), questionsToAnswer.end());
        cout<<questionsToAnswer.size()<<" ";
        for(int k=0;k<questionsToAnswer.size();k++) {
            cout<<questionsToAnswer[k]+1<<" ";
        }
        cout<<endl;
    }

    return 0;
}