/*
Binary Tree From Inorder And Postorder
Given inorder and postorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree. 
Example :
Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

 */


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* buildTreeHelper(vector<int> &inorder, vector<int> &postOrder, int start, int end, int &postIndex, unordered_map<int,int> &m) {
	if(start > end ) {
		return NULL;
	}
	   int rootPos = m[postOrder[postIndex]];
		TreeNode *root = new TreeNode(postOrder[postIndex--]);
		
		if(start == end) {
			return root;
		}
		
		root->right = buildTreeHelper(inorder,postOrder,rootPos+1,end,postIndex,m);
		root->left = buildTreeHelper(inorder,postOrder,start,rootPos-1,postIndex, m);
		
		return root;
	}


TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
	unordered_map<int,int> m;

	for(int i = 0; i<A.size(); i++) {
		m[A[i]] = i;
	}
    int n = A.size()-1;
	return buildTreeHelper(A,B,0,A.size()-1,n,m);
}
