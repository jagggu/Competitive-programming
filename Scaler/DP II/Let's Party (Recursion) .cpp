/*
Let's Party
Problem Description

In Danceland, one person can party either alone or can pair up with another person.

Can you find in how many ways they can party if there are A people in Danceland?

Note: Return your answer modulo 10003, as the answer can be large.



Problem Constraints
1 <= A <= 105



Input Format
Given only argument A of type Integer, number of people in Danceland.



Output Format
Return an integer denoting the number of ways people of Danceland can party.



Example Input
Input 1:

 A = 3
Input 2:

 A = 5


Example Output
Output 1:

 4
Output 2:

 26


Example Explanation
Explanation 1:

 Let suppose three people are A, B, and C. There are only 4 ways to party
 (A, B, C) All party alone
 (AB, C) A and B party together and C party alone
 (AB, C) A and B party together and C party alone
 (BC, A) B and C party together and A
 here 4 % 10003 = 4, so answer is 4.
 
Explanation 2:

 Number of ways they can party are: 26.

 */



vector<int> ways;
#define MOD 10003

int findWays(int n) {
	if(n <= 0) {
		return 0;
	}

	if(n == 1) {
		return 1;
	}
	
	if(n == 2) {
	    return 2;
	}

	if(ways[n] != -1) {
		return ways[n];
	}

	return ways[n] = (findWays(n-1)%MOD + ((n-1)%MOD * findWays(n-2)%MOD ) %MOD ) % MOD;
}

int Solution::solve(int A) {
	ways.clear();

	for(int i = 0;i<=A;i++) {
		ways.push_back(-1);
	}

	int ans =findWays(A);

	return ans%MOD;
}
