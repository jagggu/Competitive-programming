/*
Ways to Decode
Problem Description

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message denoted by string A containing digits, determine the total number of ways to decode it.



Problem Constraints
1 <= length(A) <= 105



Input Format
The first and the only argument is a string A.



Output Format
Return an integer, representing the number of ways to decode the string.



Example Input
Input 1:

 A = "12"
Input 2:

 A = "8"


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 Given encoded message "8", it could be decoded as only "H" (8).
 The number of ways decoding "8" is 1.
Explanation 2:

 Given encoded message "12", it could be decoded as "AB" (1, 2) or "L" (12).
 The number of ways decoding "12" is 2.

 */


/*
	dp[i] --> No of ways starting with i as first number
*/

int Solution::numDecodings(string A) {
	int n = A.size();
	if(n<1) {
		return 0;
	}
	vector<int> ways(n+1,0);

	ways[n] = 1;
	ways[n-1] = A[n-1] == '0'? 0 : 1;

	for(int i = n-2;i>=0;i--) {
	    
	    if(A[i] == '0') {
	        continue;
	    }
	    
		int num = (A[i]-'0') * 10 + (A[i+1]-'0');

		ways[i] = num<=26?ways[i+1]+ways[i+2]:ways[i+1];
	}

	return ways[0];

}
