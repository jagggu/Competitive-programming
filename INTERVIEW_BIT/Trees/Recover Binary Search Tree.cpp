/*
Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

 Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
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
 */
vector<int> Solution::recoverTree(TreeNode* A) {

	TreeNode *curr = A;
	stack<TreeNode*> s;

	int first = -1;
	int second = -1;

	int minVal = -1;
	int maxVal = -1;

	while(curr || !s.empty()) {
		if(curr) {
			s.push(curr);
			curr = curr->left;
		} else {
			curr = s.top();
            s.pop();
			if(first == -1) {
				first = curr->val;
			} else {
				second = curr->val;

				if(first > second) {
					if(minVal == -1) {
						minVal = second;
						maxVal = first;
					} else {
						minVal = second;
					}
				}

				first = second;
				
			}
			
			curr = curr->right;
		}
	}

	vector<int> ans;
	ans.push_back(minVal);
	ans.push_back(maxVal);

	return ans;
}
