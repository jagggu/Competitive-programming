
int findNextGreater(vector<int> &A, int ele, int index) {
	int n = A.size();

	for(int i = n-1;i>=index;i--) {
		if(A[i] > ele) {
			return i;
		}
	}
}

vector<int> Solution::nextPermutation(vector<int> &A) {

	int n = A.size();

	int index = n-2;

	while(index >= 0) {
		if(A[index] < A[index+1]) {
			break;
		}
		index--;
	}

	if(index == -1) {
		reverse(A.begin(),A.end());
	}

	int nextGreaterIndex = findNextGreater(A,A[index],index+1);

	swap(A[index],A[nextGreaterIndex]);

	sort(A.begin()+index+1,A.end());
	return A;
}
