#define ll long long int

class Heap {

	vector<int> minHeap;
	int k;

public:
	Heap(int window) {
		k = window;
		minHeap.resize(k + 1);
	}

	int leftChild(int i) {
		int l = 2 * i + 1;
		return l;
	}

	int rightChild(int i) {
		int r = 2 * i + 2;
		return r;
	}

	int parent(int i) {
		int p = (i - 1) / 2;
		return p;
	}

	void percolateUp(int i) {
		while (i > 0 && minHeap[parent(i)] > minHeap[i]) {
			swap(minHeap[i], minHeap[parent(i)]);
			i = parent(i);
		}
	}

	void constructMinHeap(vector<int> &A) {
		for (int i = 0; i < k; i++) {
			minHeap[i] = A[i];
			percolateUp(i);
		}
	}

	void perculateDown(int i) {
		int left = leftChild(i);
		int right = rightChild(i);
		int smallest = i;

		if(left<(k+1) && minHeap[left]<minHeap[smallest]) {
			smallest = left;
		}

		if(right<(k+1) && minHeap[right]<minHeap[smallest]) {
			smallest = right;
		}

		if(smallest != i) {
			swap(minHeap[i],minHeap[smallest]);
			perculateDown(smallest);
		}
	}

	void deleteRoot() {
		swap(minHeap[0],minHeap[k]);
		perculateDown(0);
	}

	vector<int> findAns(vector<int> &A) {
		vector<int> res;
		ll prod = 1;
		for (int i = 0; i < k - 1; i++) {
			prod = prod * A[i];
			res.push_back(-1);
		}
		if (A.size() < 3) {
			return res;
		}

		prod = prod * A[k - 1];
		res.push_back(prod);
		for (int i = k; i < A.size(); i++) {
			int minEle = minHeap[0];
			if (minEle > A[i]) {
				res.push_back(prod);
			} else {

				prod  = prod * A[i];


				minHeap[k] = A[i];

				deleteRoot();
				prod/=minEle;
				res.push_back(prod);
			}
		}

		return res;

	}
};


vector<int> Solution::solve(vector<int> &A) {

	int n = A.size();

	Heap hp = Heap(3);

	hp.constructMinHeap(A);
	vector<int> res = hp.findAns(A);

	return res;
}
