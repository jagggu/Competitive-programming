/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define ll long long int

void storeTheNodesOfA(TreeNode *root, unordered_set<int> &s) {
	TreeNode *curr = root;

	stack<TreeNode*> st;

	while(curr != NULL || !st.empty()) {
		if(curr) {
			s.insert(curr->val);
			st.push(curr);
			curr = curr->left;
		} else {
			TreeNode *tmp = st.top();
			st.pop();
			if(tmp->right) {
				st.push(tmp->right);
			}
			curr = tmp->right;
		}
	}
}

int sumOfNodesInB(TreeNode *root, unordered_set<int> &s) {
	stack<TreeNode*> st;

	ll ans = 0;
	ll mod = 1e9+7;
	TreeNode *curr = root;

	while(curr!= NULL || !st.empty()) {
		if(curr) {
			int val = curr->val;
			if(s.find(val) != s.end()) {
				ans = (ans%mod + val%mod) %mod;
			}
			st.push(curr);
			curr = curr->left;
		} else {
			TreeNode *tmp = st.top();
			st.pop();
			if(tmp->right) {
				st.push(tmp->right);
			}
			curr = tmp->right;
		}
	}

	return ans%mod;
}

int Solution::solve(TreeNode* A, TreeNode* B) {

	unordered_set<int> s;
	storeTheNodesOfA(A,s);

	return sumOfNodesInB(B,s);

}
