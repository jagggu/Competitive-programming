/*
B-th Smallest Prime Fraction
Problem Description
A sorted array of integers, A contains 1, plus some number of primes. Then, for every p < q in the list, we consider the fraction p/q. What is the B-th smallest fraction considered? Return your answer as an array of integers, where answer[0] = p and answer[1] = q.  


Problem Constraints
1 <= length(A) <= 2000 
1 <= A[i] <= 30000 
1 <= B <= length(A)*(length(A) - 1)/2


Input Format
The first argument of input contains the integer array, A.
The second argument of input contains an integer B.


Output Format
Return an array of two integers, where answer[0] = p and answer[1] = q.


Example Input
Input 1:
 A = [1, 2, 3, 5]
 B = 3
Input 2:
 A = [1, 7]
 B = 1
 


Example Output
Output 1:
 [2, 5]
Output 2:
 [1, 7]
 


Example Explanation
Explanation 1:
 The fractions to be considered in sorted order are:
 [1/5, 1/3, 2/5, 1/2, 3/5, 2/3]
 The third fraction is 2/5.
Explanation 2:
 The fractions to be considered in sorted order are:
 [1/7]
 The first fraction is 1/7.
*/


struct Fraction {
	int p;
	int q;
	double frac;
};

class Heap {

	vector<Fraction> minHeap;
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

		if(left < heapSize && minHeap[left].frac < minHeap[smallest].frac) {
			smallest = left;
		}

		if(right < heapSize && minHeap[right].frac < minHeap[smallest].frac) {
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

public:
	Heap(vector<int> &A) {
		int n = A.size();

		for(int i = 0;i<n;i++) {
			for(int j = n-1;j>i;j--) {
				Fraction f;
				double val = A[i]/(double)A[j];
				f.p = A[i];
				f.q = A[j];
				f.frac = val;
				minHeap.push_back(f);
			}
		}

		heapSize = minHeap.size();
		constructMinHeap();
	}

	vector<int> findAns(int k) {
		vector<int> res;
		for(int i = 1;i<k;i++) {
		    Fraction f = minHeap[0];
		    //cout<<f.p<<' '<<f.q<<' '<<f.frac<<endl;
			deleteRoot();
		}

		Fraction f = minHeap[0];
		res.push_back(f.p);
		res.push_back(f.q);

		return res;
	}
};

vector<int> Solution::solve(vector<int> &A, int B) {

	Heap hp = Heap(A);

	vector<int> res = hp.findAns(B);

	return res;

}
