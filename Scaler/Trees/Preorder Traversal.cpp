/*
Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,2,3]. Using recursion is not allowed.

*/



/*
Preorder Traversal
Given a binary tree, return the preorder traversal of its nodes' values. Example : Given binary tree
   1
    \
     2
    /
   3
return [1,2,3]. Using recursion is not allowed.

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

void preorderTraversalHelper(TreeNode *root, vector<int> &res) {

	if(root == NULL) {
		return;
	}
	res.push_back(root->val);
	preorderTraversalHelper(root->left,res);
	preorderTraversalHelper(root->right,res);
}

vector<int> Solution::preorderTraversal(TreeNode* A) {

	vector<int> res;
	//Recursion
	/*
	preorderTraversalHelper(A,res);

	return res;
	*/

	//Iterative
	stack<TreeNode*> s;
	TreeNode *curr = A;
	
	while(curr != NULL || !s.empty()) {

		if(curr) {
			res.push_back(curr->val);
			s.push(curr);
			curr = curr->left;
		} else {
			TreeNode *top = s.top();
			s.pop();
			if(top->right) {
				curr = top->right;
			}
		}
	}

	return res;
}
