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
ll MOD = 1e9+7;

int Solution::solve(vector<int> &A) {

  int start = 0;
  int n = A.size();

  ll ans = 0;
  unordered_set<int> s;
  for(int end = 0;end<n; end++) {

    while(start < n && s.find(A[end]) != s.end()) {
      s.erase(A[start]);
      start++;
    }
    
    s.insert(A[end]);

    ll currAns = ((end-start) + 1) % MOD;
    ans = (ans%MOD + currAns%MOD) % MOD;

  }

  return ans;    
}
