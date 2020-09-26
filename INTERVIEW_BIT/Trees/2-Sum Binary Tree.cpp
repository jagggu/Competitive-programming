/*
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K.

Return 1 to denote that two such nodes exist. Return 0, otherwise.

Notes

Your solution should run in linear time and not take memory more than O(height of T).
Assume all values in BST are distinct.
Example :

Input 1: 

T :       10
         / \
        9   20

K = 19

Return: 1

Input 2: 

T:        10
         / \
        9   20

K = 40

Return: 0


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
int Solution::t2Sum(TreeNode* A, int B) {

	if(A == NULL) {
		return 0;
	}
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;

	TreeNode *root1 = A;
	TreeNode *root2 = A;

	while(true) {

		if(root1) {
			s1.push(root1);
			root1 = root1->left;
		} else if(root2) {
			s2.push(root2);
			root2 = root2->right;
		} else if(!s1.empty() && !s2.empty()) {
			root1 = s1.top();
			root2 = s2.top();
			if(root1 == root2) {
			    s1.pop();
			    s2.pop();
			    root1 = root1->right;
			    root2 = root2->right;
			    continue;
			}

			if((root1->val+root2->val) == B) {
				return 1;
			} else if((root1->val + root2->val) > B) {
				s2.pop();
				root2 = root2->left;
				root1 = NULL;
			} else {
				s1.pop();
				root1 = root1->right;
				root2 = NULL;
			}
		} else {
			return 0;
		}
	}
}
