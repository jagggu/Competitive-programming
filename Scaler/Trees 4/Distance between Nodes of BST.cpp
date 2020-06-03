/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int findEdges(TreeNode *root, int target) {
	TreeNode *curr = root;
	int cnt = 0;

	while(curr != NULL) {
		if(curr->val < target) {
			cnt++;
			curr = curr->right;
		} else if(curr->val > target) {
			curr = curr->left;
		} else {
			return cnt;
		}
	}
}

int findLCA(TreeNode *root, int val1, int val2) {
	TreeNode *curr = root;

	while(curr) {
		if(cur->val > val1 && curr->val > val2) {
			curr = curr->left;
		} else if(curr->val < val1 && curr->val < val2) {
			curr = curr->right;
		} else {
			return curr->val;
		}
	}
}

int Solution::solve(TreeNode* A, int B, int C) {

	int edges1 = findEdges(A,B);
	int edges2 = findEdges(A,C);
	if(A->val>=B && A->val<=C) { 
		return edges1+edges2;
	}

	int lca = findLCA(A,B,C);

	int edges3 = findEdges(A,lca);

	return (edges1+edges2) - (2*edges3);

}
