/*
Count Subarrays
Problem Description
Misha likes finding all Subarrays of an Array. Now she gives you an array A of N elements and told you to find the number of subarrays of A, that have unique elements. Since the number of subarrays could be large, return value % 109 +7. 


Problem Constraints
1 <= N <= 105 1 <= A[i] <= 106  


Input Format
The only argument given is an Array A, having N integers.


Output Format
Return the number of subarrays of A, that have unique elements.


Example Input
A = [1, 1, 3]


Example Output
4


Example Explanation
Subarrays of A that have unique elements only:
[1], [1], [1, 3], [3]

*/



#define ll long long int


int Solution::solve(vector<int> &A) {

	set<int> s;
	ll ans = 0;
	ll mod = 1000000007;
	int n = A.size();
	 int j = 0;
	 ll sameEles = 0;
	for(int i = 0; i<n; i++) {

		if(s.find(A[i]) != s.end()) {
			ll tmp = ((i-j)/2.0) * (i-j+1);
			ans = (ans%mod + tmp%mod)%mod;
			while(s.find(A[i]) != s.end()) {
				s.erase(A[j]);
				j++;
			}

			tmp = ((i-j)/2.0) * (i-j+1);
			ans = ans - tmp;
			s.insert(A[i]);
			
		} else { 
		s.insert(A[i]);
		}
	
	}

	ll tmp = n-j;
	ll tmpAns = (tmp/2.0) *(tmp+1);
	ans = (ans%mod + tmpAns%mod)%mod;
	return ans;
}
