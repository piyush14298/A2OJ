/* program to construct tree using inorder 
and levelorder traversals */
#include <iostream> 
#include<set> 
using namespace std; 

/* A binary tree node */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

Node* makeNode(int data){ 
	Node* newNode = new Node(); 
	newNode->key = data; 
	newNode->right = newNode->right = NULL; 
	return newNode; 
} 

// Function to build tree from given 
// levelorder and inorder 
Node* buildTree(int inorder[], int levelOrder[], 
				int iStart, int iEnd, int n) 
{ 
	if (n <= 0) return NULL; 

	// First node of level order is root 
	Node* root = makeNode(levelOrder[0]); 

	// Search root in inorder 
	int index = -1; 
	for (int i=iStart; i<=iEnd; i++){ 
		if (levelOrder[0] == inorder[i]){ 
			index = i; 
			break; 
		} 
	} 

	// Insert all left nodes in hash table 
	set<int> s; 
	for (int i=iStart;i<index;i++) 
		s.insert(inorder[i]); 
	
	// Separate level order traversals 
	// of left and right subtrees. 
	int lLevel[s.size()]; // Left 
	int rLevel[iEnd-iStart-s.size()]; // Right 
	int li = 0, ri = 0; 
	for (int i=1;i<n;i++) { 
		if (s.find(levelOrder[i]) != s.end()) 
			lLevel[li++] = levelOrder[i]; 
		else
			rLevel[ri++] = levelOrder[i];		 
	} 

	// Recursively build left and right 
	// subtrees and return root. 
	root->left = buildTree(inorder, lLevel, 
				iStart, index-1, index-iStart); 
	root->right = buildTree(inorder, rLevel, 
				index+1, iEnd, iEnd-index); 
	return root; 

} 

/* Utility function to print inorder 
traversal of binary tree */
void printInorder(Node* node) 
{ 
	if (node == NULL) 
	return; 
	printInorder(node->left); 
	cout << node->key << " "; 
	printInorder(node->right); 
} 

int minDepth(Node *root) 
{ 
    // Corner case. Should never be hit unless the code is  
    // called on root = NULL 
    if (root == NULL) 
        return 0; 
  
    // Base case : Leaf Node. This accounts for height = 1. 
    if (root->left == NULL && root->right == NULL) 
    return 1; 
  
    // If left subtree is NULL, recur for right subtree 
    if (!root->left) 
    return minDepth(root->right) + 1; 
  
    // If right subtree is NULL, recur for left subtree 
    if (!root->right) 
    return minDepth(root->left) + 1; 
  
    return min(minDepth(root->left), minDepth(root->right)) + 1; 
} 

int minheight(int input1[],int input2[],int input3)
{
    Node *root = buildTree(input1, input2, 0, input3 - 1, input3);
    return minDepth(root);
}

// Driver Code 
int main() 
{ 
	int in[] = {4,2,1,7,5,3,6}; 
	int level[] = {1,2,3,4,5,6,7}; 
	int n = sizeof(in)/sizeof(in[0]); 
    int result = minheight(in,level,n);
	

	/* Let us test the built tree by 
	printing Insorder traversal */
	// cout << "Inorder traversal of the "
	// 		"constructed tree is \n"; 
	// printInorder(root); 

    cout<<result;
	return 0; 
} 

