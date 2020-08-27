int Solution::isMatch(const string A, const string B) {

	int ALen = A.size();
	int BLen = B.size();

	vector<vector<bool> > regexMatch(ALen+1,vector<bool>(BLen+1,false));

	regexMatch[0][0] = true;

	for(int i = 1;i<=BLen;i++) {
		regexMatch[0][i] = B[i-1] == '*' ? regexMatch[0][i-1]:false;
	}

	for(int i = 1;i<=ALen;i++) {
		for(int j = 1;j<=BLen;j++) {
			if(A[i-1] == B[j-1] || B[j-1] == '.') {
				regexMatch[i][j] = regexMatch[i-1][j-1];
			} else {
				regexMatch[i][j] = regexMatch[i][j-1];
				int ptr = i;
				while(ptr>=1 && A[ptr-1] == A[i-1]) {
					regexMatch[i][j] = regexMatch[i][j] | regexMatch[i-1][j];
					if(regexMatch[i][j]) {
						break;
					}
				}
			}
		}
	}

	return regexMatch[ALen][BLen];
}