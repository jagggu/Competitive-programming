int Solution::solve(vector<int> &A, vector<int> &B) {

	unordered_set<pair<int,int> > s;
	for(int i = 0;i<A.size();i++) {
		pair<int,int> p;
		p = make_pair(A[i],B[i]);
		s.insert(p);
	}
	int n = A.size();
	int ans = 0;
	for(int i = 0;i<n;i++) {
		for(int j = i+1;i<n;i++) {
			if(A[i] == A[j] || B[i] == B[j]) {
				continue;
			}

			pair<int,int> p1,p2;
			p1 = make_pair(A[i],B[j]);
			p2 = make_pair(A[j],B[i]);

			if(s.find(p1) != s.end() && s.find(p2) != s.end()) {
				ans++;
			}
		}
	}
	return ans;
}
