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

	//Indexing from 1. Run a testcase with len of 4.
	//If i = 3, we are checking 3,2 which is last characters with 0 based
	//indexing
	for (int i = 1; i < n; i++) {
		if (A[i] == A[i - 1]) {
			isPal[i][i + 1] = true;
		}
	}

	for (int len = 3; len <= n; len++) {
		for (int i = 1; (i + len - 1) <= n; i++) {
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

int Solution::minCut(string A) {

	int n = A.size();
	if (n < 1) {
		return 0;
	}

	vector<vector<bool> > isPal = findPalindromes(A);

	vector<vector<int> > cutsRequired(n + 1, vector<int>(n + 1, 0));
	//cout<<"Ans: "<<isPal[1][2]<<endl;

	for (int len = 2; len <= n; len++) {
		for (int i = 1; i + len - 1 <= n; i++) {

			int j = i + len - 1;

			if (isPal[i][j]) {
				//cout<<i<<' '<<j<<endl;
				cutsRequired[i][j] = 0;
				continue;
			}
			/*
			if(isPalindrome(A,i-1,j-1)) {
				cutsRequired[i][j] = 0;
				continue;
			}
			*/
			cutsRequired[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				cutsRequired[i][j] = min(cutsRequired[i][j], 1 + cutsRequired[i][k] + cutsRequired[k + 1][j]);
			}
		}
	}


	return cutsRequired[1][n];
}
