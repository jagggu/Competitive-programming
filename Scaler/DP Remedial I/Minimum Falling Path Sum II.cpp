/*
Minimum Falling Path Sum II
Problem Description

Given a square grid of integers A, a falling path with non-zero shifts is a choice of exactly one element from each row of A, such that no two elements chosen in adjacent rows are in the same column.

Return the minimum sum of a falling path with non-zero shifts.



Problem Constraints
1 <= |A| == |A[i]| <= 200
-99 <= A[i][j] <= 99



Input Format
First argument is a 2D array of integers.



Output Format
Return an integer denoting the minimum sum.



Example Input
Input 1:

 A =  [ [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9] ]
Input 2:

 A =  [ [17, 14, 19],
        [12, 18, 9],
        [20, 10, 1] ]


Example Output
Output 1:

 13
Output 2:

 27


Example Explanation
Explanation 1:

 The possible falling paths are:
 [1,5,9], [1,5,7], [1,6,7], [1,6,8],
 [2,4,8], [2,4,9], [2,6,7], [2,6,8],
 [3,4,8], [3,4,9], [3,5,7], [3,5,9]
 The falling path with the smallest sum is [1,5,7], so the answer is 13.
Explanation 2:

 The possible falling paths are:
 The falling path with the smallest sum is [14,12,1], so the answer is 27.


 */




int Solution::solve(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	for(int i = 1;i<rows; i++) {
		for(int j = 0;j<cols;j++) {
			
			int tmp = INT_MAX;
			for(int k = 0; k<cols; k++) {
			    if(k != j) {
			        tmp = min(tmp,A[i-1][k]);
			    }
			}
			
			A[i][j] = A[i][j] + tmp;
		}
	}

	int sum = INT_MAX;

	for(int i = 0;i<cols;i++) {
		sum = min(sum, A[rows-1][i]); 
	}

	return sum;
}
