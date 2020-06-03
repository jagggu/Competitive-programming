/*
Reverse a stack using recursion
Given a stack of integers A. You are required to reverse the stack using recursion. You are not allowed to use loop constructs like while, for..etc, Return A after reversing it using recursion. NOTE: It is mandatory to reverse A using recursion.  
Input Format
The only argument given is the integer array A.
Output Format
Return the reversal of A using stack.
Constraints
1 <= length of the array <= 2000
1 <= A[i] <= 10^8 
For Example
Input 1:
    A = [1, 5, 3, 2, 4]
Output 1:
    [4, 2, 3, 5, 1]

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    [11, 100, 17, 5]

 */


void insertAtBottom(stack<int> &s, int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}
	int tmp = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(tmp);
}

void reverse(stack<int> &s) {

	if(!s.empty()) {
		int x = s.top();
		s.pop();
		reverse(s);
		insertAtBottom(s,x);
	}
}

vector<int> Solution::solve(vector<int> &A) {
    stack<int> s;
    int n = A.size();
    
    for(int i = n-1; i>=0; i--) {
    	s.push(A[i]);
    }

    reverse(s);

    int i = 0;
    while(!s.empty()) {
    	A[i] = s.top();
    	s.pop();
    	i++;
    }
    return A;
}
