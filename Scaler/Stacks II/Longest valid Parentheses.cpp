/*
Longest valid Parentheses
Problem Description

Given a string A containing just the characters '(' and ')'.

Find the length of the longest valid (well-formed) parentheses substring.



Problem Constraints
1 <= length(A) <= 750000



Input Format
The only argument given is string A.



Output Format
Return the length of the longest valid (well-formed) parentheses substring.



Example Input
Input 1:

 A = "(()"
Input 2:

 A = ")()())"


Example Output
Output 1:

 2
Output 2:

 4


Example Explanation
Explanation 1:

 The longest valid parentheses substring is "()", which has length = 2.
Explanation 2:

 The longest valid parentheses substring is "()()", which has length = 4.


*/




int Solution::longestValidParentheses(string A) {

	stack<int> s;
	int maxLen = 0;
	s.push(-1);
	for(int i = 0;i<A.size();i++) {
		if(A[i] == ')') {
			if(s.top() == -1) {
				s.push(i);
			} else if(A[s.top()] == '(') {
				s.pop();
				int currLen = i-s.top();
				maxLen = max(maxLen,currLen);
			} else {
			    s.push(i);
			}
		} else {
			s.push(i);
		}
	}

	return maxLen;
}
