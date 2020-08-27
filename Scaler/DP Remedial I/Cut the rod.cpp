/*
Cut the rod
Given an integer A, and an integar vector B of size A. Cut the rod of length A into pieces such that sum of price of all pieces is maximum.
B[i] denotes price of a piece of length i.

Find and return maximum price possible after cutting the rod.


Input Format

The first argument given is integer A.
The second argument given is array B.
Output Format

Find and return maximum price possible after cutting the rod.
Constraints

1 <= A <= 10^4
1 <= B[i] <= 10^5
For Example

Input 1:
    A = 5
    B = [3, 7, 7, 10, 12]
Output 1:
    17
Explaination 1:
Rod of length 5 can be broken as :- 5 = 2 + 2 +1
answer = B[2] + B[2] + B[1] = 7 + 7 + 3 = 17 

Input 2:
    A = 6
    B = [1, 7, 9, 9 ,21, 44]
Output 2:
    44
Explaination 2:
Rod of length 6 can be broken as :- 6 = 6
answer = B[6] = 44


*/



int Solution::solve(int A, vector<int> &B) {

	vector<int> dp(A+1);
	dp[1] = B[0];

	for(int i = 1;i<=A;i++) {
	    dp[i] = INT_MIN;
		for(int j = 1;j<=i;j++) {
			dp[i] = max((B[j-1] + dp[i-j]), dp[i]);
		}
	}

	return dp[A];
}
