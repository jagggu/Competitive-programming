
vector<vector<int> > maxSum;

int Solution::calculateMinimumHP(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}
	int rows = A.size();
	int cols = A[0].size();

	maxSum.clear();
	vector<int> tmp;
	for(int i = 0;i<=rows;i++) {
		tmp.clear();
		for(int j = 0;j<=cols;j++) {
			tmp.push_back(-1);
		}
		maxSum.push_back(tmp);
	}

	int ans = calculateMinimumHPHelper(A,rows,cols)
}
