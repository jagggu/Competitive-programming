vector<int> Solution::solve(int A, int B, int C, int D) {

	vector<vector<int> > res;

	int ia = 0;
	int ib = 0;
	int ic = 0;

	int nextA = A;
	int nextB = B;
	int nextC = C;

	for(int i = 0;i<D;i++) {
		res.push_back(min(nextA,min(nextB,nextC)));

		if(res[i] == nextA) {
			nextA = res[ia++] * A;
		} else if(res[i] == nextB) {
			nextB = res[ib++] * B;
		} else {
			nextC = res[ic++] * C;
		}
	}

	return res;


}
