/*
ZigZag Level Order Traversal BT
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between). Example : Given binary tree
    3
   / \
  9  20
    /  \
   15   7
return
[
         [3],
         [20, 9],
         [15, 7]
]

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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > res;
    stack<TreeNode*> SL;
    stack<TreeNode*> SR;

    bool right = true;

    SR.push(A);
    vector<int> tmp;
    while(!SR.empty() || !SL.empty()) {
       // cout<<"Right: "<<right<<endl;
    	if(right) {
    		if(SR.empty()) {
    			res.push_back(tmp);
    			tmp.clear();
    			right = false;
    		} else {
    			TreeNode *curr = SR.top();
    			SR.pop();
    			tmp.push_back(curr->val);
    			if(curr->left) {
    				SL.push(curr->left);
    			}
    			if(curr->right) {
    			   // cout<<"checkPoint2";
    				SL.push(curr->right);
    			}
    		}
    	} else {
    		if(SL.empty()) {
    		  //  cout<<"checkPOint1"<<endl;
    			res.push_back(tmp);
    			tmp.clear();
    			right = true;
    		} else {
    		    //cout<<"checkPoint3"<<endl;
    			TreeNode *curr = SL.top();
    			SL.pop();
    			tmp.push_back(curr->val);
                //cout<<"LeftVal: "<<curr->val<<endl;
    			if(curr->right) {
    				SR.push(curr->right);
    			}

    			if(curr->left) {
    				SR.push(curr->left);
    			}
    		}
    	}
    }
    if(tmp.size() > 0) {
        res.push_back(tmp);
    }
    return res;
}
