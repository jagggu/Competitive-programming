/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers.

Assume that there will only be one solution

Example: 
given array S = {-1 2 1 -4}, 
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/


#define ll long long int

int Solution::threeSumClosest(vector<int> &A, int B) {
	int n = A.size();
	ll ans = INT_MAX;
	sort(A.begin(),A.end());

	for(int i = 0;i<n-2;i++) {
		int start = i+1;
		int end = n-1;

		while(start < end) {
			ll tmp = A[i] + A[start] + A[end];
			if(abs(tmp-B) < abs(ans-B)) {
				ans = tmp;
			}
			if(tmp > B) {
				end--;
			} else {
				start++;
			}
		}
	}

	return ans;
}
