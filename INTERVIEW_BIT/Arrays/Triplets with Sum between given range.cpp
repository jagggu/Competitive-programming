int Solution::solve(vector<string> &A) {

	int n = A.size();

	if(n < 3) {
		return 0;
	}

	vector<double> arr(n);

	for(int i = 0;i<n;i++) {
		double num = stof(A[i]);
		if(num > 2.0) {
			continue;
		}
		arr[i] = num;
	}

	sort(arr.begin(),arr.end());

	if(arr.size() < 3) {
		return 0;
	}



	if((arr[0] + arr[1] + arr[2]) > 2.0) {
		return 0;
	}

	if((arr[n-1] + arr[n-2] + arr[n-3]) < 1.0) {
		return 0;
	}

	return 1;

}
