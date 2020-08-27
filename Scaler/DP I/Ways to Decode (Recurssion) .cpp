
vector<int> ways;

int numDecodingsHelper(string A, int start, int end) {
	if(start == end) {
		return 1;
	}

	if(start > end) {
		return 0;
	}

	if(A[start] == '0') {
		return 0;
	}

	if(ways[start] != -1) {
		return ways[start];
	}

	int ans1 = 0;
	int ans2 = 0;

	ans1 = numDecodingsHelper(A,start+1,end);

	if(start != end-1) {
		int num = (A[start] - '0') * 10 + (A[start+1]-'0');
		if(num <= 26) {
			ans2 = numDecodingsHelper(A,start+2,end);
		}
	}
    //cout<<"Ans: "<<ans1<<' '<<ans2<<' '<<start<<' '<<end<<endl;
	return ways[start] = ans1 + ans2;
}

int Solution::numDecodings(string A) {
	int n = A.size();

	if(n<1) {
		return 0;
	}

	ways.clear();
	for(int i = 0;i<=n; i++) {
		ways.push_back(-1);
	}

	int ans = numDecodingsHelper(A,0,n);

	return ans;
}
