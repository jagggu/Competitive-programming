/*
N integers containing only 1,2 and 3
Given an integer A. Find and Return first positive A integers in ascending order containing only digits 1,2 and 3. NOTE: all the A integers will fit in 32 bit integer. 
Input Format
The only argument given is integer A.
Output Format
Find and Return first positive A integers in ascending order containing only digits 1,2 and 3.
Constraints
1 <= A <= 29500
For Example
Input 1:
    A = 3
Output 1:
    [1, 2, 3]

Input 2:
    A = 7
Output 2:
    [1, 2, 3, 11, 12, 13, 21]

  */


vector<int> Solution::solve(int A) {
	vector<int> res;
	queue<int> q;
	if(A <= 3) {
		int num = 1;
		while(A>0) {
			res.push_back(num);
			num++;
			A--;
		}
		return res;
	} else {
		q.push(1);
		q.push(2);
		q.push(3);
		A = A - 3;
		while(A > 0) {
			int num = q.front();
			res.push_back(num);
			q.pop();
			q.push(num*10 + 1);
			A--;
			if(A>0) {
				q.push(num*10+2);
                A--;
			}
			if(A>0) {
				q.push(num*10+3);
				A--;
			}
		}

		while(!q.empty()) {
			res.push_back(q.front());
			q.pop();
		}

	}
	return res;

}
