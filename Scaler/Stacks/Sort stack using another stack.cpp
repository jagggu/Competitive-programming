/*
Sort stack using another stack
Given a stack of integers A, sort it using another stack. Return the array of integers after sorting the stack using another stack. 
Input Format
The only argument given is the integer array A.
Output Format
Return the array of integers after sorting the stack using another stack.
Constraints
1 <= length of the array <= 5000
0 <= A[i] <= 10^9 
For Example
Input 1:
    A = [5, 4, 3, 2, 1]
Output 1:
    [1, 2, 3, 4, 5]

Input 2:
    A = [5, 17, 100, 11]
Output 2:
    [5, 11, 17, 100]
*/


vector<int> Solution::solve(vector<int> &A) {

	stack<int> sortStack;
	stack<int> tmpStack;
	for(auto ele : A) {
		if(sortStack.empty()) {
			sortStack.push(ele);
		} else {
			while(!sortStack.empty() && sortStack.top() > ele) {
				int t = sortStack.top();
				sortStack.pop();
				tmpStack.push(t);
				//cout<<t<<' ';
			}
			sortStack.push(ele);
			while(!tmpStack.empty()) {
				int t = tmpStack.top();
				tmpStack.pop();
				sortStack.push(t);
			}
			//cout<<endl;
		}
	}

	int index = 0;
	while(!sortStack.empty()) {
		int t = sortStack.top();
		A[index++] = t;
		sortStack.pop();
	}
	reverse(A.begin(),A.end());
	return A;
}
