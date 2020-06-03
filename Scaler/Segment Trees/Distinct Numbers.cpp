vector<int> segTree;

struct Queries {
	int start;
	int end;
	int indx; 
};

void update(int node, int start, int end, int indx, int val) {
	if(start == end) {
		segTree[node] = val;
		return;
	}

	int mid = start + (end-start)/2;

	if(start<=indx && indx<=end) {
		update(2*node,start,mid,indx,val);
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
	int right = query(2*node+1, mid+1,end,l,r);

	return left+right;
}

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {

	int n = A.size();
	segTree.clear();
	segTree.resize(4*n);

	for(int i = 0;i<(4*n);i++) {
		segTree[i] = 0;
	}

	unordered_map<int,int> lastSeen;

	unordered_map<int,vector<Queries> > q;

	for(int i = 0;i<B.size();i++) {
		Queries tmp;
		tmp.start = B[i][0]-1;
		tmp.end = B[i][1] - 1;
		tmp.indx = i;
		q[B[i][1]-1].push_back(tmp);
	}

	vector<int> res(B.size());

	for(int i = 0;i<n;i++) {
		update(1,0,n-1,i,1);
		if(lastSeen.find(A[i]) != lastSeen.end()) {
			update(1,0,n-1,lastSeen[A[i]],0);
		}
		lastSeen[A[i]] = i;
		for(int j = 0;j<q[i].size();j++) {
			int l = q[i][j].start;
			int r = q[i][j].end;
			int indx = q[i][j].indx;
			int ans = query(1,0,n-1,l,r);
			res[indx] = ans;
		}
	}

	return res;
}