/*
Matrix Median
Problem Description

Given a matrix of integers A of size N x M in which each row is sorted.

Find and return the overall median of the matrix A.

NOTE: No extra memory is allowed.

NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N, M <= 10^5

1 <= N*M <= 10^6

1 <= A[i] <= 10^9

N*M is odd



Input Format
The first and only argument given is the integer matrix A.



Output Format
Return the overall median of the matrix A.



Example Input
Input 1:

A = [   [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]   ]
Input 2:

A = [   [5, 17, 100]    ]


Example Output
Output 1:

 5
Output 2:

 17


Example Explanation
Explanation 1:

 
A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
Median is 5. So, we return 5.
Explanation 2:

 
Median is 17.


*/



int findGreaterIndex(vector<int> &arr, int target) {
	int n = arr.size();

	int start = 0;
	int end = n-1;
    int ans = n;
    
    //cout<<start<<' '<<end<<' '<<target<<endl;
    
	while(start <= end) {
		int mid = start + (end-start)/2;

		if(arr[mid] > target) {
			ans = mid;
			end = mid-1;
		} else {
			start = mid+1;
		}

	}

	return ans;
}

int findLesserElements(vector<vector<int> > &A, int target) {
	int rows = A.size();
	int cols = A[0].size();

	int ans = 0;

	for(int i = 0;i<rows;i++) {
		int index = findGreaterIndex(A[i],target);
		//cout<<"Index: "<<index<<endl;
		ans += index;
	}

	return ans;
}

int Solution::findMedian(vector<vector<int> > &A) {

	int minEle = INT_MAX;
	int maxEle = INT_MIN;

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	for(int i = 0;i<rows;i++) {
		minEle = min(minEle, A[i][0]);
		maxEle = max(maxEle, A[i][cols-1]);
	}

	int start = minEle;
	int end = maxEle;

	int totalEles = rows*cols;

	int ans = 0;

	while(start <= end) {
		int mid = start + (end-start)/2;

		int lesserEles = findLesserElements(A,mid);
		
		//cout<<mid<<' '<<lesserEles<<endl;

		if(lesserEles >= ((totalEles/2)+1)) {
			ans = mid;
			end = mid-1;
		} else {
			start = mid + 1;
		}
	}

	return ans;
}
