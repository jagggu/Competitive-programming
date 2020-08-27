
int solveHelper(const vector<int> &A, int sum, int i) {
	if(i<0 || sum<0) {
		return INT_MAX;
	}

	return min(1+solveHelper(A,sum-A[i],i-1),solveHelper(A,sum,i));
}

int Solution::solve(const vector<int> &A) {

	int sum = 0;
	for(int ele : A) {
		sum+=ele;
	}

	return solveHelper(A,sum,A.size()-1);
}
