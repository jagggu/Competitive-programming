/*
Max Rectangle in Binary Matrix
Problem Description

Given a 2-D binary matrix A of size N x M filled with 0's and 1's, find the largest rectangle containing all ones and return its area.



Problem Constraints
1 <= N, M <= 100



Input Format
First argument is an 2-D binary array A.



Output Format
Return an integer denoting the area of largest rectangle containing all ones.



Example Input
Input 1:

 A = [
       [1, 1, 1]
       [0, 1, 1]
       [1, 0, 0] 
     ]
Input 2:

 A = [
       [0, 1, 0]
       [1, 1, 1]
     ] 


Example Output
Output 1:

 4
Output 2:

 3


Example Explanation
Explanation 1:

 As the max area rectangle is created by the 2x2 rectangle created by (0,1), (0,2), (1,1) and (1,2).
Explanation 2:

 As the max area rectangle is created by the 1x3 rectangle created by (1,0), (1,1) and (1,2).

*/



int findMaxArea(vector<int> &arr) {
	stack<int> s;
	int n = arr.size();

	int maxArea = INT_MIN;

	for(int i = 0;i<n;i++) {
		if(s.empty() || arr[s.top()]<=arr[i]) {
			s.push(i);
		} else {
			while(!s.empty() && arr[s.top()]>arr[i]) {
				//int top = s.top();
				
				int currBar = arr[s.top()];
				s.pop();
				int currArea = currBar * (s.empty()?i:i-s.top()-1);
				maxArea = max(maxArea, currArea);
			}
			
			s.push(i);
		}
	}

	while(!s.empty()) {
		//int top = s.top();
		
		int currBar = arr[s.top()];
		s.pop();
		int currArea = currBar * (s.empty()?n:n-s.top()-1);
		maxArea = max(maxArea,currArea);
	}

	return maxArea;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	int maxArea = findMaxArea(A[0]);
	//cout<<maxArea<<endl;
	for(int i = 1;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == 1) {
				A[i][j] = A[i][j] +  A[i-1][j];
			} else {
				A[i][j] = 0;
			}
		}

		int tmpArea = findMaxArea(A[i]);
		//cout<<"Tmp: "<<tmpArea<<endl;
		maxArea = max(maxArea,tmpArea);
	}

	return maxArea;
}
