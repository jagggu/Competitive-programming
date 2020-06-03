/*
Largest Rectangle in Histogram
Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1. Largest Rectangle in Histogram: Example 1 Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]. Largest Rectangle in Histogram: Example 2 The largest rectangle is shown in the shaded area, which has area = 10 unit. Find the area of largest rectangle in the histogram. 
Input Format
The only argument given is the integer array A.
Output Format
Return the area of largest rectangle in the histogram.
For Example
Input 1:
    A = [2, 1, 5, 6, 2, 3]
Output 1:
    10
    Explanation 1:
        The largest rectangle is shown in the shaded area, which has area = 10 unit.

 */



int Solution::largestRectangleArea(vector<int> &A) {
	int n = A.size();
	if(n < 1) {
		return 0;
	}
	vector<int> nextSmaller(n);
	vector<int> prevSmaller(n);

	stack<int> s;
	s.push(0);
	prevSmaller[0] = -1;
	for(int i = 1;i<n;i++) {
		while(!s.empty() && A[s.top()]>=A[i]) {
			s.pop();
		}
		if(s.empty()) {
			prevSmaller[i] = -1;
		} else {
			prevSmaller[i] = s.top();
		}
		s.push(i);
	}
	while(!s.empty()) {
		s.pop();
	}

	nextSmaller[n-1] = n;
	s.push(n-1);
	for(int i = n-2;i>=0;i--) {
		while(!s.empty() && A[s.top()] >= A[i]) {
			s.pop();
		}
		if(s.empty()) {
			nextSmaller[i] = n;
		} else {
			nextSmaller[i] = s.top();
		}
		s.push(i);
	}

	int maxArea = INT_MIN;
	for(int i = 0;i<n;i++) {
		int left = prevSmaller[i] + 1;
		int right = nextSmaller[i] - 1;
		int width = abs(right-left) + 1;
		int currArea = A[i] * width;
	//	cout<<currArea<<endl;
		maxArea = max(maxArea,currArea);
	}
	return maxArea;
}
