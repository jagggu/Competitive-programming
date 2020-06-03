/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorderTraversalHelper(TreeNode *root, vector<int> &res) {
	if(root == NULL) {
		return;
	}
	inorderTraversalHelper(root->left,res);
	res.push_back(root->val);
	inorderTraversalHelper(root->right,res);
}

vector<int> Solution::inorderTraversal(TreeNode* A) {
	vector<int> res;
	//Recursive solution
	/*
	inorderTraversalHelper(A,res);
	return res;
	*/

	//Iterative Solution

	TreeNode *root = A;

	stack<TreeNode*> s;

	while(root != NULL || !s.empty()) {

		if(root) {
			s.push(root);
			root = root->left;	
		} else {
			TreeNode *top = s.top();
			s.pop();
			res.push_back(top->val);
			if(top->right) {
				root = top->right;
			}
		}
	}
	return res;
}
