/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

*/



vector<int> Solution::maxone(vector<int> &A, int B) {

	int start = 0;
	int zeroCnt = 0;
	int n = A.size();
	int ansStart,ansEnd;
	int maxLen = -1;
	for(int end = 0;end<n; end++) {
		if(A[end] == 0) {
			zeroCnt++;
		}

		while(start < n && zeroCnt > B) {
			if(A[start] == 0) {
				zeroCnt--;
			}
			start++;
		}

		int len = end-start;

		if(len > maxLen) {
			ansStart = start;
			ansEnd = end;
			maxLen = len;
		}

	}

	vector<int> res;
	for(int i = ansStart; i<= ansEnd; i++) {
		res.push_back(i);
	}

	return res;
}
