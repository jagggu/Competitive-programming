/*
Little Ponny and Partition Sort
Problem Description

You are given an array of integers A.



You need to divide it in the maximum number of partitions such that after sorting each partition individually, The array becomes sorted.



Return the maximum number of partitions in which you can divide the array.



Problem Constraints
1 <= |A| <= 100000

Each element of the array is between 1 and 109 (inclusive)



Input Format
The first and only argument of the input is the array A



Output Format
Your function should return a single integer - the maximum number of partitions in which you can divide the array.



Example Input
Input 1:

 A: [3, 2, 2]
Input 2:

 A: [3, 4, 1, 2, 5, 7, 6]


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

You have to sort the entire array to make it sorted, there is no division possible for the given array.
Thus, there will be only one parition i.e, [3, 2, 2].
Explanation 2:

You can divide the array in three parts i.e, [3, 4, 1, 2], [5], [7, 6].
After sorting each part individually array will become [1, 2, 3, 4], [5], [6, 7] = [1, 2, 3, 4, 5, 6, 7] which is sorted.


*/



int Solution::solve(vector<int> &A) {

	int partitions = 0;

	int n = A.size();
	vector<int> maxLeft(n);
	vector<int> minRight(n);

	maxLeft[0] = A[0];
	for(int i = 1;i<n;i++) {
		maxLeft[i] = max(maxLeft[i-1],A[i]);
	}

	minRight[n-1] = A[n-1];
	for(int i = n-2;i>=0;i--) {
		minRight[i] = min(minRight[i+1],A[i]);
	}

	for(int i = 0;i<n-1;i++) {
		if(maxLeft[i] <= minRight[i+1]) {
			partitions++;
		}
	}

	return partitions + 1; //Considering the last partition
}
