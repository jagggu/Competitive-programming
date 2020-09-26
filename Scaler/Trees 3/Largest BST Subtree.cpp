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
  bool isBST;
  int minVal;
  int maxVal;
  int size;
};

Node solveHelper(TreeNode *root, int &maxSize) {

      if(root == NULL) {
        return {true,INT_MAX,INT_MIN,0};
      }

      Node left = solveHelper(root->left,maxSize);
      Node right = solveHelper(root->right,maxSize);

      if(left.maxVal < root->val && root->val < right.minVal && left.isBST && right.isBST) {
          maxSize = max(maxSize,left.size+right.size+1);
         // cout<<"Root: "<<root->val<<' '<<"leftSize: "<<left.size<<' '<<" RightSize: "<<right.size<<endl;
        return {true,min(root->val,left.minVal),max(root->val,right.maxVal),left.size+right.size+1};
      } else {
        return {false,-1,-1,0};
      }

}

int Solution::solve(TreeNode* A) {

int maxSize = 0;
  Node ans = solveHelper(A, maxSize);
  return maxSize;
}
