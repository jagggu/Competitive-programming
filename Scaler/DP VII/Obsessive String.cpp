
long long int MOD = 1e9 + 7;

int Solution::solve(string A, string B) {

	int n = A.size();
	vector<int> matchCount(n, 0);

	int bLen = B.size();

	if (A.size() == B.size()) {
		return A == B;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if ((i - j + 1) >= bLen) {
				string str = A.substr(j, i - j + 1);
				if (str.find(B) < bLen) {
					// cout<<"Reached: "<<str<<endl;
					if (j == 0) {
						matchCount[i] = (matchCount[i] % MOD + 1) % MOD;
					} else {
						matchCount[i] = (matchCount[i] % MOD 1 % MOD + matchCount[j - 1] % MOD) % MOD;
					}
				}
			}
		}
	}

	int ans = 0;
	for (int ele : matchCount) {
		ans = (ans%MOD + ele%MOD)%MOD;
	}

	return ans;

}
