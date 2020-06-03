/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 
*/


#define ll long long int

bool isPossible(const vector<int> &A, const vector<int> &B, int tmpAns, int term) {
	ll count = 0;
	count = count + (upper_bound(A.begin(),A.end(),tmpAns) - A.begin());

	count = count + (upper_bound(B.begin(),B.end(),tmpAns) - B.begin());

	return term <= count;
}

ll findKthEle(const vector<int> &A, const vector<int> &B, ll term, ll start, ll end) {

	ll res;

	while(start <= end) {
		ll mid = start + (end-start)/2;
		if(isPossible(A,B,mid,term)) {
			res = mid;
			end = mid-1;
		} else {
			start = mid+1;
		}
	}
	return res;
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	ll start = -1;
	ll end = -1;
	int ALen = A.size();
	int BLen = B.size();
	if(ALen == 0) {
		start = B[0];
		end = B[BLen-1];
	} else if(BLen == 0) {
		start = A[0];
		end = A[ALen-1];
	} else {
		start = min(A[0],B[0]);
		end = max(A[ALen-1],B[BLen-1]);
	}

	ll totalLen = ALen+BLen;
	double ans;

	if(totalLen&1) {
		ll eleTobeFound = (totalLen+1)/2;
		return findKthEle(A,B,eleTobeFound,start,end);
	} else {
		int a = findKthEle(A,B,totalLen/2,start,end);
		ll tmp = (totalLen/2) + 1;
		int b = findKthEle(A,B,tmp,start,end);

		ans = (a+b)/2.0;
		return ans;
	}
}
