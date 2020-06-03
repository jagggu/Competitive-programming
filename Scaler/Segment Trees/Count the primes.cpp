vector<int> segTree;
#define ll long long int

vector<bool> sieve(int maxEle) {

	vector<bool> primes(1000007, true);
	primes[0] = false;
	primes[1] = false;

	for(ll i = 2; i < (maxEle+3); i++) {
		if(primes[i]) {
			for(ll j = i*i; j<(maxEle+3);j+=i) {
				primes[j] = false;
			}
		}
	}

	return primes;
}

void buildTree(int node, int start, int end, vector<int> &A) {
	if(start == end) {
		segTree[node] = A[start];
		return;
	}

	int mid = start + (end-start)/2;

	buildTree(2*node,start,mid,A);
	buildTree(2*node+1,mid+1,end,A);

	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

void update(int node, int start, int end, int indx, int val) {
	if(start == end) {
		segTree[node] = val;
		return;
	}

	int mid = start + (end-start)/2;

	if(start<=indx && indx<=mid) {
		update(2*node, start,mid,indx,val);
	} else {
		update(2*node+1,mid+1,end,indx,val);
	}

	segTree[node] = segTree[2*node] + segTree[2*node+1];
}

int query(int node, int start, int end, int l, int r) {
	if(r < start || end < l) {
		return 0;
	}

	if(l<=start && end<=r) {
		return segTree[node];
	}

	int mid = start + (end-start)/2;

	int left = query(2*node,start,mid,l,r);
	int right = query(2*node+1,mid+1,end,l,r);

	return left+right;
}

vector<int> Solution::solve(vector<int> &A, vector<string> &B, vector<int> &C, vector<int> &D) {

	int n = A.size();
	segTree.clear();
	segTree.resize(4*n);
	
	for(int i = 0;i<(4*n); i++) {
		segTree[0];
	}
	
	vector<int> res;
	if(n<1) {
		return res;
	}

	int maxEle = INT_MIN;
	for(auto ele : A) {
		maxEle = max(maxEle, ele);
	}

	vector<bool> primes = sieve(maxEle);

	for(int i = 0;i<n;i++) {
		if(primes[A[i]]) {
			A[i] = 1;
		} else {
			A[i] = 0;
		}
	}

	buildTree(1,0,n-1,A);

	for(int i = 0;i<B.size(); i++) {
		string q = B[i];
		int l = C[i];
		int r = D[i];

		if(q == "C") {
			int val;
			if(primes[r]) {
				val = 1;
			} else {
				val = 0;
			}

			update(1,0,n-1,l-1,val);
		} else {
			int ans = query(1,0,n-1,l-1,r-1);
			res.push_back(ans);
		}

	}

	return res;
}
