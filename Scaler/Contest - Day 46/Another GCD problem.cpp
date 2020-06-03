/*
Another GCD problem
Problem Description
Given an integer array A of size N. Find the maximum length of a subarray Al, Al+1 ... Ar such that gcd(A[l], A[l+1], ... A[r]) > 1. NOTE: If no such subarray exists, return -1.     


Problem Constraints
1 <= N <= 105
0 <= A[i] <= 106


Input Format
First and only argument is an integer array A of size N.


Output Format
Return an integer denoting the maximum length of a subarray.


Example Input
Input 1:
 A = [7, 1, 2, 3, 4]
Input 2:
 A = [2, 4, 6, 8, 20]
    


Example Output
Output 1:
 1
Output 2:
 5
    


Example Explanation
Explanation 1:
 Gcd of every two consecutive element is 1. So, we can not take more than 1 element in any subarray. So, the answer is 1.
Explanation 2:
 Gcd of all elements in the array is greater than 1 which is 2. So, the maximum length of the subarray is 5.

*/




int findGCD(int a, int b) {
    int maxNum  = max(a,b);
    int minNum = min(a,b);
    while(minNum != 0) {
        int tmp = maxNum % minNum;
        maxNum = minNum;
        minNum = tmp;
    }
    return maxNum;
}


int Solution::solve(vector<int> &A) {

	int n = A.size();
	if(n < 1) {
		return -1;
	}

	int currGCD = A[0];
	int minGCD = 2;
	int ans = 0;
	int start = 0;
	for(int end = 1; end<n; end++) {

		int tmpGCD = findGCD(currGCD,A[end]);
		if(tmpGCD >= minGCD) {
			currGCD = tmpGCD;
			ans = max(ans,end-start+1); 
		} else {
			int tmpStart = end;
			int newGCD = A[end];
			while(tmpStart>=start && findGCD(newGCD,A[tmpStart])>=minGCD) {
				newGCD = findGCD(newGCD,A[tmpStart]);
				tmpStart--;
			}
			if(tmpStart == end) {
				currGCD = A[end];
				start = end;
			} else {
				start = tmpStart + 1;
				currGCD = newGCD;
			}
		}
	}
	if(ans == 0) {
		for(auto ele : A) {
			if(ele > 1) {
				return 1;
			}
		}
		return -1;
	}
	return ans;
}