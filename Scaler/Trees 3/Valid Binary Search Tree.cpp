/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeInfo {\
public:
	bool isBST = false;
	int maxEle;
	int minEle;
};

bool isValidBSTHelper(TreeNode *root, int leftAllowed, int rightAllowed) {
	if(root == NULL) {
		return true;
	}
	
	return leftAllowed<=root->val && root->val<rightAllowed && isValidBSTHelper(root->left,leftAllowed,root->val) && isValidBSTHelper(root->right,root->val+1,rightAllowed);	
}

TreeInfo isValidBSTHelper1(TreeNode *root) {
	if(root == NULL) {
		TreeInfo tmp;
		tmp.isBST = true;
		tmp.maxEle = INT_MIN;
		tmp.minEle = INT_MAX;
		return tmp;
	}

	TreeInfo leftAns = isValidBSTHelper1(root->left);
	TreeInfo rightAns = isValidBSTHelper1(root->right);
    //cout<<leftAns.maxEle<<' '<<root->val<<' '<<rightAns.minEle<<endl;
	if(leftAns.maxEle < root->val &&  rightAns.minEle > root->val && leftAns.isBST && rightAns.isBST) {
		TreeInfo tmp;
		tmp.isBST = true;
		tmp.maxEle = max(root->val,rightAns.maxEle);
		tmp.minEle = min(root->val,leftAns.minEle);
		return tmp;
	}
	
	TreeInfo tmp;
	tmp.isBST = false;
	tmp.maxEle = -1;
	tmp.minEle = -1;
	return tmp;
	
}

int Solution::isValidBST(TreeNode* A) {

	//It works only for integers
	/*
	return isValidBSTHelper(A,INT_MIN,INT_MAX);
	*/

	TreeInfo res = isValidBSTHelper1(A);
	return res.isBST;
}
