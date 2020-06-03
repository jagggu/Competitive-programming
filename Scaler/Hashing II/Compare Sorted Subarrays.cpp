
#define ll long long int

ll findSum(vector<int> &A, unordered_map<int,int> &m, int l, int r) {
	ll sum = 0;
	ll mod = 1e9+7;
	for(int i = l;i<=r; i++) {
		sum = (sum%mod + m[A[i]]%mod) % mod;
	}
	return sum%mod;
}

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {

	vector<int> res;
	ll mod = 1e9 + 7;
	unordered_map<int,int> m;
	for(int ele : A) {
		m[ele] = rand() % mod;
	}
		
	for(int i = 0;i<B.size();i++) {
		ll sum1 = findSum(A,m,B[i][0],B[i][1]);
		ll sum2 = findSum(A,m,B[i][2],B[i][3]);
		if(sum1 == sum2) {
			res.push_back(1);
		} else {
			res.push_back(0);
		}
	}

	return res;
}
