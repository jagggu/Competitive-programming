/*
Maximum array sum after B negations
Problem Description
Given an array of integers A and an integer B. You must modify the array exactly B number of times. In single modification, we can replace any one array element A[i] by -A[i]. You need to perform these modifications in such a way that after exactly B modifications, sum of the array must be maximum.  


Problem Constraints
1 <= length of the array <= 5*105
1 <= B <= 5 * 106
-100 <= A[i] <= 100


Input Format
First argument given is an integer array A.
Second argument given is an integer B.


Output Format
Return an integer denoting the maximum array sum after B modifications.


Example Input
Input 1:
 A = [24, -68, -29, -9, 84]
 B = 4
Input 2:
 A = [57, 3, -14, -87, 42, 38, 31, -7, -28, -61]
 B = 10


Example Output
Output 1:
 196
Output 2:
 362


Example Explanation
Explanation 1:
 Final array after B modifications = [24, 68, 29, -9, 84]
Explanation 2:
 Final array after B modifications = [57, -3, 14, 87, 42, 38, 31, 7, 28, 61]

*/


class Heap {
	vector<int> minHeap;
	int heapSize;

	int leftChild(int i) {
		int l = 2*i+1;
		return l;
	}

	int rightChild(int i) {
		int r = 2*i+2;
		return r;
	}

	int parent(int i) {
		int p = (i-1)/2;
		return p;
	}

	void percolateDown(int i) {
		int left = leftChild(i);
		int right = rightChild(i);

		int smallest = i;

		if(left < heapSize && minHeap[left] < minHeap[smallest]) {
			smallest = left;
		}

		if(right < heapSize && minHeap[right] < minHeap[smallest]) {
			smallest = right;
		}

		if(smallest != i) {
			swap(minHeap[i],minHeap[smallest]);
			percolateDown(smallest);
		}
	}

	void constructMinHeap() {
		for(int i = heapSize-1;i>=0;i--) {
			percolateDown(i);
		}
	}

	void deleteRoot() {
		swap(minHeap[0],minHeap[heapSize-1]);
		heapSize--;
		percolateDown(0);
	}

	void percolateUp(int i) {
		while(i>0 && minHeap[i]<minHeap[parent(i)]) {
			swap(minHeap[i],minHeap[parent(i)]);
			i = parent(i);
		}
	}

	void insert(int num) {
		heapSize++;
		minHeap[heapSize-1] = num;
		percolateUp(heapSize-1);
	}

public:
	Heap(vector<int> &A) {
		minHeap = A;
		heapSize = A.size();
		constructMinHeap();
	}

	int findAns(int countOps) {
		for(int i = 0;i<countOps;i++) {
			int minEle = minHeap[0];
			deleteRoot();
			insert(-1*minEle);
		}

		int ans = 0;
		for(int i = 0;i<heapSize;i++) {
			ans = ans + minHeap[i];
		}

		return ans;
	}
	
};


int Solution::solve(vector<int> &A, int B) {

	Heap hp = Heap(A);
	int ans = hp.findAns(B);

	return ans;
}
