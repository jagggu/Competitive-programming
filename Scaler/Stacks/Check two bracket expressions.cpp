/*
Check two bracket expressions
Given two strings A and B. Each string represents an expression consisting of lowercase english alphabets, '+', '-' and '()'. The task is to compare them and check if they are similar. If they are similar return 1 else return 0. Note: It may be assumed that there are at most 26 operands from ‘a’ to ‘z’ and every operand appears only once. 
Input Format
The arguments given are string A and String B.
Output Format
Return 1 if they represent the same expression
else return 0.
Constraints
1 <= length of the each String <= 100
For Example
Input 1:
     A = "-(a+b+c)"
     B = "-a-b-c"
Output 1:
     1

Input 2:
     A = "a-b-(c-d)"
     B = "a-b-c-d"
Output 2:
    0

 */


string removeBrackets(string A) {
	stack<int> s;
	int minusFlag = false;
	int isFirstOperator = false;
	for(int i = 0;i<A.size();i++) {
		if(A[i] == '(') {
			if(!s.empty() && s.top() == '-') {
				minusFlag = true;
			}
		} else if(A[i] == ')') {
			minusFlag = false;
		} else {
			if(A[i] == '+' || A[i] == '-') {
				if(minusFlag) {
					if(A[i] == '+') {
						s.push('-');
					} else {
						s.push('+');
					}
				} else {
				    s.push(A[i]);
				}
			} else {
				s.push(A[i]);
			}
		}
	}
	string res;
	while(!s.empty()) {
		res+=s.top();
		s.pop();
	}
	reverse(res.begin(),res.end());
	return res;
}

int Solution::solve(string A, string B) {
	string str1 = removeBrackets(A);
	string str2 = removeBrackets(B);

	return str1 == str2;
}
