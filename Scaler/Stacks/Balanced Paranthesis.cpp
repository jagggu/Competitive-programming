/*
Balanced Paranthesis
Problem Description
Given an expression string A, examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in A.  Refer to the examples for more clarity.       


Problem Constraints
1 <= |A| <= 100


Input Format
The first and the only argument of input contains the string A having the paranthesis sequence.


Output Format
Return 0, if the paranthesis sequence is not balanced. Return 1, if the paranthesis sequence is balanced.       


Example Input
Input 1:
 A = {([])}
Input 2:
 A = (){
Input 3:
 A = ()[] 
     


Example Output
Output 1:
 1 
Output 2:
 0 
Output 3:
 1 
    


Example Explanation
You can clearly see that the first and third case contain valid paranthesis. In the second case, there is no closing bracket for {, thus the paranthesis sequence is invalid. 

*/

int Solution::solve(string A) {

	stack<char> s;

	for(int i = 0;i<A.size();i++) {
		if(A[i] == '{' || A[i] == '[' || A[i] == '(') {
			s.push(A[i]);
		} else {
			if(s.empty()) {
				return 0;
			}
			if(A[i] == '}') {
				if(s.top() == '{') {
					s.pop();
				} else {
					return 0;
				}
			} else if(A[i] == ']') {
				if(s.top() == '[') {
					s.pop();
				} else {
					return 0;
				}
			} else {
				if(s.top() == '(') {
					s.pop();
				} else {
					return 0;
				}
			}
		}
	}
	return s.empty();
}
