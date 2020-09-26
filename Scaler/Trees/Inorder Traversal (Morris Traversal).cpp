/*
Inorder Traversal
Problem Description

Given a binary tree, return the inorder traversal of its nodes values.

NOTE: Using recursion is not allowed.



Problem Constraints
1 <= number of nodes <= 105



Input Format
First and only argument is root node of the binary tree, A.



Output Format
Return an integer array denoting the inorder traversal of the given binary tree.



Example Input
Input 1:

   1
    \
     2
    /
   3
Input 2:

   1
  / \
 6   2
    /
   3


Example Output
Output 1:

 [1, 3, 2]
Output 2:

 [6, 1, 3, 2]


Example Explanation
Explanation 1:

 The Inorder Traversal of the given tree is [1, 3, 2].
Explanation 2:

 The Inorder Traversal of the given tree is [6, 1, 3, 2].

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
vector<int> Solution::inorderTraversal(TreeNode* A) {

	TreeNode *curr = A;
	vector<int> ans;

	while(curr) {
		if(curr->left) {
			TreeNode *lp = curr->left;

			while(lp->right && lp->right != curr) {
				lp = lp->right;
			}

			if(lp->right == NULL) {
				lp->right = curr;
				curr = curr->left;
			} else {
				ans.push_back(curr->val);
				lp->right = NULL;
				curr = curr->right;
			}
		} else {
			ans.push_back(curr->val);
			curr = curr->right;
		}
	}

	return ans;
}
