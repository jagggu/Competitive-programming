/*
Min Sum Path in Matrix
Problem Description

Given a M x N grid A filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Return the minimum sum of the path.

NOTE: You can only move either down or right at any point in time.



Problem Constraints
1 <= M, N <= 1000

-1000 <= A[i][j] <= 1000



Input Format
First and only argument is a 2-D grid A.



Output Format
Return an integer denoting the minimum sum of the path.



Example Input
Input 1:

 A = [
       [1, 3, 2]
       [4, 3, 1]
       [5, 6, 1]
     ]
Input 2:

 A = [
       [1, -3, 2]
       [2, 5, 10]
       [5, -5, 1]
     ]


Example Output
Output 1:

 8
Output 2:

 -1


Example Explanation
Explanation 1:

 The path will be: 1 -> 3 -> 2 -> 1 -> 1.
Input 2:

 The path will be: 1 -> -3 -> 5 -> -5 -> 1.

 */




int Solution::minPathSum(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	} 

	//dp[i][j] = No of ways to reach (n,m) from (i,j)
	// So the ans will lie in dp[0][0]
	//here We are modifing the same 2D - array A

	int rows = A.size();
	int cols = A[0].size();

	for(int i = cols-2;i>=0;i--) {
		A[rows-1][i] = A[rows-1][i] + A[rows-1][i+1];
	}

	for(int i = rows-2;i>=0;i--) {
		A[i][cols-1] = A[i][cols-1] + A[i+1][cols-1];
	}

	for(int i = rows-2;i>=0;i--) {
		for(int j = cols-2;j>=0;j--) {
			A[i][j] = A[i][j] + min(A[i+1][j],A[i][j+1]);
		}
	}

	return A[0][0];
}
