int Solution::solve(vector<int> &A, int B) {

	int start = 0;
	int zeroCnt = 0;
	int n = A.size();
	int maxLen = 0;
	for(int end = 0; end < n; end++) {

		if(A[end] == 0) {
			zeroCnt++;
		}

		while(start < n && zeroCnt > B) {
			if(A[start] == 0) {
				zeroCnt--;
			}
			start++;
		}

		int currLen = (end - start) + 1;
		maxLen = max(maxLen, currLen);
	}

	return maxLen;
}
