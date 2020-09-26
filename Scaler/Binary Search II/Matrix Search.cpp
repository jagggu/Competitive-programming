/*
Matrix Search
Problem Description

Given a matrix of integers A of size N x M and an integer B. Write an efficient algorithm that searches for integar B in matrix A.

This matrix A has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Return 1 if B is present in A, else return 0.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 1000
1 <= A[i][j], B <= 106



Input Format
The first argument given is the integer matrix A.
The second argument given is the integer B.



Output Format
Return 1 if B is present in A, else return 0.



Example Input
Input 1:

A = [ 
      [1,   3,  5,  7]
      [10, 11, 16, 20]
      [23, 30, 34, 50]  
    ]
B = 3
Input 2:

A = [   
      [5, 17, 100, 111]
      [119, 120, 127, 131]    
    ]
B = 3


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

 3 is present in the matrix at A[0][1] position so return 1.
Explanation 2:

 3 is not present in the matrix so return 0.

*/


bool isExists(vector<int> &arr, int target) {
	int n = arr.size();

	int start = 0;
	int end = n-1;

	while(start <= end) {
		int mid = start + (end-start)/2;
		if(arr[mid] == target) {
			return true;
		} else if(arr[mid] < target) {
			start = mid+1;
		} else {
			end = mid-1;
		}
	}

	return false;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	for(int i = 0;i<rows; i++) {
		if(A[i][cols-1] < B) {
			continue;
		}

		return isExists(A[i],B);
	}

	return 0;
}
