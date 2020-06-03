/*
Longest Substring Without Repeat
Problem Description
Given a string A, find the length of the longest substring without repeating characters.


Problem Constraints
0 <= size(A) <= 106 String consists of lowerCase,upperCase characters and digits are also present in the string A.   


Input Format
Single Argument representing string A.


Output Format
Single integer denoting the maximum possible length of substring without repeating characters.


Example Input
 A = "abcabcbb"


Example Output
3


Example Explanation
Substring "abc" is the longest substring without repeating characters in string A.


*/


int Solution::lengthOfLongestSubstring(string A) {

	unordered_set<char> s;

	int ans = INT_MIN;

	int start = 0;

	for(int i = 0;i<A.size();i++) {

		while(s.find(A[i]) != s.end()) {
			s.erase(A[start]);
			start++;
		}
		int currLen = i-start+1;
		ans = max(ans,currLen);
		s.insert(A[i]);
	}

	return ans;
}
