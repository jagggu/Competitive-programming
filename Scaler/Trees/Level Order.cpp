/*
Level Order
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level). Example : Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

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
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
	int DELIMITER = -1;
	queue<TreeNode*> q;
	vector<vector<int> > res;
	vector<int> tmp;
	if(A == NULL) {
		return res;
	}
	q.push(A);
	q.push(NULL);

	while(!q.empty()) {
		TreeNode *top = q.front();
		q.pop();
		if(top == NULL) {
			res.push_back(tmp);
			tmp.clear();
			if(!q.empty()) { 
				q.push(NULL);
			}	
			continue;
		}

		tmp.push_back(top->val);
		if(top->left) {
			q.push(top->left);
		} 

		if(top->right) {
			q.push(top->right);
		}

	}

	return res;

}
