/*
Container With Most Water
Problem Description
Given n non-negative integers A[0], A[1], ..., A[n-1] , where each represents a point at coordinate (i, A[i]).  N vertical lines are drawn such that the two endpoints of line i is at (i, A[i]) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water. Note: You may not slant the container. 


Problem Constraints
0 <= N <= 105 1 <= A[i] <= 105 


Input Format
Single Argument representing a 1-D array A.


Output Format
Single Integer denoting the maximum area you can obtain.


Example Input
A = [1,5,4,3]


Example Output
6


Example Explanation
5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6

*/


int Solution::maxArea(vector<int> &A) {
	
	int start = 0;
	int end = A.size()-1;

	int maxArea = 0;
	
	while(start < end) {
		int currMaxArea = min(A[start],A[end]) * (end-start);
		maxArea = max(maxArea,currMaxArea);
		if(A[start] < A[end])  {
			start++;
		} else {
			end--;
		}
	}
	return ans;    
}
