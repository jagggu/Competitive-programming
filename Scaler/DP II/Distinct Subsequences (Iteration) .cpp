int Solution::numDistinct(string A, string B) {

	int ALen = A.size();
	int BLen = B.size();

	vector<vector<int> > distinctCnt(ALen+1,vector<int>(BLen+1));

	distinctCnt[0][0] = 1;
	for(int i = 1;i<=ALen;i++) {
		distinctCnt[i][0] = 0;
	}

	for(int i = 1;i<=BLen;i++) {
		distinctCnt[0][i] = 0;
	}

	for(int i = 1;i<=ALen;i++) {
		for(int j = 1;j<=BLen;j++) {
			if(A[i-1] == B[j-1]) {
				distinctCnt[i][j] = distinctCnt[i-1][j-1] + distinctCnt[i-1][j]
			} else {
				distinctCnt[i][j] = distinctCnt[i-1][j];
			}
		}
	}

	return distinctCnt[ALen][BLen];
}
