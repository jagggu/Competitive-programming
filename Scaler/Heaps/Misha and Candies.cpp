/*
Misha and Candies
Problem Description
Misha loves eating candies. She has given N boxes of Candies. She decides, every time she will choose a box having the minimum number of candies, eat half of the candies and put the remaining candies in the other box that has the minimum number of candies.
Misha does not like a box if it has the number of candies greater than B so she won't eat from that box. Can you find how many candies she will eat? NOTE 1: If a box has an odd number of candies then Misha will eat floor(odd/2). NOTE 2: A same box will not be chosen again. 


Problem Constraints
1 <= N <= 105 1 <= A[i] <= 105 1 <= B <= 106 


Input Format
The first argument is A an Array of Integers, where A[i] is the number of candies in the ith box.
The second argument is B, the maximum number of candies Misha like in a box.


Output Format
Return an Integer denoting number of candies Misha will eat.


Example Input
Input 1:
 A = [3, 2, 3]
 B = 4
Input 2:
 A = [1,2,1]
 B = 2


Example Output
Output 1:
 2
Output 2:
 1


Example Explanation
Explanation 1:
 1st time Misha will eat from 2nd box, i.e 1 candy she'll eat and will put the remaining 1 candy in the 1st box.
 2nd time she will eat from the 3rd box, i.e 1 candy she'll eat and will put the remaining 2 candies in the 1st box.
 She will not eat from the 3rd box as now it has candies greater than B.
 So the number of candies Misha eat is 2.
Explanation 2:
 1st time Misha will eat from 1st box, i.e she can't eat any and will put the remaining 1 candy in the 3rd box.
 2nd time she will eat from the 3rd box, i.e 1 candy she'll eat and will put the remaining 1 candies in the 2nd box.
 She will not eat from the 2nd box as now it has candies greater than B.
 So the number of candies Misha eat is 1.

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

public:
	Heap(vector<int> &A) {
		minHeap = A;
		heapSize = A.size();
		constructMinHeap();
	}

	int findAns(int maxCandies) {
		int ans = 0;

		while(heapSize > 0) {
			int fisrtMin = minHeap[0];
			if(fisrtMin > maxCandies) {
				return ans;
			}

			ans = ans + (fisrtMin/2);

			if(heapSize <= 1) {
				return ans;
			}

			deleteRoot();
			minHeap[0] = minHeap[0] + (fisrtMin - (fisrtMin/2));
			//int secondMin = minHeap[0];
			//deleteRoot();
			percolateDown(0);
		}

		return ans;
	}


};


int Solution::solve(vector<int> &A, int B) {

	Heap hp = Heap(A);

	int ans = hp.findAns(B);

	return ans;

}
