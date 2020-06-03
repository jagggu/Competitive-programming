/*
Magician and Chocolates
Problem Description
Given N bags, each bag contains Bi chocolates. There is a kid and a magician. In one unit of time, kid chooses a random bag i, eats Bi chocolates, then the magician fills the ith bag with floor(Bi/2) chocolates. Find the maximum number of chocolates that kid can eat in A units of time. NOTE:
floor() function returns the largest integer less than or equal to a given number.
Return your answer modulo 109+7
     


Problem Constraints
1 <= N <= 100000
0 <= B[i] <= INT_MAX
0 <= A <= 105


Input Format
First argument is an integer A.
Second argument is an integer array B of size N.


Output Format
Return an integer denoting the maximum number of chocolates that kid can eat in A units of time.


Example Input
Input 1:
 A = 3
 B = [6, 5]
Input 2:
 A = 5
 b = [2, 4, 6, 8, 10]
    


Example Output
Output 1:
 14
Output 2:
 33
    


Example Explanation
Explanation 1:
 At t = 1 kid eats 6 chocolates from bag 0, and the bag gets filled by 3 chocolates. 
 At t = 2 kid eats 5 chocolates from bag 1, and the bag gets filled by 2 chocolates. 
 At t = 3 kid eats 3 chocolates from bag 0, and the bag gets filled by 1 chocolate. 
 so, total number of chocolates eaten are 6 + 5 + 3 = 14
Explanation 2:
 Maximum number of chocolates that can be eaten is 33.

 */




#define ll long long int
ll MOD = 1000000007;

class Heap {
	int heapSize;
	vector<int> arr;

public:

	Heap(int size, vector<int> &A) {
		heapSize = size;
		arr = A;
	}

	int parent(int i) {

		int p = (i-1)/2;
		return p;
	}

	int leftChild(int i) {
		int l = 2*i + 1;
		return l;
	}

	int rightChild(int i) {
		int r = 2*i + 2;
		return r;
	}

	void percolateDown(int i) {

		int left = leftChild(i);
		int right = rightChild(i);

		int largest = i;

		if(left<heapSize && arr[left]>arr[largest]) {
			largest = left;
		}

		if(right<heapSize && arr[right]>arr[largest]) {
			largest = right;
		}

		if(largest != i) {
			swap(arr[i],arr[largest]);
			percolateDown(largest);
		}
	}

	void constructMaxHeap() {
		for(int i = heapSize-1;i>=0;i--){
			percolateDown(i);
		}
	}

	void deleteRoot() {
		swap(arr[0],arr[heapSize-1]);
		heapSize--;
		percolateDown(0);
	}

	void percolateUp(int i) {
		while(i>0 && arr[i]>arr[parent(i)]) {
			swap(arr[i],arr[parent(i)]);
			i = parent(i);
		}
	}

	ll findAns(int freq) {
		ll ans = 0;
		for(int i = 0;i<freq;i++) {
			ll tmp = arr[0];
			ans  = (ans%MOD + tmp%MOD) % MOD;
			deleteRoot();
			heapSize++;
			arr[heapSize-1] = tmp/2;
			percolateUp(heapSize-1);

		}

		return ans%MOD;
	}

};

int Solution::nchoc(int A, vector<int> &B) {

	int n = B.size();

	Heap hp = Heap(n,B);
	hp.constructMaxHeap();

	ll ans = hp.findAns(A);

	return ans%MOD;

}
