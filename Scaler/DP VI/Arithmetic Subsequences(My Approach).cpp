


//This approach doesn't work for duplicates

int Solution::solve(vector<int> &A) {
	set<int> s;
	int ans = 0;
	if(A.size() < 3) {
		return 0;
	}
	s.insert(A[0]);
	s.insert(A[1]);
	for(int i = 2;i<A.size();i++) {
		for(int j = 1;j<i;j++) {
			int diff = A[i]-A[j];
			int currNum = A[j]-diff;
			while(s.find(currNum) != s.end()) {
				ans++;
				currNum = currNum-diff;
			}
		}

		s.insert(A[i]);
	}
}
