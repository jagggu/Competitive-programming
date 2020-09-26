int Solution::solve(vector<int> &A) {

	int minEle = INT_MAX;
	int maxEle = INT_MIN;

	for(int ele : A) {
		minEle = min(minEle,ele);
		maxEle = max(maxEle,ele);
	}

	return minEle + maxEle;
}
