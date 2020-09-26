/*
Strange Equality
Problem Description

Given an integer A.
Two numbers X and Y are defined as follows:

X is the greatest number smaller than A such that XOR sum of X and A is the same as the sum of X and A.
Y is the smallest number greater than A such that XOR sum of Y and A is the same as the sum of Y and A.
Find and return the XOR of X and Y.

NOTE 1: XOR of X and Y is defined as X ^ Y where '^' is the BITWISE XOR operator.

NOTE 2: Your code will be run against a maximum of 100000 Test Cases.



Problem Constraints
1 <= A <= 109



Input Format
First and only argument is an integer A.



Output Format
Return an integer denoting the XOR of X and Y.



Example Input
A = 5


Example Output
10


Example Explanation
The value of X will be 2 and the value of Y will be 8. The XOR of 2 and 8 is 10.

*/



int Solution::solve(int A) {

	int totalBits = 0;
	int num = A;

	while(num > 0) {
		totalBits++;
		num>>=1;
	}
	int smallerNum = 1<<totalBits;

	int largerNum = 0;

	num = A;
	int index = 0;
	while(num > 0) {
		if(!(num&1)) {
			largerNum = largerNum | (1<<index);
		}
        num >>= 1;
		index++;
	}

	return largerNum ^ smallerNum;

}

