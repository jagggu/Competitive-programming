/*
Next Pointer Binary Tree
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL. Initially, all next pointers are set to NULL.
 Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
Example : Given the following perfect binary tree,
         1
       /  \
      2    5
     / \  / \
    3  4  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 5 -> NULL
     / \  / \
    3->4->6->7 -> NULL

 */


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

/*
void Solution::connect(TreeLinkNode* A) {
	queue<TreeLinkNode*> q;
	if(A == NULL) {
		return;
	}

	q.push(A);
	while(!q.empty()) {
		TreeLinkNode *curr = q.front();
		q.pop();
		int size = q.size();
       // cout<<"size: "<<size<<' '<<curr->val<<endl;
		if(curr->left) {
			q.push(curr->left);
		}

		if(curr->right) {
			q.push(curr->right);
		}

		for(int i = 0;i<size;i++) {
		  //  cout<<"checkPoint1"<<endl;
			TreeLinkNode *tmp = q.front();
			q.pop();
		//	cout<<"size: "<<size<<' '<<tmp->val<<endl;
			if(tmp->left) {
				q.push(tmp->left);
			}
			if(tmp->right) {
				q.push(tmp->right);
			}
			curr->next = tmp;
			curr = tmp;
		}
		curr->next = NULL;
	}

	//return A;
}

*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {

    queue<TreeLinkNode*> q;
    if(A == NULL) {
      return;
    }

    q.push(A);

    while(!q.empty()) {
      int size = q.size();
      TreeLinkNode *prev = q.front();

      for(int i = 0;i<size;i++) {
        TreeLinkNode *curr = q.front();
        q.pop();
        if(curr->left) {
          q.push(curr->left);
        }
        if(curr->right) {
          q.push(curr->right);
        }

        if(curr != prev) {
          prev->next = curr;
        }
        prev = curr;
      }
    }
}
