/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool isPalindrome(vector<int> &arr) {
	int start = 0;
	int end = arr.size()-1;
	while(start<=end) {
		if(arr[start] != arr[end]) {
			return false;
		}
		start++;
		end--;
	}

	return true;
}

int Solution::isSymmetric(TreeNode* A) {
	//Iterative Solution
	/*
	if(A == NULL) {
		return 1;
	}
	
	queue<TreeNode*> q;

	q.push(A);

	while(!q.empty()) {
		vector<int> arr;
		int size = q.size();
		for(int i = 0;i<size;i++) {
			TreeNode *curr = q.front();
			q.pop();
			if(curr->left) {
				q.push(curr->left);
			}
			if(curr->right) {
				q.push(curr->right);
			}
			arr.push_back(curr->val);
		}

		if(!isPalindrome(arr)) {
			return 0;
		}
	}

	return 1;
	*/
}
