/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
Try to optimize the additional space complexity apart from the amortized time complexity. 


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
 
TreeNode *curr;
stack<TreeNode*> s;
BSTIterator::BSTIterator(TreeNode *root) {
   curr = root;
   while(!s.empty()) {
       s.pop();
   }

   while(curr) {
      // cout<<"checkPoint3"<<endl;
   	s.push(curr);
   	curr = curr->left;
   }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    
    //cout<<"checkPoint"<<endl;
    if( s.empty()) {
    	return false;
    }
//    cout<<"checkPoint"<<endl;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *top = s.top();
    s.pop();
    TreeNode *tmp = top->right;
    while(tmp) {
    	s.push(tmp);
    	tmp = tmp->left;
    }
    //cout<<"Val: "<<top->val<<endl;
    return top->val;
    
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
