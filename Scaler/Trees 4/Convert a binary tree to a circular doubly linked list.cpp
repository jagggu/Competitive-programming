/*
Definition for binary tree
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

TreeNode* findCircularDLL(TreeNode *root) {
	TreeNode *curr = root;

	TreeNode *head = NULL;
	TreeNode *tail = NULL;
	stack<TreeNode*> s;

	while(curr != NULL || !s.empty()) {
		if(curr) {
			s.push(curr);
			curr = curr->left;
		} else {
			TreeNode *tmp = s.top();
			s.pop();

			if(head == NULL) {
				head = tmp;
				tail = tmp;
			} else {
				TreeNode *tmp1 = tmp;
				tail->right = tmp1;
				tmp1->left = tail;
				tail = tail->right;
			}
			curr = tmp->right;
		}
	}

	tail->right = head;
	return head;
}

TreeNode* solve(TreeNode *A){
	
	return findCircularDLL(A);    
}
