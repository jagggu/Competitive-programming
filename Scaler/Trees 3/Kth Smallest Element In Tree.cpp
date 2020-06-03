/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int preProcessTreeSize(TreeNode *root, unordered_map<TreeNode*,int> &m) {
	if(root == NULL) {
		return 0;
	}
	int leftSize = preProcessTreeSize(root->left,m);
	int rightSize = preProcessTreeSize(root->right,m);

	m[root] = leftSize+rightSize+1;
	return leftSize+rightSize+1;
}

int kthsmallestHelper(TreeNode *root, int k, unordered_map<TreeNode*,int> &m) {
	
	int leftSize = root->left == NULL?0:m[root->left];
    //cout<<"size: "<<m[root]<<' '<<"k: "<<k<<endl;
	if(leftSize>=k) {
		return kthsmallestHelper(root->left,k,m);
	} else if(leftSize == k-1) {
		return root->val;
	} else {
		return kthsmallestHelper(root->right,k-leftSize-1,m);
	}
}

int Solution::kthsmallest(TreeNode* A, int B) {
	unordered_map<TreeNode*,int> m;
	TreeNode *curr = A;
	if(A == NULL) {
		return -1;
	}

	int tmp = preProcessTreeSize(curr,m);

	int res = kthsmallestHelper(A,B,m);
	return res;
}
