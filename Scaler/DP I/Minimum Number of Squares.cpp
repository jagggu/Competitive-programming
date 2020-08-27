/*
Minimum Number of Squares
Problem Description

Given an integer A. Return minimum count of numbers, sum of whose squares is equal to A.



Problem Constraints
1 <= A <= 105



Input Format
First and only argument is an inetegr A.



Output Format
Return an integer denoting the minimum count.



Example Input
Input 1:

 A = 6
Input 2:

 A = 5


Example Output
Output 1:

 3
Output 2:

 2


Example Explanation
Explanation 1:

 Possible combinations are : (12 + 12 + 12 + 12 + 12 + 12) and (12 + 12 + 22).
 Minimum count of numbers, sum of whose squares is 6 is 3. 
Explanation 2:

 We can represent 5 using only 2 numbers i.e. 12 + 22 = 5

 */



int Solution::countMinSquares(int A) {

	vector<int> minCount(A + 1, INT_MAX);
	minCount[0] = 0;

	/*
		* minCount[i] --> This state represents min number of
			squares required that sums to the i.
		
		* Consider i as the last element and find the ans for i.
			Use this answer for the future calculations 

	*/

	for (int i = 1; i <= A; i++) {
		for (int j = 1; j * j <= A; j++) {
			int tmp = i - (j * j);
			if (tmp >= 0) {
				minCount[i] = min(minCount[i], 1 + minCount[tmp]);
			}
		}
	}

	return minCount[A];

}
