/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void verticalOrderTraversalHelper(TreeNode *root, int &minKey, int &maxKey,int currIndex, unordered_map<int,vector<int> > &m) {
	if(root == NULL) {
		return;
	}
	m[currIndex].push_back(root->val);
	
	verticalOrderTraversalHelper(root->left,minKey,maxKey,currIndex-1,m);
	verticalOrderTraversalHelper(root->right,minKey,maxKey,currIndex+1,m);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
	unordered_map<int,vector<int> > m;
	queue<pair<TreeNode*,int> > q;

	vector<vector<int> > res;
	if(A == NULL) {
		return A;
	}

	q.push(make_pair(A,0));
	int minIndex = INT_MAX;
	int maxIndex = INT_MIN;
	while(!q.empty()) {
		pair<TreeNode*,int> p = q.front();
		q.pop();
		TreeNode *curr = p.first;
		int currIndex = p.second;
		m[currIndex].push_back(curr->val);
		minIndex = min(minIndex,currIndex);
		maxIndex = max(maxIndex,currIndex);
		if(curr->left) {
			q.push(make_pair(curr->left,currIndex-1));
		}
		if(curr->right) {
			q.push(make_pair(curr->right,currIndex+1));
		}
	}

	for(int i = minIndex;i<=maxIndex;i++) {
		res.push_back(m[i]);
	}
	return res;

}
