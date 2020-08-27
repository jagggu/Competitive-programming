/*
Palindrome Partitioning II
Problem Description

Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.



Problem Constraints
1 <= length(A) <= 501



Input Format
The first and the only argument contains the string A.



Output Format
Return an integer, representing the minimum cuts needed.



Example Input
Input 1:

 A = "aba"
Input 2:

 A = "aab"


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 "aba" is already a palindrome, so no cuts are needed.
Explanation 2:

 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

 */



vector<vector<bool> > findPalindromes(string &A) {
	int n = A.size();
	vector<vector<bool> > isPal(n + 1, vector<bool>(n + 1, false));
	for (int i = 0; i <= n; i++) {
		isPal[i][i] = true;
	}

	for (int i = 1; i <= n; i++) {
		if (A[i] == A[i - 1]) {
			isPal[i][i + 1] = true;
		}
	}

	for (int len = 3; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {
			int j = i + len - 1;
			if (A[i - 1] == A[j - 1]) {
				isPal[i][j] = isPal[i + 1][j - 1];
			} else {
				isPal[i][j] = false;
			}
		}
	}

	return isPal;
}

int Solution::minCut(string A) {

	int n = A.size();
	vector<int> cutsRequired(n + 1, INT_MAX);

	vector<vector<bool> > isPal = findPalindromes(A);


	cutsRequired[n] = 0;
	for (int i = n - 1; i >= 1; i--) {
		if (isPal[i][n]) {
			cutsRequired[i] = 0;
		} else {
			cutsRequired[i] = INT_MAX;
			for (int k = i; k < n; k++) {
				if (isPal[i][k]) {
					cutsRequired[i] = min(cutsRequired[i], 1 + cutsRequired[k + 1]);
				}
			}
		}
	}

	return cutsRequired[1];
}
