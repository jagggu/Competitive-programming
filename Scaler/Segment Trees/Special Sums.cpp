#define ll long long int
vector<pair<ll,ll> > segTree;
ll  mod = 1000000007;
void buildTree(int node, int start, int end, vector<int> &A) {
	if(start == end) {
		segTree[node] = make_pair((start+1)*A[start],A[start]);
		return;
	}

	int mid = start + (end-start)/2;

	buildTree(2*node,start,mid,A);
	buildTree(2*node+1,mid+1,end,A);
	ll a = ((segTree[2*node].first)%mod + (segTree[2*node+1].first)%mod)%mod;
	ll b = ((segTree[2*node].second)%mod + (segTree[2*node+1].second)%mod)%mod;
	segTree[node] = make_pair(a,b);
}

void update(int node, int start, int end, int indx, int val) {
	if(start == end) {
		segTree[start] = val;
		return;
	}

	int mid = start + (end-start)/2;

	if(start<=indx && indx<=end) {
		update(2*node,start,mid,indx,val);
	} else {
		update(2*node+1,mid+1,end,indx,val);
	}

	ll a = (segTree[2*node].first%mod + segTree[2*node+1].first%mod)%mod;
	ll b = (segTree[2*node].second%mod + segTree[2*node+1].second%mod)%mod;
	segTree[node] = make_pair(a,b);
}

pair<ll,ll> query(int node, int start, int end, int l, int r) {
	if(start == end) {
		return segTree[start];
	}
	if(r<start || end < l) {
		return make_pair(0,0);
	}

	if(l<=start && end<=r) {
		return segTree[node];
	}
	int mid = start + (end-start)/2;
	pair<ll,ll> a = query(2*node,start,mid,l,r);
	pair<ll,ll> b = query(2*node+1,mid+1,end,l,r);

	ll p1 = a.first+b.first;
	ll p2 = a.second+b.second;
	return make_pair(p1,p2);

}

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {

	segTree.clear();
	int n = A.size();
	segTree.resize(4*n);
	vector<int> res;
	buildTree(1,0,n-1,A);

	for(int i = 0;i<B.size();i++) {
		if(B[i][0] == 1) {
			update(1,0,n-1,B[i][1]-1,B[i][2]);
		} else {
			pair<ll,ll> tmp = query(1,0,n-1,B[i][1]-1,B[i][2]-1);

			ll ans = ((tmp.first%mod) + ((1-B[i][1])%mod * tmp.second%mod)%mod)%mod;
			res.push_back(ans);
		}
	}
	return res;
}
