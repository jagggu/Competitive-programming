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
struct LL {
	TreeNode *head;
	TreeNode *tail;
};

LL flattenHelper(TreeNode *root) { 
	if(root == NULL) {
		LL tmp;
		tmp.head = NULL;
		tmp.tail = NULL;
		return tmp;
	}
	LL leftAns = flattenHelper(root->left);
	LL rightAns = flattenHelper(root->right);
	if(leftAns.head == NULL) {
	    root->right = rightAns.head;
	    LL tmp;
	    tmp.head = root;
	    if(rightAns.tail) { 
	    tmp.tail = rightAns.tail;
	    } else {
	        tmp.tail = rightAns.head;   // Tail should refer to some address instead of NULL
	    }
	    root->left = NULL;
	    return tmp;
	} else if(rightAns.head == NULL) {
	       root->right = leftAns.head;
	       root->left = NULL;
	       LL tmp;
	       tmp.head = root;
	       if(leftAns.tail != NULL) {
	           tmp.tail = leftAns.tail;
	       } else {
	           tmp.tail = leftAns.head;
	       }
	       return tmp;
	} 
	else {
	 //cout<<root->val<<' '<<leftAns.head<<' '<<leftAns.tail<<endl;
	root->right = leftAns.head;
	if(leftAns.tail != NULL) { 
	leftAns.tail->right = rightAns.head;
	} else {
	    leftAns.head->right = rightAns.head;
	}
	root->left = NULL;
	LL tmp;
	tmp.head = root;
	if(rightAns.tail) {
	    tmp.tail = rightAns.tail;
	} else {
	    tmp.tail = rightAns.head;
	}
	return tmp;
	}
}

TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	LL res = flattenHelper(A);

	return res.head;

}
