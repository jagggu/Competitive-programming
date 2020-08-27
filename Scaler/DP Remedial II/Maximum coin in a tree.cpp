/*
Maximum coin in a tree
Given a tree T of N nodes rooted at 1, where each node i has Bi coins attached with it. You have to choose a subset of nodes such that no two adjacent nodes(i.e. nodes connected directly by an edge) are chosen and sum of coins attached with nodes in chosen subset is maximum.

Input Format:

    First argument of input contains an integer aray A denoting parent of each node.
    Second argument of input contains an integer array B denoting coins at each node.
Output Format:

    return a single integer denoting maximum coins possible.
Constraints:

    1 <= N <= 50000
    -40000 <= B[i] <= 40000 
    A[0] = 0
For Example:

Input 1:
    A = [0, 1, 1] B = [10, 2, 3]
Output 1:
    10
Explanation 1:
we choose node 10
    10
   /  \
  2    3
Input 2:
    A = [0, 1, 1] B = [5, 3, 4]
Output 2:
    7

   */


#define MAXN 50000

int solveHelper(int root, vector<int> &B, unordered_map<int,vector<int> > &children, unordered_map<int,vector<int> > &grandChildren, vector<int> &dp) {

	int includeAns = 0;
	int dontIncludeAns = 0;

	if(dp[root] != -1) {
		return dp[root];
	}

	//Don't include the current node
	for(auto child : children[root]) {
		dontIncludeAns += solveHelper(child,B,children,grandChildren,dp);
	}

	//Include the root

	for(auto gc : grandChildren[root]) {
		includeAns += solveHelper(gc,B,children,grandChildren,dp);
	}

	return dp[root] =  max(dontIncludeAns, B[root] + includeAns);

}
 
int Solution::solve(vector<int> &A, vector<int> &B) {

	unordered_map<int,vector<int> > children;
	unordered_map<int,vector<int> > grandChildren;
	vector<int> dp(MAXN+1,-1);

	for(int i = 0;i<A.size();i++) {
		if(A[i] == 0) {
			continue;
		}

		children[A[i] - 1].push_back(i);
	}

	for(int i = 0;i<A.size(); i++) {
		if(A[i] == 0) {
			continue;
		}

		int p1 = A[i] - 1;
		if(p1 == 0) {
			continue;
		}

		int p2 = A[p1] - 1;
		grandChildren[p2].push_back(i);
	}

	int ans = solveHelper(0,B,children,grandChildren,dp);

	return ans;
}
