
vector<int> segTree;

void buildTree(int node , int start, int end) {
	if (start == end) {
		segTree[node] = 1;
		return;
	}
	int mid = start + (end - start) / 2;
	buildTree(2 * node, start, mid);
	buildTree(2 * node + 1, mid + 1, end);
	segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

void update(int node, int start, int end, int indx) {
	if (start == end) {
		segTree[node] = 0;
		return;
	}

	int mid = start + (end - start) / 2;
	if (start <= indx && indx <= mid) {
		update(2 * node, start, mid, indx);
	} else {
		update(2 * node + 1, mid + 1, end, indx);
	}

	segTree[node] = segTree[2 * node] + segTree[2 * node + 1];

}

int query(int node, int start, int end, int k) {

	if (segTree[node] < k) {
		return -1;
	}

	if (start == end) {
		return start;
	}

	int mid = start + (end - start) / 2;

	int leftOnes = segTree[2 * node];
	if (leftOnes >= k) {
		return query(2 * node, start, mid, k);
	} else {
		return query(2 * node + 1, mid + 1, end, k - leftOnes);
	}
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {

	segTree.clear();
	segTree.resize(4 * A);

	buildTree(1, 0, A - 1);

	vector<int> res;

	for (int i = 0; i < B.size(); i++) {
		if (B[i][0] == 0) {
			update(1, 0, A - 1, B[i][1] - 1);
		} else {
			int ans = query(1, 0, A - 1, B[i][1]);
			if (ans != -1) {
				ans++;
			}
			res.push_back(ans);
		}
	}

	return res;
}
