
int findIndexOfEle(vector<int> &arr, int target) {
	int start = 0;
	int end = arr.size() - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (arr[mid] == target) {
			return 1;
		} else if (arr[mid] < target) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}

	return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {

	if (A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	for (int i = 0; i < rows; i++) {
		if (B > A[i][cols - 1]) {
			continue;
		}
		if (findIndexOfEle(A[i], B)) {
			return 1;
		}

	}

	return 0;
}
