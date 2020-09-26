/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
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

*/

//Efficient Solution

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
ll MOD  = 1e9+7;

ll solveHelper(TreeNode *root1, TreeNode *root2) {

    stack<TreeNode*> s1,s2;
    ll sum = 0;

    while(true) {

        if(root1) {
          s1.push(root1);
          root1 = root1->left;
        } else if(root2) {
          s2.push(root2);
          root2 = root2->left;
        } else if(!s1.empty() && !s2.empty()) {

            root1 = s1.top();
            root2 = s2.top();

            if(root1->val == root2->val) {
              sum = (sum%MOD + root1->val%MOD) % MOD;

              s1.pop();
              s2.pop();

              root1 = root1->right;
              root2 = root2->right;
            } else if(root1->val < root2->val) {
              s1.pop();
              root1 = root1->right;
              root2 = NULL;
            } else {
              s2.pop();
              root2 = root2->right;
              root1 = NULL;
            }
        } else {
          return sum%MOD;
        }
    }
}

int Solution::solve(TreeNode* A, TreeNode* B) {

      int sum = solveHelper(A,B);
      return sum;
}
