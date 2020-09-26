/*
Check for BST with exactly one child of each internal nodes
Given preorder traversal of a binary tree, check if it is possible that it is also a preorder traversal of a BST, where each internal node (non -leaf nodes) have exactly one child. CONSTRAINTS
1 <= N <= 100
INPUT
    A : [ 4, 10, 5 ,8 ]
OUTPUT
    YES
EXPLANATION
    The possible BST is:

            4
             \
             10
             /
             5
              \
              8

*/


string Solution::solve(vector<int> &A) {

    int n = A.size();

    if(n < 1) {
      return "YES";
    }
    int root = A[0];
    int left = INT_MIN;
    int right = INT_MAX;

    for(int i = 1;i<n;i++) {
      if(A[i] > root) {
        left = root;
      } else if(A[i] < root) {
        right = root;
      }

      if(A[i] < left || A[i] > right) {
        return "NO";
      }
      root = A[i];
    }

    return "YES";
}