/*
Largest BST Subtree
Problem Description
Given a Binary Tree A with N nodes. Write a function that returns the size of the largest subtree which is also a Binary Search Tree (BST). If the complete Binary Tree is BST, then return the size of whole tree. NOTE:
Largest subtree means subtree with most number of nodes.


Problem Constraints
1 <= N <= 105


Input Format
First and only argument is an pointer to root of the binary tree A.


Output Format
Return an single integer denoting the size of the largest subtree which is also a BST.


Example Input
Input 1:
     10
    / \
   5  15
  / \   \ 
 1   8   7
Input 2:
     5
    / \
   3   8
  / \ / \
 1  4 7  9


Example Output
Output 1:
 3
Output 2:
 7


Example Explanation
Explanation 1:
 Largest BST subtree is
                            5
                           / \
                          1   8
Explanation 2:
 Given binary tree itself is BST.

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

class TreeInfo {
public:
	int maxEle;
	int minEle;
	bool isBST;
	int size;
};

TreeInfo solveHelper(TreeNode *root, int &ans) {
	if(root == NULL) {
		TreeInfo tmp;
		tmp.maxEle = INT_MIN;
		tmp.minEle = INT_MAX;
		tmp.isBST = true;
		tmp.size = 0;
		return tmp;
	}

	TreeInfo leftAns = solveHelper(root->left,ans);
	TreeInfo rightAns = solveHelper(root->right,ans);
	if(leftAns.maxEle<root->val && rightAns.minEle>root->val && leftAns.isBST && rightAns.isBST) {
		TreeInfo tmp;
		tmp.maxEle = max(root->val,rightAns.maxEle);
		tmp.minEle = min(root->val,leftAns.minEle);
		tmp.isBST = true;
		tmp.size = leftAns.size + rightAns.size+1;
		ans = max(ans,tmp.size);
		return tmp;
	}

	TreeInfo tmp;
	tmp.maxEle = max(root->val,rightAns.maxEle);
	tmp.minEle = min(root->val,leftAns.minEle);
	tmp.isBST = false;
	tmp.size = leftAns.size + rightAns.size+1;
	//tmp.size = 0;
	
	return tmp;

}

int Solution::solve(TreeNode* A) {

int ans = 0;

	TreeInfo res = solveHelper(A,ans);

	return ans;

}
