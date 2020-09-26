int Solution::solve(vector<int> &A) {

	int n = A.size();

	int start = 0;
	int end = n-1;

	while(start <= end) {
		int mid = start + (end-start)/2;

		if(mid != 0 && A[mid]<A[mid-1]) {
			end = mid-1;
		} else if(mid != n-1 && A[mid] < A[mid+1]) {
			start = mid+1;
		} else {
			return A[mid];
		}
	}
}
