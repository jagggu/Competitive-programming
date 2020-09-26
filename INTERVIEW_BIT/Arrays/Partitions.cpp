/*
Problem Description

You are given a 1D integer array B containing A integers.

Count the number of ways to split all the elements of the array into 3 contiguous parts so that the sum of elements in each part is the same.

Such that : sum(B[1],..B[i]) = sum(B[i+1],...B[j]) = sum(B[j+1],...B[n])



Problem Constraints
1 <= A <= 105

-109 <= B[i] <= 109



Input Format
First argument is an integer A.

Second argument is an 1D integer array B of size A.



Output Format
Return a single integer denoting the number of ways to split the array B into three parts with the same sum.



Example Input
Input 1:

 A = 5
 B = [1, 2, 3, 0, 3]
Input 2:

 A = 4
 B = [0, 1, -1, 0]


Example Output
Output 1:

 2
Output 2:

 1


Example Explanation
Explanation 1:

 There are no 2 ways to make partitions -
 1. (1,2)+(3)+(0,3).
 2. (1,2)+(3,0)+(3).
Explanation 2:

 There is only 1 way to make partition -
 1. (0)+(-1,1)+(0).


*/


#define ll long long int

int binarySearch(vector<int> &arr, int target) {
	int ans = arr.size();
	int start = 0;
	int end = arr.size() - 1;

	while(start <= end) {
		int mid = start + (end-start)/2;

		if(arr[mid] <= target) {
			start = mid+1;
		} else {
			ans = mid;
			end = mid-1;
		}
	}

	return ans;
}

int Solution::solve(int A, vector<int> &B) {

	ll totalSum = 0;
	for(ll ele : B) {
		totalSum += ele;
	}

	if(totalSum%3 != 0) {
		return 0;
	}

	ll requiredSum = totalSum/3;


	int n = A;
	vector<ll> prefix(A);
	vector<ll> suffix(A);
	prefix[0] = B[0];
	
	for(int i = 1;i<A;i++) {
		prefix[i] = prefix[i-1] + B[i];
	}

	suffix[n-1] = B[n-1];
	for(int i = n-2;i>=0;i--) {
		suffix[i] = suffix[i+1] + B[i];
	}

	vector<int> arr;
	for(int i = 0;i<n; i++) {
		if(suffix[i] == requiredSum) {
			arr.push_back(i);
		}
	}

	int ans = 0;
	
	
	
	//cout<<endl;

	for(int i = 0; i<n; i++) {

		if(prefix[i] == requiredSum) {

			int t = binarySearch(arr,i+1);
			//cout<<"T: "<<t<<' '<<i+1<<endl;

			ans += (arr.size() - t);
		}
	}

	return ans;
}
