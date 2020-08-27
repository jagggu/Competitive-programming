
int find(int node, vector<int> &parent) {
	if(node == parent[node]) {
		return node;
	}

	parent[node] = find(parent[node],parent);

	return parent[node];
}

int Solution::solve(vector<int> &A) {

	int n = A.size();
	vector<int> parent(n+1);
	vector<int> size(n+1,1);

	for(int i = 1;i<=n;i++) {
		parent[i] = i;
	}

	for(int i = 0;i<n;i++) {
		int c = find(i,parent);
		int d = find(A[i],parent);

		if(c != d) {
			if(size[c] < size[d]) {
				swap(c,d);
			}
			parent[d] = c;
			size[c]+=size[d];
		}
	}

	int ans = 0;

	for(int i = 1;i<=n;i++) {
		if(parent[i] == i) {
			ans++;
		}
	}

	return ans;
}
