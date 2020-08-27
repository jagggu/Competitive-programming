/*
Odd Palindrome
Problem Description

A palindrome string is a string which reads the same forward and backward. If a palindrome string is of odd length l, then (l+1)/2th character (1 index based) is said to be the centre of the palindrome.

You are given a string A. Return an array X of integers where X[i] = (number of odd length palindrome subsequence of A with A[i] as the centre) modulo (109 + 7).

A subsequence of A is a string which can be derived from A by deleting some of its character.



Problem Constraints
1 <= length(A) <= 1000
Every character of A will be a lowercase English letter 'a' - 'z'.



Input Format
First and only argument is a string A.



Output Format
Return an integer array X as mentioned in the question.



Example Input
Input 1:

 A = "xyzx"
Input 2:

 A = "ababzz"


Example Output
Output 1:

 [1, 2, 2, 1]
Output 2:

 [1, 2, 2, 1, 1, 1]


Example Explanation
Explanation 1:

 
 Index(i)  |   Palindrome subsequences with centre i
   0       |   a        
   1       |   y, xyx
   2       |   z, xzx
   3       |   x
 So, output array is [1, 2, 2, 1]

Explanation 2:

 Index(i)  |  Palindrome subsequences with centre i
   0       |  a    
   1       |  b, aba
   2       |  a, bab
   3       |  b
   4       |  z
   5       |  z
 So, output array is [1, 2, 2, 1, 1, 1]

 */



long long int MOD = 1000000007;
vector<int> Solution::solve(string A) {

	string org = A;
	 reverse(A.begin(),A.end());
    string rev = A;
	int n = A.size();
	vector<vector<int> > subSequences(n+1,vector<int>(n+1,0));

	subSequences[0][0] = 1;
	for(int i = 1;i<=n;i++) {
		subSequences[0][i] = 1;
		subSequences[i][0] = 1;
	}

	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(org[i-1] == rev[j-1]) {
				subSequences[i][j] = (subSequences[i-1][j-1]%MOD + (subSequences[i][j-1]%MOD + subSequences[i-1][j]%MOD - subSequences[i-1][j-1]%MOD + MOD) % MOD ) % MOD;
			} else {
				subSequences[i][j] = (subSequences[i][j-1]%MOD + subSequences[i-1][j]%MOD - subSequences[i-1][j-1]%MOD + MOD) % MOD;
			}
		}
	}

	vector<int> res;

	for(int i = 1;i<=n;i++) {
		int cnt = subSequences[i-1][n-i];
		res.push_back(cnt%MOD);
	}

	return res;
}
