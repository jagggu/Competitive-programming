/*
All Subarrays
We have an integer array for you.
You have to generate it's all subarrays having the size greater than 1.
Then for each subarray find Bitwise XOR of its maximum and second maximum element.
After that return the maximum value of XOR among all subarrays.  
 Input Format
Given only argument A, an Integers Array.
Output Format
Return an Integer, i.e maximum value of XOR of maximum and 2nd maximum element among all subarrays.
Constraints
2 <= size of array <= 1e5
1 <= A[i] <= 1e7
For Example
Example Input:
    A = [2, 3, 1, 4]

Example Output:
    7

Explanation:
    All subarrays of A having size greater than 1 are:
    Subarray            XOR of maximum and 2nd maximum no.
    1. [2, 3]           1
    2. [2, 3, 1]        1
    3. [2, 3, 1, 4]     7
    4. [3, 1]           2
    5. [3, 1, 4]        7
    6. [1, 4]           5
    So maximum value of Xor among all subarrays is 7.

 */

int Solution::solve(vector<int> &A) {

	int n = A.size();

	vector<int> nextGreaterRight(n);
	vector<int> nextGreaterLeft(n);

	stack<int> s;

	nextGreaterRight[n-1] = -1;
	s.push(n-1);
	for(int i = n-2;i>=0;i--) {
		while(!s.empty() && A[s.top()] < A[i]) {
			s.pop();
		}
		if(s.empty()) {
			nextGreaterRight[i] = -1;
		} else {
			nextGreaterRight[i] = s.top();
		}
		s.push(i);
	}

	while(!s,empty()) {
		s.pop();
	}
	nextGreaterLeft[0] = -1;
	s.push(0);
	for(int i = 1;i<n;i++) {
		while(!s.empty() && A[s.top()] < A[i]) {
			s.pop();
		}
		if(s.empty()) {
			nextGreaterLeft[i] =  -1;
		} else {
			nextGreaterLeft[i] = s.top();
		}
		s.push(i);
	}

	int ans = 0;
	int xorResult = 0;
	for(int i = 0;i<n;i++) {
		if(nextGreaterLeft[i] != -1) {
			ans = max(ans,A[i]^A[nextGreaterLeft[i]]);
		}
		if(nextGreaterRight[i] != -1) {
			ans = max(ans,A[i]^A[nextGreaterRight[i]]);
		}
	}

	return ans;
	
}
