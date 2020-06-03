/*
Redundant Braces
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'. Chech whether A has redundant braces or not. Return 1 if A has redundant braces, else return 0. Note: A will be always a valid expression. 
Input Format
The only argument given is string A.
Output Format
Return 1 if string has redundant braces, else return 0.
For Example
Input 1:
    A = "((a + b))"
Output 1:
    1
    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"
Output 2:
    0
    Explanation 2:
        (a + (a + b)) doesn't have have any redundant braces so answer will be 0.

  */


int Solution::braces(string A) {

	stack<char> s;
	for(int i = 0;i<A.size();i++) {
		if(A[i] != ')') {
			s.push(A[i]);
		} else {
			if(s.top() == '(') {
				return 1;
			}
			bool isOperand = false;
			bool isOperator = false;
			while(!s.empty() && s.top() != '(') {
			    char ch = s.top();
			    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			        isOperator = true;
			    } else {
			        isOperand = true;
			    }
				s.pop();
			}
			if(!(isOperand && isOperator)) {
			    return 1;
			}
			s.pop();
		}
	}
	return 0;
}
