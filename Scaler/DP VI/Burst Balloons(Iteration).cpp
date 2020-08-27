int Solution::solve(vector<int> &A) {

	if(A.size() < 1) {
		return 0;
	}

	int n = A.size();

	vector<int> ballons(n+2);
	int indx = 0;
	ballons[indx++] = 1;
	for(int i = 0;i<n;i++) {
		ballons[indx++] = A[i];
	}
	ballons[indx] = 1;
	vector<vector<int> > maxCoins(n+2,vector<int>(n+2,0));
	for(int len = 1;len<=n;len++) {

		for(int left = 1;left+len<=(n+1);left++) { //As we appended the 2 1's first and last
			int right = left + len - 1;
			for(int last = left;last<=right;last++) {
				maxCoins[left][right] = max(maxCoins[left][right],maxCoins[left][last-1] + maxCoins[last+1][right] + ballons[left-1]*ballons[last]*ballons[right+1]);
			}
		}
	}

	return maxCoins[1][n];
}
