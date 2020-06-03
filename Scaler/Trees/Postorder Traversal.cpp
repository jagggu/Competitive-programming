/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void postorderTraversalHelper(TreeNode *root, vector<int> &res) {

	if(root == NULL) {
		return;
	}

	postorderTraversalHelper(root->left,res);
	postorderTraversalHelper(root->right,res);
	res.push_back(root->val);
}

vector<int> Solution::postorderTraversal(TreeNode* A) {

	vector<int> res;
	//Recursion
	/*
	postorderTraversalHelper(A,res);
	return res;
	*/
	ListNode *curr = A;
	stack<TreeNode*> s;

	while(curr != NULL || s.empty()) {
		if(curr) {
			res.push_back(curr->val);
			s.push(curr);
			curr = curr->right;
		} else {
			TreeNode *top = s.top();
			s.pop();
			if(top->left) {
				curr = top->left;
			}
		}
	}
	reverse(res.begin(),res.end());
	return res;
}
