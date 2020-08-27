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


bool isPalindrome(string &A, int start, int end) {
	while (start <= end) {
		if (A[start] != A[end]) {
			return false;
		}
		start++;
		end--;
	}

	return true;
}

int minCutHelper(string &A, int start, int end, vector<vector<int> > &minCuts) {
	if (isPalindrome(A, start, end)) {
		return 0;
	}

	if (minCuts[start][end] != -1) {
		return minCuts[start][end];
	}

	int ans = INT_MAX;

	for (int k = start; k < end; k++) {
		ans = min(ans, 1 + minCutHelper(A, start, k, minCuts) + minCutHelper(A, k + 1, end, minCuts));
	}

	return minCuts[start][end] = ans;
}

int Solution::minCut(string A) {

	int n = A.size();
	vector<vector<int> > minCuts(n, vector<int>(n, -1));

	int ans = minCutHelper(A, 0, n - 1, minCuts);
	return ans;
}
