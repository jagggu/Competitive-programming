/*
Longest Palindromic Subsequence
Problem Description

Given a string A. Find the longest palindromic subsequence (A subsequence which does not need to be contiguous and is a palindrome).

You need to return the length of longest palindromic subsequence.



Problem Constraints
1 <= length of(A) <= 103



Input Format
First and only integer is a string A.



Output Format
Return an integer denoting the length of longest palindromic subsequence.



Example Input
Input 1:

 A = "bebeeed"
Input 2:

 A = "aedsead"


Example Output
Output 1:

 4
Output 2:

 5


Example Explanation
Explanation 1:

 The longest palindromic subsequence is "eeee", which has a length of 4.
Explanation 2:

 The longest palindromic subsequence is "aedea", which has a length of 5.

 */


/*
	dp[i][j] ---> Longest palindromic subsequence of length j and 
				character start from i

	The Ans lies in dp[1][N]
*/

int Solution::solve(string A) {

	int n = A.size();

	if(n<1) {
		return 0;
	}

	vector<vector<int> > LPal(n+1,vector<int>(n+1));
	LPal[0][0] = 0;

	for(int i = 1;i<=n;i++) {
		LPal[i][0] = 0;
		LPal[0][i] = 0;
		LPal[i][i] = 1;  // Single char is always a palindrome
	}

	for(int len = 2;len<=n;len++){
		//(n-len+1) Gives the last index that we can reach the end
		//with the length of *len*
		for(int i = 1;i<=(n-len+1);i++) {

			int j = i + len - 1;

			if(A[i-1] == A[j-1]) {
				LPal[i][j] = LPal[i+1][j-1] + 2;
			} else {
				LPal[i][j] = max(LPal[i+1][j],LPal[i][j-1]); // If not matching skip either ith character or jth character
			}
		}
	}

	return LPal[1][n];


}
