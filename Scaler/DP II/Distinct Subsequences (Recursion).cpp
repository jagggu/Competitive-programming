
vector<vector<int> > distinctCnt;

int numDistinctHelper(string A, string B, int Ai, int Bj) {

	if(Ai == 0 && Bj == 0) {
		return 1;
	}
	if(Bj == 0) {
		return 1;
	}

	if(Ai == 0) {
		return 0;
	}

	if(distinctCnt[Ai][Bj] != -1) {
		return distinctCnt[Ai][Bj];
	}

	if(A[Ai-1] == B[Bj-1]) {
		return distinctCnt[Ai][Bj] = numDistinctHelper(A,B,Ai-1,Bj-1) + numDistinctHelper(A,B,Ai-1,Bj);
	} else {
		return distinctCnt[Ai][Bj] = numDistinctHelper(A,B,Ai-1,Bj);
	}
}

int Solution::numDistinct(string A, string B) {

	int ALen  = A.size();
	int BLen = B.size();

	distinctCnt.clear();
	vector<int> tmp;

	for(int i = 0;i<=ALen;i++) {
		tmp.clear();
		for(int j = 0;j<=BLen;j++) {
			tmp.push_back(-1);
		}
		distinctCnt.push_back(tmp);
	}

	int ans = numDistinctHelper(A,B,ALen,BLen);

	return ans;

}
