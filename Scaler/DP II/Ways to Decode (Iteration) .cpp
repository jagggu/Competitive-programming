

int Solution::numDecodings(string A) {
	int n = A.size();
	if(n<1) {
		return 0;
	}
	vector<int> ways(n+1,0);

	ways[n] = 1;
	ways[n-1] = A[n-1] == '1'? 1 : 0;

	for(int i = n-2;i>=0;i--) {
		int num = (A[i]-'0') * 10 + (A[i+1]-'0');

		ways[i] = num<=26?ways[i+1]+ways[i+2]:ways[i+1];
	}

	return ways[0];

}
