/*
Shaggy and distances
Shaggy has an array A consisting of N elements. We call a pair of distinct indices in that array as a special pair if elements at that index in the array are equal.  Shaggy wants you to find a special pair such that distance between that pair is minimum. Distance between two indices is defined as |i-j|. If there is no special pair in the array then return -1. Constraints:
Number of testcases : 1 <= T <= 5 
Length of the array : 1 <= N <= 1000
Input:
An integer array A
Note:
Your code will run against multiple testcases.
Output:
Return one integer corresponding to the minimum possible distance between a special pair.
Examples: Input:
7 1 3 4 1 7 
Output:
3
Explanation:
Here we have 2 options:
1. a[1] and a[4] are both 1 so (1,4) is a special pair and |1-4|=3
2. a[0] and a[5] are both 7 so (0,5) is a special pair and |0-5|=5

Therefore the minimum possible distance is 3. 
×
*/


int Solution::solve(vector<int> &A) {

	int ans = INT_MAX;
	unordered_map<int,int> m;
	int n = A.size();
	for(int i = 0;i<n;i++) {
		if(m.find(A[i]) != m.end()) {
			ans = min(ans, i-m[A[i]]);
		}
		m[A[i]] = i;
	}
	if(ans == INT_MAX) {
		return -1;
	}
	return ans;
}
