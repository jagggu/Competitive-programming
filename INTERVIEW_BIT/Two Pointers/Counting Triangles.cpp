/*
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.
Considering each array element Ai as the edge length of some line segment, count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4

*/


#define ll long long int

ll MOD = 1e9 + 7;

int Solution::nTriang(vector<int> &A) {

	ll ans = 0;
	
	sort(A.begin(),A.end());

	int n = A.size();
	for(int i = n-1;i>=0;i--) {

		int start = 0;
		int end = i-1;

		while(start < end) {
			ll currSum = (long long)A[start] + (long long)A[end];

			if(currSum > A[i]) {
				ans = (ans%MOD + (end-start)%MOD) % MOD;
				end--;
			} else {
				start++;
			}
		}
	}

	return ans;

}
