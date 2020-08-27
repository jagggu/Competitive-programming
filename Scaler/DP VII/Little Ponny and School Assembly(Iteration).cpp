int Solution::solve(vector<int> &A) {

	int B = A[0];
	int G = A[1];
	int C = A[2];
	int D = A[3];

	int dp[B+1][G+1][C+1][D+1] = {0};

	for(int i = 0;i<=C;i++) {
		for(int j = 0;j<=D;j++) {
			dp[0][0][i][j] = 1;
		}
	}

	for(int i = 1;i<=B;i++) {
		for(int j = 1;j<=G;j++) {
			for(int k = 1;k<=C;k++) {
				for(int l = 1;l<=D;l++) {
					dp[i][j][k][l] = dp[i-1][j][k-1][D] + dp[i][j-1][C][l-1];
				}
			}
		}
	}

	return dp[B][G][C][D];
}
