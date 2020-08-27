/*
Unique Binary Search Trees II
Problem Description

Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A?



Problem Constraints
1 <= A <=18



Input Format
First and only argument is the integer A



Output Format
Return a single integer, the answer to the problem



Example Input
Input 1:

 1
Input 2:

 2


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Only single node tree is possible.
Explanation 2:

 2 trees are possible, one rooted at 1 and other rooted at 2.

 */



int Solution::numTrees(int A) {

	vector<int> uniqueBSTs(A+1);
	uniqueBSTs[0] = 1;
	uniqueBSTs[1] = 1;
	uniqueBSTs[2] = 2;

	for(int i = 3;i<=A;i++) {
		for(int j = 1; j<=i; j++) {
			uniqueBSTs[i] += (uniqueBSTs[j-1] * uniqueBSTs[i-j]);
		}
	}

	return uniqueBSTs[A];
}
