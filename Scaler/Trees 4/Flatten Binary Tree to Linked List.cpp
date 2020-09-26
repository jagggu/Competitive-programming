/*
Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place. Example : Given
         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.

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

struct Node {
	TreeNode *head;
	TreeNode *tail;
};

Node flattenHelper(TreeNode *root) {
	if(root == NULL) {
		return {NULL,NULL};
	}

	Node leftAns = flattenHelper(root->left);
	Node rightAns = flattenHelper(root->right);

	if(leftAns.head == NULL) {
		root->right = rightAns.head;
		root->left = NULL;
		if(rightAns.tail) {
			return {root,rightAns.tail};
		} else {
			return {root,rightAns.head};
		}
	} else if(rightAns.head == NULL) {
		root->right = leftAns.head;
		root->left = NULL;
		if(leftAns.tail) {
			return {root,leftAns.tail};
		} else {
			return {root,leftAns.head};
		}
	} else {
		root->right = leftAns.head;
		root->left = NULL;
		if(leftAns.tail) {
			leftAns.tail->right = rightAns.head;
		} else {
			leftAns.head->right = rightAns.head;
		}
		if(rightAns.tail) {
			return {root,rightAns.tail};
		} else {
			return {root,rightAns.head};
		}
	}

}

TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	Node ans = flattenHelper(A);
	return ans.head;
}
