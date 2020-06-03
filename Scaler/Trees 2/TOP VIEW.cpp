/*
TOP VIEW
Given a binary tree of integers. Return an array of integers representing the Top view of the Binary tree. Top view of a Binary Tree is a set of nodes visible when the tree is visited from Top side. Note: Return the nodes in any order. Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9 
For Example
Input 1:
            1
          /   \
         2    3
        / \  / \
       4   5 6  7
      /
     8 
Output 1:
    [1, 2, 4, 8, 3, 7]

Input 2:
            1
           /  \
          2    3
           \
            4
             \
              5
Output 2:
    [1, 2, 3]

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
vector<int> Solution::solve(TreeNode* A) {
	queue<pair<TreeNode*, int> > q;
	vector<int> res;
	if(A == NULL) {
		return res;
	}

	q.push(make_pair(A,0));
	unordered_map<int,int> m;
	m[0] = A->val;
	int minELe = INT_MAX;
	int maxEle = INT_MIN;
	while(!q.empty()) {
		int size = q.size();
		for(int i = 0;i<size;i++) {
			pair<TreeNode*,int> tmp = q.front();
			q.pop();
			int level = tmp.second;
			TreeNode *curr = tmp.first;
			if(m.find(level) == m.end()) {
				m[level] = curr->val;
				minELe = min(minELe,level);
				maxEle = max(maxEle,level);
			}
			if(curr->left) {
				q.push(make_pair(curr->left,level-1));
			}
			if(curr->right) {
				q.push(make_pair(curr->right,level+1));
			}
		}
	}

	res.push_back(m[0]);
	for(int i = -1;i>=minELe;i--) {
		res.push_back(m[i]);
	}
	for(int i = 1;i<=maxEle;i++) {
		res.push_back(m[i]);
	}
	return res;
}
