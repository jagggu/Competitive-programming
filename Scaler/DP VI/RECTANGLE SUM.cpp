
int maxSumSubArray(vector<int> &arr) {
	int maxEndingHere = 0;
	int maxSoFar = 0;

	for(int i = 0;i<arr.size();i++) {
		maxEndingHere += arr[i];

		if(maxEndingHere < 0) {
			maxEndingHere = 0;
		}

		maxSoFar = max(maxSoFar,maxEndingHere);
	}

	return maxSoFar;
}

int Solution::solve(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int ans = 0;
	int rows = A.size();
	int cols = A[0].size();

	for(int i = 0;i<rows;i++) {
		vector<int> pSum(cols,0);
		for(int j = i;j<rows;j++) {
			for(int k = 0;k<cols;k++) {
				pSum[k] +=A[j][k];
			}

			int currSum = maxSumSubArray(pSum);
			ans = max(ans,currSum);
		}
	}

	return ans;
}
