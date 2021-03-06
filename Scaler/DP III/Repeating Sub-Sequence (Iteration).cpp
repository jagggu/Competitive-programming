/*

Repeating Sub-Sequence
Problem Description

Given a string A, find if there is any subsequence that repeats itself.

A subsequence of a string is defined as a sequence of characters generated by deleting some characters in the string without changing the order of the remaining characters.

NOTE: Sub-sequence length should be greater than or equal to 2.



Problem Constraints
1 <= length(A) <= 100



Input Format
The first and the only argument of input contains a string A.



Output Format
Return an integer, 1 if there is any subsequence which repeat itself else return 0.



Example Input
Input 1:

 A = "abab"
Input 2:

 A = "abba"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 "ab" is repeated.
Explanation 2:

 There is no repeating subsequence.

 */


int Solution::anytwo(string A) {

	int n = A.size();

	if (n < 4) {
		//return 0;
	}

	vector<vector<int> > maxLenSubseq(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i - 1] == A[j - 1] && i != j) {
				maxLenSubseq[i][j] = 1 + maxLenSubseq[i - 1][j - 1];
			} else {
				maxLenSubseq[i][j] = max(maxLenSubseq[i - 1][j], maxLenSubseq[i][j - 1]);
			}
		}
	}

	return maxLenSubseq[n][n] >= 2 ? 1 : 0;
}
