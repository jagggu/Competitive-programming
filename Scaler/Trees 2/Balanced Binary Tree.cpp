/*
Given a binary tree, determine if it is height-balanced.
 Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
Return 0 / 1 ( 0 for false, 1 for true ) for this problem Example :
Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 

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
int isBalancedHelper(TreeNode *root, bool &ans) {
	if(root == NULL) {
		return -1;
	}
	int lh = isBalancedHelper(root->left,ans);
	int rh = isBalancedHelper(root->right,ans);
	if(abs(lh-rh)>1) {
		//return -1;
		ans = false;
	}
	return max(lh,rh)+1;
}

pair<int,bool> isBalancedHelperOptimised(TreeNode *A) {
	if(A == NULL) {
		return make_pair(-1,true);
	}

	pair<int,bool> leftBT = isBalancedHelperOptimised(A->left);
	bool isBalancedLeft = leftBT.second;
	int leftHeight = leftBT.first;
	if(isBalancedLeft) {
		pair<int,bool> rightBT = isBalancedHelperOptimised(A->right);
		bool isBalancedRight = rightBT.second;
		int rightHeight = rightBT.first;
		if(isBalancedRight && abs(leftHeight-rightHeight)<=1) {
			return make_pair(max(leftHeight,rightHeight)+1,true);
		}
		return make_pair(-1,false);
	}
	return make_pair(-1,false);
}

int Solution::isBalanced(TreeNode* A) {
	/*
	bool ans = true;
	int ht = isBalancedHelper(A,ans);
	return ans;
	*/

	//Optimised Code

	pair<int,bool> ans = isBalancedHelperOptimised(A); 
	return ans.second;
}
