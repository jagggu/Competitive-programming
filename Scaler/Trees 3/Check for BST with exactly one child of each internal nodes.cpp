/*
Check for BST with exactly one child of each internal nodes
Given preorder traversal of a binary tree, check if it is possible that it is also a preorder traversal of a BST, where each internal node (non -leaf nodes) have exactly one child. CONSTRAINTS
1 <= N <= 100
INPUT
    A : [ 4, 10, 5 ,8 ]
OUTPUT
    YES
EXPLANATION
    The possible BST is:

            4
             \
             10
             /
             5
              \
              8

*/


bool isFound(vector<int> &A, int index) {
    int val = A[index];
    
    bool greater = false, lesser = false;
    for(int i = index+1;i<A.size();i++) {
        if(A[i]>val) {
            greater = true;
        }
        
        if(A[i] < val) {
            lesser = true;
        }
    }
    
    return greater && lesser;
}

bool solveHelper(vector<int> &A, int choice) {
     
    int n = A.size();
    
    /*
	int n = A.size();
	for(int i= 0;i<n-2;i++) {
	    if(A[i]>A[i+1] && A[i]>A[i+2]) {
	        continue;
	    } else if(A[i]<A[i+1] && A[i]<A[i+2]) {
	        continue;
	    } else {
	        return false;
	    }
	    
	}
	return true;
	*/
	
	for(int i = 0;i<n;i++) {
	    if(isFound(A,i)) {
	        return false;
	    }
	}
	return true;
}

string Solution::solve(vector<int> &A) {

	if(solveHelper(A,1) || solveHelper(A,2) || solveHelper(A,3) || solveHelper(A,4)) {
	    return "YES";
	} else {
	    return "NO";
	}

}
