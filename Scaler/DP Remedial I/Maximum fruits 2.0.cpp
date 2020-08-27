/*
Maximum fruits 2.0
Problem Description

You go to a fruit market, and you see N fruit sellers standing in a line, and each of them offers you or take away from you Ai amount of fruits, where A is an array of integers of size N. You are also given an integer B.

You want to take home the maximum number of fruits to make your family happy, but the fruit sellers are very selfish.

If you give/take fruits from a fruit seller at index i, the fruit sellers index in the range [i-B to i+B] won't offer/take fruits.

What is the maximum number of fruits you can take finally? 

NOTE: It is also possible you choose none of the fruit sellers.

Return the answer MOD 1000000007



Problem Constraints
1 <= N <= 10000
-109 <= A[i] <= 109
0 <= B <= N-1



Input Format
A: Array of integers denoting number of fruits each fruit seller might give/take.



Output Format
Maximum number of fruits you can take from the sellers. Return the answer MOD 109+7.



Example Input
A: [1, 2, -3, -5, 4, 6, -3, 2, -1, 2]
B: 1



Example Output
12



Example Explanation
We choose the fruit sellers at index 2, 6, 8 and 10, so the maximum fruits are 2+6+2+2 = 12

*/



#define ll long long int
ll MOD = 1e9 + 7;

int Solution::solve(vector<int> &A, int B) {

	if(A.size() < 1) {
		return 0;
	}

	int n = A.size();
	vector<ll> dp(n+1);
	dp[0] = max(A[0],0);
	

	for(int i = 1;i<=B;i++) {
		
		ll ele = A[i];
		dp[i] = max(dp[i-1],ele);
		
	}

	for(int i = B+1;i<n;i++) {
		ll first = A[i] + dp[i-B-1];
		ll second = dp[i-1];

		dp[i] = max(first, second);
		//dp[i] = dp[i]%MOD;

	}

	return dp[n-1]%MOD;
}
