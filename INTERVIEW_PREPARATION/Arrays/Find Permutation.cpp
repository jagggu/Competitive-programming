vector<int> Solution::findPerm(const string A, int B) {

	int minEle = 1;
	int maxEle = B;

	vector<int> res;

	for(int i = B-2;i>=0;i--) {
		if(A[i] == 'I') {
			res.push_back(maxEle);
			maxEle--;
		} else {
			res.push_back(minEle);
			minEle++;
		}
	}

	res.push_back(maxEle);

	reverse(res.begin(),res.end());

	return res; 
}
