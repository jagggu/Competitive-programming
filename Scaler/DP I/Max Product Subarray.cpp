/*
Max Product Subarray
Problem Description

Given an integer array A of size N. Find the contiguous subarray within the given array (containing at least one number) which has the largest product.

Return an integer corresponding to the maximum product possible.

NOTE: Answer will fit in 32-bit integer value.



Problem Constraints
1 <= N <= 5 * 105

-100 <= A[i] <= 100



Input Format
First and only argument is an integer array A.



Output Format
Return an integer corresponding to the maximum product possible.



Example Input
Input 1:

 A = [4, 2, -5, 1]
Input 2:

 A = [-3, 0, -5, 0]


Example Output
Output 1:

 8
Output 2:

 0


Example Explanation
Explanation 1:

 We can choose the subarray [4, 2] such that the maximum product is 8.
Explanation 2:

 0 will be the maximum product possible.

*/



int Solution::maxProduct(const vector<int> &A) {

	int maxEndingHere = 1;
	int minEndingHere = 1;
	int maxSoFar = 1;
	int flag = 1;
	for(int i = 0;i<A.size();i++) {
		if(A[i] > 0) {
			flag = 0;
			maxEndingHere = maxEndingHere*A[i];
			minEndingHere = min(minEndingHere*arr[i],1);
		} else if(A[i] == 0) {
			maxEndingHere = 1;
			minEndingHere = 1;
		} else {
			int tmp = maxEndingHere;
			maxEndingHere = max(1,minEndingHere*A[i]);
			minEndingHere = tmp*A[i];
		}

		maxSoFar = max(maxSoFar,maxEndingHere);
	} 

	if(flag) {
		return 0;
	}

	return maxSoFar;

}