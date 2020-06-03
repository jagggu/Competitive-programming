/*
BST nodes in a range
Given a binary search tree of integers. You are given a range [B, C]. Return the count of the number of nodes that lies in this range. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= B < = C <= 10^9 
For Example
Input 1:
            15
          /    \
        12      20
        / \    /  \
       10  14  16  27
      /
     8

     B = 12
     C = 20
Output 1:
    5

Input 2:
             8
            / \
           6  21
          / \
         1   4

        B = 2
        C = 20
Output 2:
    3

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

int solveHelper(TreeNode *root, int start, int end) {

	if(root == NULL) {
		return 0;
	}

	if(root->val>=start && root->val<=end) {
		return solveHelper(root->left,start,end) + solveHelper(root->right,start,end)+1;
	} else if(root->val < start) {
		return solveHelper(root->right,start,end);
	} else if(root->val > end) {
		return solveHelper(root->left,start,end);
	}
}

int Solution::solve(TreeNode* A, int B, int C) {

	return solveHelper(A,B,C);

}
