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




vector<vector<int> > cutsRequired;

bool isPalindrome(string &A, int start, int end) {
	while (start <= end) {
		if (A[start] != A[end]) {
			return false;
		}
	}

	return true;
}

int minCutHelper(string &A, int start, int end) {
	if (isPalindrome(A, start, end)) {
		return 0;
	}

	if (cutsRequired[start][end] != -1 {
	return cutsRequired[start][end];
	}
	int ans = INT_MAX;

	for (int k = start; k < end; k++) {
	ans = min(ans, 1 + minCutHelper(start, k) + minCutHelper(k + 1, end));
	}

	return cutsRequired[start][end] = ans;
}

int Solution::minCut(string A) {

	cutsRequired.clear();
	vector<int> tmp;
	int n = A.size();
	if (n < 1) {
		return 0;
	}

	for (int i = 0; i < n; i++) {
		tmp.clear();
		for (int j = 0; j < n; j++) {
			tmp.push_back(-1);
		}

		cutsRequired.push_back(tmp);
	}

	int ans = minCutHelper(A, 0, n - 1);
	return ans;

}
