
int findMaxArea(vector<int> &arr) {
	stack<int> s;
	int n = arr.size();

	int maxArea = INT_MIN;

	for(int i = 0;i<n;i++) {
		if(s.empty() || arr[s.top()]<=arr[i]) {
			s.push(i);
		} else {
			while(!s.empty() && arr[s.top()]>arr[i]) {
				int top = s.top();
				
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
	cout<<maxArea<<endl;
	for(int i = 1;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == 1) {
				A[i][j] += A[i-1][j];
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
