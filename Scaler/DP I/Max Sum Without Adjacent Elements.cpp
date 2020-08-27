/*
Max Sum Without Adjacent Elements
Problem Description

Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.

Note: You can choose more than 2 numbers.



Problem Constraints
1 <= N <= 20000
1 <= A[i] <= 2000



Input Format
The first and the only argument of input contains a 2d matrix, A.



Output Format
Return an integer, representing the maximum possible sum.



Example Input
Input 1:

 A = [   
        [1]
        [2]    
     ]
Input 2:

 A = [   
        [1, 2, 3, 4]
        [2, 3, 4, 5]    
     ]


Example Output
Output 1:

 2
Output 2:

 8


Example Explanation
Explanation 1:

 We will choose 2.
Explanation 2:

 We will choose 3 and 5.

 */




int Solution::adjacent(vector<vector<int> > &A) {

	vector<int> arr;

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	for(int i = 0;i<cols;i++) {
		arr.push_back(max(A[0][i],A[1][i]));
	}

	int n = arr.size();

	vector<int> maxSum(n+1,0);
	maxSum[1] = arr[0];

	/*
		maxSum[i] --> Represents the max sum till this point of time from the start.

		1. Consider the curr element i --> maxSum[i] = maxSum[i-2] + A[i]
		2. Not consider the curr element i  --> maxSum[i] = maxSum[i-1]

		Take the maximum from the above 1 and 2.
	*/

	for(int i = 2;i<=n;i++) {
		maxSum[i] = max(maxSum[i-1],maxSum[i-2] + arr[i-1]);
	}

	return maxSum[n];
}
