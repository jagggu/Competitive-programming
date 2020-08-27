/*
Maximum Sum
Problem Description

You are given an array A of N integers and three integers B, C, and D.

You have to find the maximum value of A[i]*B + A[j]*C + A[k]*D, where 1 <= i <= j <= k <= N.



Problem Constraints
1 <= N <= 105

-10000 <= A[i], B, C, D <= 10000



Input Format
First argument is an array A
Second argument is an integer B
Third argument is an integer C
Fourth argument is an integer D



Output Format
Return an Integer S, i.e maximum value of (A[i] * B + A[j] * C + A[k] * D), where 1 <= i <= j <= k <= N.



Example Input
Input 1:

 A = [1, 5, -3, 4, -2]
 B = 2
 C = 1
 D = -1
Input 2:

 A = [3, 2, 1]
 B = 1
 C = -10
 D = 3


Example Output
Output 1:

 18
Output 2:

 -4


Example Explanation
Explanation 1:

 If you choose i = 2, j = 2, and k = 3 then we will get
 A[2]*B + A[2]*C + A[3]*D = 5*2 + 5*1 + (-3)*(-1) = 10 + 5 + 3 = 18
Explanation 2:

 If you choose i = 1, j = 3, and k = 3 then we will get
 A[1]*B + A[3]*C + A[3]*D = (3*1) + (-10*1) + (3*1) = 3 - 10 + 3 = -4

*/


/*
A simple solution is to run three nested loops to iterate through all triplets. For every triplet, compute the required value and keep track of maximum and finally return the same.

An efficient solution is to preocompute values and store them using extra space. The first key observation is i ≤ j ≤ k, so x*a[i] will always be the left maximum, and z*a[k] will always be the right maximum. Create a left array where we store the left maximums for every element. Create a right array where we store the right maximums for every element. Then for every element, calculate the maximum value of the function possible. For any index ind, the maximum at that position will always be (left[ind] + j * a[ind] + right[ind]), find the maximum of this value for every element in the array and that will be your answer.
*/



int Solution::solve(vector<int> &A, int B, int C, int D) {
	int n = A.size();

	if(n<1) {
		return 0;
	}

	vector<int> leftMax(n);
	vector<int> rightMax(n);

	leftMax[0] = A[0]*B;

	for(int i = 1;i<n;i++) {
		leftMax[i] = max(leftMax[i-1],A[i]*B);
	}

	rightMax[n-1] = A[n-1]*D;

	for(int i = n-2;i>=0;i--) {
		rightMax[i] = max(rightMax[i+1],A[i]*D);
	}

	int maxSum = INT_MIN;

	for(int i = 0; i<n; i++) {
		int tmp = leftMax[i] + (A[i]*C) + rightMax[i];
		maxSum = max(maxSum,tmp);
	}

	return maxSum;
}
