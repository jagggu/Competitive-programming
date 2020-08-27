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


vector<vector<int> > LPal;  //Longest Palindrome

int longestPalindromicSubsequence(string &A, int i, int j) {
	if (i == j) {
		return 1;
	}

	if (i > j) {
		return 0;
	}

	if(LPal[i][j] != -1) {
		return LPal[i][j];
	}

	if(A[i] == A[j]) {
		return LPal[i][j] = longestPalindromicSubsequence(A,i+1,j-1) + 2;
	} else {
		return LPal[i][j] = max(longestPalindromicSubsequence(A,i+1,j), longestPalindromicSubsequence(A,i,j-1));
	}
}

int Solution::solve(string A) {

	int n = A.size();
	if (n < 1) {
		return 0;
	}
	vector<int> tmp;
	LPal.clear();

	for (int i = 0; i <= n; i++) {
		tmp.clear();
		for (int j = 0; j <= n; j++) {
			tmp.push_back(-1);
		}
		LPal.push_back(tmp);
	}

	int ans = longestPalindromicSubsequence(A, 0, n - 1);

	return ans;
}
