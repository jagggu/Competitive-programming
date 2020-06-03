/*
Longest Consecutive Sequence
Problem Description
Given an unsorted integer array A of size N. Find the length of the longest set of consecutive elements from the array A. 


Problem Constraints
1 <= N <= 106 -106 <= A[i] <= 106 


Input Format
First argument is an integer array A of size N.


Output Format
Return an integer denoting the length of the longest set of consecutive elements from the array A.


Example Input
A = [100, 4, 200, 1, 3, 2]


Example Output
4


Example Explanation
 The set of consecutive elements will be [1, 2, 3, 4].


*/

int Solution::longestConsecutive(const vector<int> &A) {
	unordered_set<int> s;

	for(int ele : A) {
		s.insert(ele);
	}

	int ans = 0;
	for(int i = 0;i<A.size(); i++) {
		int num = A[i];

		
		if(s.find(num-1) == s.end()) {
			int currAns = 1;
			while(s.find(num+1) != s.end()) {
				num++;
				currAns++;
			}
			ans = max(ans,currAns);
		}
	}

	return ans;
}
