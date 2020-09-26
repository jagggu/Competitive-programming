/*
Problem Description

Given a bitonic sequence A of N distinct elements, write a program to find a given element B in the bitonic sequence in O(logN) time.

NOTE:

A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.


Problem Constraints
3 <= N <= 105

1 <= A[i], B <= 108

Given array always contain a bitonic point.

Array A always contain distinct elements.



Input Format
First argument is an integer array A denoting the bitonic sequence.

Second argument is an integer B.



Output Format
Return a single integer denoting the position (0 index based) of the element B in the array A if B doesn't exist in A return -1.



Example Input
Input 1:

 A = [3, 9, 10, 20, 17, 5, 1]
 B = 20
Input 2:

 A = [5, 6, 7, 8, 9, 10, 3, 2, 1]
 B = 30


Example Output
Output 1:

 3
Output 2:

 -1


Example Explanation
Explanation 1:

 B = 20 present in A at index 3
Explanation 2:

 B = 30 is not present in A

 */



int findPeak(vector<int> &arr) {
	int n = arr.size();
	int start = 0;
	int end = n-1;

	while(start <= end) {
		int mid = start + (end-start)/2;
		if(mid != 0  && arr[mid] < arr[mid-1]) {
			end = mid-1;
		} else if(mid != (n-1) && arr[mid] < arr[mid+1]){
			start = mid + 1;
		} else {
			return mid;
		}
	}
}

int findEleSorted(vector<int> &arr, int target, int start, int end){

	while(start <= end) {
		int mid = start + (end -start)/2;
		if(arr[mid] == target) {
			return mid;
		} else if(arr[mid] < target) {
			start = mid+1;
		} else {
			end = mid-1;
		}
	}

	return -1;
}

int findEleReversed(vector<int> &arr, int target, int start, int end) {

	while(start <= end) {
		int mid = start + (end-start)/2;
		if(arr[mid] == target) {
			return mid;
		} else if(arr[mid] < target) {
			end = mid-1;
		} else {
			start = mid+1;
		}
	}

	return -1;
}

int Solution::solve(vector<int> &A, int B) {

	int n = A.size();
	int target = B;

	

	int peakIndex = findPeak(A);

	int index = findEleSorted(A,B,0,peakIndex);
	if(index != -1) {
		return index;
	}

	return findEleReversed(A,B,peakIndex+1,n-1);
}
