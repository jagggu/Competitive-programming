
int solveHelper(int n, int k, vector<vector<int> > &dp){

	if(k == 1 || k == 0) {
		return k;
	}

	if(n == 1) {
		return k;
	}

	if(dp[n][k] != -1) {
		return dp[n][k];
	}

	int res = INT_MAX;
	for(int x = 1;x<=k; x++) {

		int tmp = max(solveHelper(n-1,x-1,dp),solveHelper(n,k-x,dp));
		res = min(res,tmp);
	}

	return dp[n][k] = 1 + res;
}

int Solution::solve(int A, int B) {
	
	int n = A; //Eggs
	int k = B; //Floors
	/*
	vector<vector<int> > dp(n+1,vector<int>(k+1,-1));

	int ans = solveHelper(n,k,dp);

	return ans;
	*/

	//Iterative Solution

	vector<vector<int> > dp(n+1,vector<int>(k+1));

	dp[0][0] = 0;

	for(int i = 1;i<=n;i++) {
		dp[i][1] = 1;
		dp[i][0] = 0;
	}

	for(int i = 1;i<=k;i++) {
		dp[1][i] = i;
	}

	for(int i = 2;i<=n;i++) {
		for(int j = 2;j<=k; j++) {

			dp[i][j] = INT_MAX;
			for(int x = 1;x<=j;x++) {

				int tmp = 1 + max(dp[i-1][x-1], dp[i][j-x]);
				dp[i][j] = min(dp[i][j],tmp);
			}
		}
	}

	return dp[n][k]; 
}
