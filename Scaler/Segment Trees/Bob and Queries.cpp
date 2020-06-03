/*
Bob and Queries
Problem Description
Bob has an array A of N integers. Initially, all the elements of the array are zero. Bob asks you to perform Q operations on this array. You have to perform three types of query, in each query you are given three integers x, y and z. 
if x = 1: Update the value of A[y] to 2 * A[y] + 1.
if x = 2: Update the value A[y] to ⌊A[y]/2⌋ , where ⌊⌋ is Greatest Integer Function.
if x = 3: Take all the A[i] such that y <= i <= z and convert them into their corresponding binary strings. Now concatenate all the binary strings and find the total no. of '1' in the resulting string.
 
Queries are denoted by a 2-D array B of size M x 3 where B[i][0] denotes x, B[i][1] denotes y, B[i][2] denotes z.       


Problem Constraints
1 <= N, Q <= 100000
1 <= y, z <= N
1 <= x <= 3


Input Format
The first argument has the integer A.
The second argument is a 2d matrix B, of size Q x 3, representing the queries.


Output Format
Return an array of integers where ith index represents the answer of the ith type 3 query.


Example Input
Input 1:
 A = 5
 B = [   
        [1, 1, -1]
        [1, 2, -1]
        [1, 3, -1]   
        [3, 1, 3] 
        [3, 2, 4]   
     ]
Input 2:
 A = 5
 B = [   
        [1, 1, -1]
        [1, 2, -1]
        [3, 1, 3]
        [2, 1, -1]
        [3, 1, 3]   
     ]
           


Example Output
Output 1:
 [3, 2]
Output 2:
 [2, 1]
            


Example Explanation
Explanation 1:
 Initial array A = [0, 0, 0, 0, 0]
 After query 1, A => [1, 0, 0, 0, 0]
 After query 2, A => [1, 1, 0, 0, 0]
 After query 3, A => [1, 1, 1, 0, 0]
 For query 4, Concatenation of Binary String between index 1 and 3 : 111. So, number of 1's = 3
 For query 5, Concatenation of Binary String between index 2 and 4 : 110. So, number of 1's = 2
 So, output array is [3, 2].
Explanation 2:
 Initial array A = [0, 0, 0, 0, 0]
 After query 1, A => [1, 0, 0, 0, 0]
 After query 2, A => [1, 1, 0, 0, 0]
 For query 3, Concatenation of Binary String between index 1 and 3 : 110. So, number of 1's = 2
 After query 4, A => [0, 1, 0, 0, 0]
 For query 5, Concatenation of Binary String between index 2 and 4 : 010. So, number of 1's = 1.
 So, output array is [2, 1].
 
 */



vector<int> segTree;

void buildTree(int node, int start, int end) {
	if (start == end) {
		segTree[node] = 0;
		return;
	}

	int mid = start + (end - start) / 2;
	buildTree(2 * node, start, mid);
	buildTree(2 * node + 1, mid + 1, end);
	segTree[node] = 0;
}

void update(int node, int start, int end, int indx, int val) {
	if (start == end) {
		if (val == 1) {
			segTree[node]++;
		} else {
			if (segTree[node] > 0) {
				segTree[node]--;
			}
		}

		return;
	}

	int mid = start + (end - start) / 2;

	if (start <= indx && indx <= mid) {
		update(2 * node, start, mid, indx, val);
	} else {
		update(2 * node + 1, mid + 1, end, indx, val);
	}

	segTree[node] = segTree[2 * node] + segTree[2 * node + 1];


}

int query(int node, int start, int end, int l, int r) {
	if (r < start || end < l) {
		return 0;
	}

	if (l <= start && end <= r) {
		return segTree[node];
	}

	int mid = start + (end - start) / 2;
	int ans1 = query(2 * node, start, mid, l, r);
	int ans2 = query(2 * node + 1, mid + 1, end, l, r);

	return ans1 + ans2;
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {

	segTree.clear();
	segTree.resize(4 * A);

	buildTree(1, 0, A - 1);

	vector<int> res;

	for (int i = 0; i < B.size(); i++) {
		if (B[i][0] == 1) {
			update(1, 0, A - 1, B[i][1] - 1, 1);
		} else if (B[i][0] == 2) {
			update(1, 0, A - 1, B[i][1] - 1, -1);
		} else {
			int ans = query(1, 0, A - 1, B[i][1] - 1, B[i][2] - 1);
			res.push_back(ans);
		}
	}

	return res;
}
