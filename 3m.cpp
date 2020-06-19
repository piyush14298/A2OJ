#include<iostream>
#include<queue>
using namespace std;

void buildTree(int inorder[], int levelOrder[],int n)
{
    queue<int>q1,q2;
    q1.push(levelOrder[0]);
    int k = 1,height = 0;
    while(!q1.empty() || !q2.empty()){
        if(!q1.empty()) height++;
        while(!q1.empty()){
            int val = q1.front();int i;
            for(i = 0;i<n;++i){
                if(inorder[i] == val) break;
            }
            if(i>0 && inorder[i-1] !=-1 && k<n)
                q2.push(levelOrder[k++]);
            if(i<n-1 && inorder[i+1] !=-1 && k<n) 
                q2.push(levelOrder[k++]);
            inorder[i] = -1;
            q1.pop();
        }
        if(!q2.empty()) height++;
        while(!q2.empty()){
            int val = q2.front();int i;
            for(i = 0;i<n;++i){
                if(inorder[i] == val) break;
            }
            if(i>0 && inorder[i-1] !=-1 && k<n)  
                q1.push(levelOrder[k++]);
            if(i<n-1 && inorder[i+1] !=-1 && k<n) 
                q1.push(levelOrder[k++]);
            inorder[i] = -1;
            q2.pop();
        }
    }
 cout<<height<<endl;
}

int main()
{
    int arr1[]={4,2,1,7,5,3,6};
    int arr2[]={1,2,3,4,5,6,7};
    int n=7;
    buildTree(arr1,arr2,n);

    return 0;
}