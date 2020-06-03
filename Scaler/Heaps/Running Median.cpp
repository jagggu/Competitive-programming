/*
Running Median
Problem Description
Given an array of integers A denoting a stream of integers. New arrays of integer B and C are formed. Each time an integer is encountered in a stream, append it at the end of B and append median of array B at the C. Find and return the array C. NOTE:
If the number of elements are N in B and N is odd then consider medain as B[N/2] ( B must be in sorted order).
If the number of elements are N in B and N is even then consider medain as B[N/2-1]. ( B must be in sorted order).
  


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 109


Input Format
The only argument given is the integer array A.


Output Format
Return an integer array C, C[i] denotes the median of first i elements.


Example Input
Input 1:
 A = [1, 2, 5, 4, 3]
Input 2:
 A = [5, 17, 100, 11]
 


Example Output
Output 1:
 [1, 1, 2, 2, 3]
Output 2:
 [5, 5, 17, 11]
 


Example Explanation
Explanation 1:
 stream          median
 [1]             1
 [1, 2]          1
 [1, 2, 5]       2
 [1, 2, 5, 4]    2
 [1, 2, 5, 4, 3] 3
Explanation 2:
 stream          median
 [5]              5
 [5, 17]          5
 [5, 17, 100]     17
 [5, 17, 100, 11] 11 
 

 */



vector<int> Solution::solve(vector<int> &A) {

	priority_queue<int> left;

	priority_queue<int,vector<int>,greater<int> > right;

	vector<int> res;

	int n = A.size();
	if(n < 1) {
		return res;
	}

	res.push_back(A[0]);

	left.push(A[0]);
	double median = A[0];
	for(int i = 1;i<n;i++) {
		int ans;
		double val = A[i];

		if(left.size() > right.size()) {
			if(val < median) {
				right.push(left.top());
				left.pop();
				left.push(A[i]);
			} else {
				right.push(A[i]);
			}

			median = (left.top() + right.top())/2.0;

			 ans = left.top();

			//res.push_back(ans);
		} else if(left.size() == right.size()) {
			 
			if(val < median) {
				left.push(A[i]);
				median = left.top();
				ans = left.top();
			} else {
				right.push(A[i]);
				median = right.top();
				ans = right.top();
			}
		} else {
			if(val > median) {
				left.push(right.top());
				right.pop();
				right.push(val);
			} else {
				left.push(val);
			}

			median = (left.top() + right.top())/2.0;
			ans = left.top();
		}

		res.push_back(ans);
	}

	return res;

}
