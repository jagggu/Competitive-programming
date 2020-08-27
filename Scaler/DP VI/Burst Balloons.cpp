
unordered_map<int, bool> visited;

int solveHelper(int left, int right, vector<int> &A) {

	int ans = 0;
	for(int i = left+1;i<right;i++) {
		int currAns = solveHelper(left,i,A) + solveHelper(i,right,A);

		currAns += A[left]*A[i] * A[right];
		ans = max(ans,currAns);
	}

	return ans;
}

int Solution::solve(vector<int> &A) {

	if (A.size() < 1) {
		return 0;
	}
	vector<int> ballons(A.size()+2);
	int indx = 0;
	ballons[indx++] = 1;
	for(int ele : A) {
		ballons[indx++] = ele;
	}
	ballons[indx] = 1;

	return solveHelper(0, A.size()+1, ballons);
}
