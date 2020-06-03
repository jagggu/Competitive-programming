/*
Recover Binary Search Tree
Two elements of a binary search tree (BST) are swapped by mistake. Tell us the 2 values swapping which the tree will be restored.
 Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
Example :
Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST

*/


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/

vector<int> Solution::recoverTree(TreeNode* A) {

	stack<TreeNode*> s;
	TreeNode *curr = A;
	vector<int> res;

	int minEle = -1;
	int maxEle = -1;
	int firstEle = -1;
	int secondEle = -1;

	if(A == NULL) {
		return res;
	}

	while(!s.empty() || curr != NULL) {

		if(curr) {	
			s.push(curr);
			curr = curr->left;
		} else {
			TreeNode *tmp = s.top();
			s.pop();
			curr = tmp->right;
			if(firstEle == -1) {
				firstEle = tmp->val;
			} else {
				if(secondEle == -1) { 
				secondEle = tmp->val;
				} else {
					firstEle = secondEle;
					secondEle = tmp->val;
				}

				if(firstEle > secondEle) {
					if(minEle == -1 || maxEle == -1) {
						minEle = secondEle;
						maxEle = firstEle;
					} else {
						minEle = secondEle;
					}
				}

			}
		}
	}

	res.push_back(minEle);
	res.push_back(maxEle);
	return res;

}
