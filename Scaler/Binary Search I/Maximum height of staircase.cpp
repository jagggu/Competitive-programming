/*
Maximum height of staircase
Problem Description

Given an integer A representing the number of square blocks. The height of each square block is 1. The task is to create a staircase of max height using these blocks.

The first stair would require only one block, the second stair would require two blocks and so on.

Find and return the maximum height of the staircase.



Problem Constraints
0 <= A <= 109


Input Format
The only argument given is integer A.



Output Format
Return the maximum height of the staircase using these blocks.



Example Input
Input 1:

 A = 10
Input 2:

 20


Example Output
Output 1:

 4
Output 2:

 5

 */



#define ll long long int

bool isPossible(ll mid, ll A) {
	ll blocks = (mid/2.0) * (mid+1);
	return blocks <= A;
}

int Solution::solve(int A) {

	int start = 0;
	int end = A;
	int ans = 0;
	while(start <= end) {
		ll mid = start + (end-start)/2;
		if(isPossible(mid,A)) {
			ans = mid;
			start = mid+1;
		} else {
			end = mid-1;
		}
	}

	return ans;
}
