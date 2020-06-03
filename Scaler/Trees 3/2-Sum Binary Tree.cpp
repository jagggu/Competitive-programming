/*
2-Sum Binary Tree
Given a binary search tree T, where each node contains a positive integer, and an integer K, you have to find whether or not there exist two different nodes A and B such that A.value + B.value = K. Return 1 to denote that two such nodes exist. Return 0, otherwise. Notes
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


bool isExists(TreeNode *root, int target) {
	TreeNode *curr = root;
    
  //  cout<<target<<endl;

	while(curr != NULL) {
		if(curr->val < target) {
			curr = curr->right;
		} else if(curr->val > target) {
			curr = curr->left;
		} else {
			return true;
		//	cout<<"Found: "<<curr->val<<" "<<target<<endl;
		}
	}

	return false; 
}

int Solution::t2Sum(TreeNode* A, int B) {

	stack<TreeNode*> s;
	if(A == NULL) {
		return 0;
	}

	TreeNode *curr = A;
	while(!s.empty() || curr != NULL) {
		if(curr) {
			int val = curr->val;
			if(isExists(A,B-val) && val*2 != B) {
			   // cout<<"Target: "<<B-val<<endl;
				return 1;
			}
			s.push(curr);
			curr = curr->left;

		} else {
			TreeNode *tmp = s.top();
			s.pop();
			if(tmp->right) {
				s.push(tmp->right);
			}
			curr = tmp->right;
		}
	}

	return 0;

}
