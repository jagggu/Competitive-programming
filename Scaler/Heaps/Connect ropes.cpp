/*
Connect ropes
Problem Description
Given an array of integers A representing the length of ropes. You need to connect these ropes into one rope. The cost of connecting two ropes is equal to the sum of their lengths. Find and return the minimum cost to connect these ropes into one rope.   


Problem Constraints
1 <= length of the array <= 100000
1 <= A[i] <= 1000


Input Format
The only argument given is the integer array A.


Output Format
Return an integer denoting the minimum cost to connect these ropes into one rope.


Example Input
Input 1:
 A = [1, 2, 3, 4, 5]
Input 2:
 A = [5, 17, 100, 11]
  


Example Output
Output 1:
 33
Output 2:
 182
  


Example Explanation
Explanation 1:
 Given array A = [1, 2, 3, 4, 5].
 Connect the ropes in the following manner:
 1 + 2 = 3
 3 + 3 = 6
 4 + 5 = 9
 6 + 9 = 15

 So, total cost  to connect the ropes into one is 3 + 6 + 9 + 15 = 33.
Explanation 2:
 Given array A = [5, 17, 100, 11].
 Connect the ropes in the following manner:
 5 + 11 = 16
 16 + 17 = 33
 33 + 100 = 133

 So, total cost  to connect the ropes into one is 16 + 33 + 133 = 182.

 */


class Heap {
	vector<int> arr;
	int heapSize;

	public:
		Heap(vector<int> &A) {
			arr = A;
			heapSize = A.size();
		} 

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

			if(left < heapSize && arr[left] < arr[smallest]) {
				smallest = left;
			}

			if(right < heapSize && arr[right] < arr[smallest]) {
				smallest = right;
			}

			if(smallest != i) {
				swap(arr[i], arr[smallest]);
				percolateDown(smallest);
			}
		}

		void constructMinHeap() {
			for(int i = heapSize-1;i>=0;i--) {
				percolateDown(i);
			}
		}

		void deleteRoot() {
			swap(arr[0],arr[heapSize-1]);
			heapSize--;
			percolateDown(0);
		}

		void percolateUp(int i) {
			while(i>0 && arr[i]<arr[parent(i)]) {
				swap(arr[i],arr[parent(i)]);
				i = parent(i);
			}
		}

		void insert(int num) {
		    heapSize++;
			arr[heapSize-1] = num;
			percolateUp(heapSize-1);
		}

		int findAns() {
			int ans = 0;

			while(heapSize > 1) {
				int min1 = arr[0];
				deleteRoot();
				int min2 = arr[0];
				deleteRoot();

				ans = ans + min1 + min2;

				insert(min1+min2);
			}
			
			return ans;
		}

		
};

int Solution::solve(vector<int> &A) {

	Heap hp = Heap(A);
	hp.constructMinHeap();

	int ans = hp.findAns();

	return ans;
}
