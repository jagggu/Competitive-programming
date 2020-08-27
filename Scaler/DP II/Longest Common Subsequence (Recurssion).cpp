/*
Longest Common Subsequence
Problem Description

Given two strings A and B. Find the longest common subsequence ( A sequence which does not need to be contiguous), which is common in both the strings.

You need to return the length of such longest common subsequence.



Problem Constraints
1 <= Length of A, B <= 1005



Input Format
First argument is a string A.
Second argument is a string B.



Output Format
Return an integer denoting the length of the longest common subsequence.



Example Input
Input 1:

 A = "abbcdgf"
 B = "bbadcgf"
Input 2:

 A = "aaaaaa"
 B = "ababab"


Example Output
Output 1:

 5
Output 2:

 3


Example Explanation
Explanation 1:

 The longest common subsequence is "bbcgf", which has a length of 5.
Explanation 2:

 The longest common subsequence is "aaa", which has a length of 3.

 */


vector<vector<int> > dp;

int solveHelper(string &A, string &B, int i, int j) {
	if(i == 0 || j == 0) {
		return 0;
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	if(A[i-1] == B[j-1]) {
		return dp[i][j] = 1 + solveHelper(A,B,i-1,j-1);
	} else {

	return dp[i][j] = max(solveHelper(A,B,i,j-1),solveHelper(A,B,i-1,j));
	}
}

int Solution::solve(string A, string B) {

	dp.clear();
	int ALen = A.size();
	int BLen = B.size();

	vector<int> tmp;

	for(int i = 0;i<=ALen; i++) {
		tmp.clear();
		for(int j = 0;j<=BLen; j++) {
			tmp.push_back(-1);
		}
		dp.push_back(tmp);
	}

	int ans = solveHelper(A,B,ALen,BLen);

	return ans;

}
