#include<bits/stdc++.h> 
using namespace std; 

void fillSpiral(vector<vector<int>>& mat, int m, int n, int temp[]) 
{ 
	int i, k = 0, l = 0; 


	int tIdx = 0;
	while (k < m && l < n) 
	{ 
		for (int i = l; i < n; ++i) 
			mat[k][i] = temp[tIdx++]; 
		k++; 

		for (int i = k; i < m; ++i) 
			mat[i][n-1] = temp[tIdx++]; 
		n--; 

		if (k < m) 
		{ 
			for (int i = n-1; i >= l; --i) 
				mat[m-1][i] = temp[tIdx++]; 
			m--; 
		} 

		if (l < n) 
		{ 
			for (int i = m-1; i >= k; --i) 
				mat[i][l] = temp[tIdx++]; 
			l++; 
		} 
	} 
} 


void spiralRotate(vector<vector<int>>& mat, int M, int N, int k[], int siz) 
{ 
	int temp[M*N]; 


	int m = M, n = N, s = 0, l = 0, p=0; 

	int *start = temp;  
	int tIdx = 0;
	while (s < m && l < n &&p<siz) 
	{ 
		int *end = start; 

		for (int i = l; i < n; ++i) 
		{ 
			temp[tIdx++] = mat[s][i]; 
			end++; 
		} 
		s++; 

		for (int i = s; i < m; ++i) 
		{ 
			temp[tIdx++] = mat[i][n-1]; 
			end++; 
		} 
		n--; 

		if (s < m) 
		{ 
			for (int i = n-1; i >= l; --i) 
			{ 
				temp[tIdx++] = mat[m-1][i]; 
				end++; 
			} 
			m--; 
		} 

		if (l < n) 
		{ 
			for (int i = m-1; i >= s; --i) 
			{ 
				temp[tIdx++] = mat[i][l]; 
				end++; 
			} 
			l++; 
		} 
		k[p]=k[p]%(end-start);
        // if (end-start<= k[p]) break;
		if (p%2==0) 
		{ 
            
			reverse(start, start+k[p]); 
			reverse(start+k[p], end); 
			reverse(start, end); 

			start = end; 
			p++;
		} 
		
	    else{

			int d = end-start-k[p];
			reverse(start, start+d); 
			reverse(start+d, end); 
			reverse(start, end); 

			start = end; 
			p++;
	    }
	} 

	fillSpiral(mat, M, N, temp); 
} 

int main() 
{ 
	int M, N, k; 
	cin>>M>>N;
	vector<vector<int>> mat(M, vector<int> (N));
	for(int i=0;i<M;i++){
	    for(int j=0;j<N;j++){
	        cin>>mat[i][j];
	    }
	}
	int l1,l2;
	if(N%2==1){
	    l1=(N+1)/2;
	}
	else l1=N/2;
	if(M%2==1){
	    l2=(M+1)/2;
	}
	else l2=M/2;
	int l=min(l1,l2);
	int L[l];
	for(int i=0;i<l;i++){
	    cin>>L[i];
	}
	spiralRotate(mat, M, N, L, l);
	for (int i=0; i<M; i++) 
	{ 
		for (int j=0; j<N; j++) 
			cout << mat[i][j] << " "; 
		cout << endl; 
	}
	return 0; 
} 