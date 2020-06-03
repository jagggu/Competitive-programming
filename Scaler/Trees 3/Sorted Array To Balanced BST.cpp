/*
Sorted Array To Balanced BST
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Example :
Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

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

TreeNode* sortedArrayToBSTHelper(const vector<int> &A, int start, int end) {
	if(start > end) {
		return NULL;
	}

	int mid = start + (end-start)/2;

	TreeNode *root = new TreeNode(A[mid]);

	root->left = sortedArrayToBSTHelper(A,start,mid-1);
	root->right = sortedArrayToBSTHelper(A,mid+1,end);

	return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {

	return sortedArrayToBSTHelper(A,0,A.size()-1);

}
