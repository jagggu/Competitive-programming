/*
Level Order
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level). Example : Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
Also think about a version of the question where you are asked to do a level order traversal of the tree when depth of the tree is much greater than number of nodes on a level.

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
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {

      queue<TreeNode*> q;
      vector<vector<int> > ans;
      if(A == NULL) {
        return ans;
      }

      q.push(A);

      vector<int> tmp;

      while(!q.empty()) {

          int size = q.size();
          tmp.clear();

          for(int i = 0;i<size;i++) {
            TreeNode *currNode = q.front();
            q.pop();
            tmp.push_back(currNode->val);
            if(currNode->left) {
              q.push(currNode->left);
            }
            if(currNode->right) {
              q.push(currNode->right);
            }
          }

          ans.push_back(tmp);
      }

      return ans;
}
