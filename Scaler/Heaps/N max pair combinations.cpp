/*
N max pair combinations
Problem Description
Given two integers arrays A and B of size N each. Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B. 


Problem Constraints
1 <= N <= 2 * 105 -1000 <= A[i], B[i] <= 1000 


Input Format
First argument is an integer array A.
Second argument is an integer array B.


Output Format
Return an intger array denoting the N maximum element in descending order.


Example Input
Input 1:
 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
Input 2:
 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]


Example Output
Output 1:
 [10, 9, 9, 8]
Output 2:
 [8, 6, 6, 5]


Example Explanation
Explanation 1:
 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2:
 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).

 */



struct Info {
	int i;
	int j;
	int val;
};

class MyComparator {
public:
	int operator() (Info f1, Info f2) {
		return f1.val < f2.val;
	}
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {

	priority_queue<Info, vector<Info>, MyComparator> maxPQ;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	set<pair<int, int> > s;
	int n = A.size();
	Info f;
	f.i = n - 1;
	f.j = n - 1;
	f.val = A[n - 1] + B[n - 1];
	s.insert(make_pair(f.i, f.j));
	maxPQ.push(f);
	vector<int> res;
	for (int i = n - 1; i >= 0; i--) {

		Info tmp = maxPQ.top();
		maxPQ.pop();
		res.push_back(tmp.val);
		Info c1;
		c1.i = tmp.i - 1;
		c1.j = tmp.j;
		c1.val = A[c1.i] + B[c1.j];
		Info c2;

		c2.i = tmp.i;
		c2.j = tmp.j - 1;
		c2.val = A[c2.i] + B[c2.j];
		if (s.find(make_pair(c1.i, c1.j)) == s.end()) {


			maxPQ.push(c1);
			s.insert(make_pair(c1.i, c1.j));
		}

		if (s.find(make_pair(c2.i, c2.j)) == s.end()) {

			maxPQ.push(c2);
			s.insert(make_pair(c2.i, c2.j));
		}

	}

	return res;

}
