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



long long int MOD = 1e9+7;

vector<int> Solution::solve(string A) {

	string str = A;
	reverse(A.begin(),A.end());
	string revStr = A;

	int n = A.size();
	vector<vector<int> > commonSubSeq(n+1,vector<int>(n+1,0));

	commonSubSeq[0][0] = 1;
	for(int i = 1;i<=n;i++) {
		commonSubSeq[i][0] = 1;
		commonSubSeq[0][i] = 1;
	}

	for(int i = 1;i<=n;i++) {
		for(int j = 1;j<=n;j++) {
			if(str[i-1] == revStr[j-1]) {
				commonSubSeq[i][j] = (commonSubSeq[i-1][j-1]%MOD + commonSubSeq[i][j-1]%MOD + commonSubSeq[i-1][j]%MOD - commonSubSeq[i-1][j-1]%MOD) % MOD;
				if(commonSubSeq[i][j]<0) {
					commonSubSeq[i][j] += MOD;
				}
			} else {
				commonSubSeq[i][j] = (commonSubSeq[i][j-1]%MOD + commonSubSeq[i-1][j]%MOD - commonSubSeq[i-1][j-1]%MOD) % MOD;
				if(commonSubSeq[i][j]<0) {
					commonSubSeq[i][j] += MOD;
				}
			}
		}
	}

	vector<int> res;
	for(int i = 1;i<=n;i++) {

		res.push_back(commonSubSeq[i-1][n-i]);
	}

	return res;
}
