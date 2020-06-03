/*
Count A
You are given a string S. Find the number of substrings that start and end with 'a'.  
 Input Format
Given the only argument is a String S.
Output Format
Return number of substrings that start and end with 'a'. 
Constraints
1 <= length(S) <= 1e5
string will have only lowercase English letters.
For Example
Example Input:
    S = "aab"

Example Output:
    3

Explanation 1:
    substrings that start and end with 'a' are:
    1. "a"
    2. "aa"
    3. "a"

  */


#define ll long long int

int Solution::solve(string A) {
	int count = 0;
	for(auto ele : A) {
		if(ele == 'a') {
			count++;
		}
	}
	ll ans = (count/2.0) * (count+1);
	return ans;
}
