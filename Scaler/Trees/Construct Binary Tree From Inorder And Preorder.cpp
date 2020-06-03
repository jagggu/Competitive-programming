/*
Construct Binary Tree From Inorder And Preorder
Given preorder and inorder traversal of a tree, construct the binary tree.
 Note: You may assume that duplicates do not exist in the tree. 
Example :
Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

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

TreeNode* buildTreeHelper(vector<int> &preOrder, vector<int> &inOrder, int start, int end,int &preIndex, unordered_map<int,int> &m) {
	if(start > end) {
		return NULL;
	}

	int rootPos = m[preOrder[preIndex]];

	TreeNode *root = new TreeNode(preOrder[preIndex++]);
	if(start == end) {
		return root;
	}

	root->left = buildTreeHelper(preOrder,inOrder,start,rootPos-1,preIndex,m);

	root->right = buildTreeHelper(preOrder,inOrder,rootPos+1,end,preIndex,m);

	return root;

}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {

	int n = A.size();

	unordered_map<int,int> m;
	for(int i = 0;i<n;i++) {
		m[B[i]] = i;
	}
	int tmp = 0;
	return buildTreeHelper(A,B,0,n-1,tmp,m);
}
