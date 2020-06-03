/*
Maximum Rectangle
Given a 2D binary matrix of integers A containing 0's and 1's of size N x M. Find the largest rectangle containing only 1's and return its area. Note: Rows are numbered from top to bottom and columns are numbered from left to right. 
Input Format
The only argument given is the integer matrix A.
Output Format
Return the area of the largest rectangle containing only 1's.
Constraints
1 <= N, M <= 1000
0 <= A[i] <= 1
For Example
Input 1:
    A = [   [0, 0, 1]
            [0, 1, 1]
            [1, 1, 1]   ]
Output 1:
    4

Input 2:
    A = [   [0, 1, 0, 1]
            [1, 0, 1, 0]    ]
Output 2:
    1
 */


int findMaxRectangle(vector<int> &height) {
	stack<int> s;
	int maxArea = INT_MIN;
	int n = height.size();
	for(int i = 0;i<n;i++) {
		if(s.empty() || height[s.top()]<=height[i]) {
			s.push(i);
		} else {
			while(!s.empty() && height[s.top()]>height[i]) {
				int ht = height[s.top()];
				s.pop();
				int currArea = ht * (s.empty()?i:i-s.top()-1);
				maxArea = max(maxArea,currArea);
			}
			s.push(i);
		}
	}

	while(!s.empty()) {
		int ht = height[s.top()];
		s.pop();
		int currArea = ht * (s.empty()?n:n-s.top()-1);
		maxArea = max(maxArea,currArea);
	}
	return maxArea;
}


int Solution::solve(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int maxArea = findMaxRectangle(A[0]); 
	for(int i = 1;i<A.size();i++) {
		for(int j = 0;j<A[0].size();j++) {
			if(A[i][j] == 1) {
				A[i][j] = A[i][j] + A[i-1][j];
			}
		}
		int currArea = findMaxRectangle(A[i]);
		maxArea = max(maxArea,currArea);
	}
	return maxArea;
}
