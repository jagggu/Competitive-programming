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
TreeNode *tmp = NULL;
ll findSum(TreeNode *root) {
	TreeNode *curr = root;
	stack<TreeNode*> s;

	ll sum = 0;

	while(curr != NULL || !s.empty()) {
		if(curr) {
			sum += curr->val;
			s.push(curr);
			curr = curr->left;
		} else {
			TreeNode *tmp = s.top();
			s.pop();
			curr = tmp->right;
		}

	}
	return sum;
}

ll isPossible(TreeNode *root, ll sumToAchieve, int &ans) {
	if(root == NULL) {
		return 0;
	}

	ll leftSum = isPossible(root->left,sumToAchieve,ans);
	ll rightSum = isPossible(root->right,sumToAchieve,ans);

	ll sum = leftSum + rightSum + root->val;

	if(sum == sumToAchieve && tmp == NULL) {
	    tmp = root;
		ans = 1;
	}

	return sum;
	
}

ll solveHelper(TreeNode *root, unordered_set<ll> &s, int &ans) {
	if(root == NULL) {
		return 0;
	}

	ll lSum = solveHelper(root->left,s,ans);
	ll rSum = solveHelper(root->right,s,ans);

	ll sum = lSum + rSum + root->val;

	if(s.find(sum) != s.end()) {
		ans = 1;
	}

	s.insert(sum);
	return sum;

}

int Solution::solve(TreeNode* A) {
	/*
    //cout<<"Start: "<<A<<endl;
	ll totalSum = findSum(A);
    //cout<<totalSum<<endl;
	if(abs(totalSum) & 1 ) {
		return 0;
	}

	 int ans = 0;
	 
	int a = isPossible(A,totalSum/2,ans);
	if(tmp == A) {
	    tmp = NULL;
	    return 0;
	}
//	cout<<"End: "<<tmp<<endl;
	return ans;
	*/

	unordered_set<ll> s;
	int ans = 0;
	ll k = solveHelper(A,s,0);
	return ans;

}
