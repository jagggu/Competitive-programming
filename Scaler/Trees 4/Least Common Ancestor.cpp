/*
Least Common Ancestor
Find the lowest common ancestor in an unordered binary tree given two values in the tree.
Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.
Example :
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.
 LCA = Lowest common ancestor 
Please note that LCA for nodes 5 and 4 is 5.
You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn't exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can't add a parent pointer.

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

void findInOutValues(TreeNode *root, unordered_map<int,int> &in, unordered_map<int,int> &out, int &time) {
	if(root == NULL) {
		return;
	}
	
	in[root->val] = time;
	time++;
	findInOutValues(root->left,in,out,time);
	findInOutValues(root->right,in,out, time);
	out[root->val] = time;
	time++;
	
//	cout<<in[root->val]<<' '<<out[root->val]<<endl;
}

bool isAncestor(int currVal, int val1, int val2, unordered_map<int,int> &in, unordered_map<int,int> &out) {
	if(in[currVal]<=in[val1] && out[currVal] >= out[val1] && in[currVal] <= in[val2] && out[currVal] >= out[val2]) {
		return true;
	}

	return false;
}

int findLCA(TreeNode *root, int val1, int val2, unordered_map<int,int> &in, unordered_map<int,int> &out) {

	while(root != NULL) {
		if(root->left && isAncestor(root->left->val,val1,val2,in,out)) {
			root = root->left;
		} else if(root->right && isAncestor(root->right->val,val1,val2,in,out)) {
			root = root->right;
		} else {
			return root->val;
		}
	}
}

int lcaHelper(TreeNode *root, int val1, int val2, int &ans) {
	if(root == NULL) {
		return 0;
	}

	int leftAns = lcaHelper(root->left, val1,val2,ans);
	int righAns = lcaHelper(root->right,val1,val2,ans);

	int foundHeight = leftAns + rightAns + (root->val == val1) + (root->val == val2);

	if(ans == -1 && foundHeight == 2){
		ans = root->val;
	}

	return foundHeight;
}

int Solution::lca(TreeNode* A, int B, int C) {
	/*
	unordered_map<int,int> in;
	unordered_map<int,int> out;
	int time = 1;
//	cout<<A<<endl;

  
	findInOutValues(A,in,out,time);  
    
    for(auto itr = in.begin(); itr != in.end(); itr++) {
        //cout<<in[B]<<' '<<in[C]<<endl;
       // in[itr->first] = in[itr->second];
    }
    
    for(auto itr = out.begin(); itr != out.end();itr++) {
       // out[itr->first] = out[itr->second];
    }
    
    //cout<<B<<' '<<C<<endl;
    
    //cout<<in[B]<<' '<<in[1]<<endl;
    
  
	if(in.find(B) == in.end()) {
		return -1;
	}  

	if(in.find(C) == in.end()) {
		return -1;
	}
    //cout<<"second: "<<A<<endl;
  
	return findLCA(A,B,C,in,out);
	*/

	// Recursive solution

	int ans = -1;

	lcaHelper(A,B,C,ans);
	return ans;
}
