/*
Right view of Binary tree
Given a binary tree of integers. Return an array of integers representing the right view of the Binary tree. Right view of a Binary Tree is a set of nodes visible when the tree is visited from Right side. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 
For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Output 1:
    [1, 3, 7, 8]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
Output 2:
    [1, 3, 4, 5]

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

/*
vector<int> Solution::solve(TreeNode* A) {
	vector<int> res;
	if(A == NULL) {
		return res;
	}
	queue<TreeNode*> q;
	q.push(A);
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0;i<size;i++) {
			TreeNode *curr = q.front();
			q.pop();
			if(curr->left) {
				q.push(curr->left);
			}
			if(curr->right) {
				q.push(curr->right);
			}
			if(i == size-1) {
				res.push_back(curr->val);
			}
		}
	}
	return res;

}

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

void solveHelper(TreeNode *root, int currLevel, int &maxLevel, vector<int> &ans) {

  if(root == NULL) {
    return;
  }

  if(currLevel == maxLevel) {
      ans.push_back(root->val);
      maxLevel++;
  }
  solveHelper(root->right,currLevel+1,maxLevel,ans);
  solveHelper(root->left,currLevel+1,maxLevel,ans);


}

vector<int> Solution::solve(TreeNode* A) {

  vector<int> ans;
  if(A == NULL) {
    return ans;
  }

  int maxLevel = 0;
  solveHelper(A,0,maxLevel,ans);
  return ans;

}
