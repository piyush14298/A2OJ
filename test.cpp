#include<bits/stdc++.h>
using namespace std;

int main() {
	unordered_set<int > s;

	for(int i=10;i>=0;i--) {
		// int a = rand()%20;
		s.insert(i);
	}

	for(auto i:s) {
		
		cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}