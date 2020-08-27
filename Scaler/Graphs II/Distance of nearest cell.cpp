/*
Distance of nearest cell
Problem Description

Given a matrix of integers A of size N x M consisting of 0 or 1.

For each cell of the matrix find the distance of nearest 1 in the matrix.

Distance between two cells (x1, y1) and (x2, y2) is defined as |x1 - y1| + |x2 - y2|.

Find and return a matrix B of size N x M which defines for each cell in A distance of nearest 1 in the matrix A.

NOTE: There is atleast one 1 is present in the matrix.



Problem Constraints
1 <= N, M <= 1000

0 <= A[i] <= 1



Input Format
The first argument given is the integer matrix A.



Output Format
Return the matrix B.



Example Input
Input 1:

 A = [
       [0, 0, 0, 1]
       [0, 0, 1, 1] 
       [0, 1, 1, 0]
     ]
Input 2:

 A = [
       [1, 0, 0]
       [0, 0, 0]
       [0, 0, 0]  
     ]


Example Output
Output 1:

 [ 
   [3, 2, 1, 0]
   [2, 1, 0, 0]
   [1, 0, 0, 1]   
 ]
Output 2:

 [
   [0, 1, 2]
   [1, 2, 3]
   [2, 3, 4] 
 ]


Example Explanation
Explanation 1:

 A[0][0], A[0][1], A[0][2] will be nearest to A[0][3].
 A[1][0], A[1][1] will be nearest to A[1][2].
 A[2][0] will be nearest to A[2][1] and A[2][3] will be nearest to A[2][2].
Explanation 2:

 There is only a single 1. Fill the distance from that 1.

 */


struct Info {
	int i;
	int j;
	int dist;

};

int rowsDir[] = {-1,0,1,0};
int colsDir[] = {0,1,0,-1};

bool isValid(int i, int j, int r, int c) {
	if(i<0 || i>=r || j<0 || j>=c) {
		return false;
	}

	return true;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return A;
	}

	int rows = A.size();
	int cols = A[0].size();

	queue<Info> q;
	vector<vector<bool> > visited(rows,vector<bool>(cols,false));

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == 1) {
				Info tmp;
				tmp.i = i;
				tmp.j = j;
				tmp.dist = 0;
				q.push(tmp);
				visited[i][j] = true;
			}
		}
	}

	while(!q.empty()) {

		int size = q.size();
		for(int i = 0;i<size;i++) {
			Info tmp = q.front();
			q.pop();
			int currRow = tmp.i;
			int currCol = tmp.j;
			int currDist = tmp.dist;
			A[currRow][currCol] = currDist;
			for(int k = 0;k<4;k++) {
				int nextRow = currRow + rowsDir[k];
				int nextCol = currCol + colsDir[k];

				if(isValid(nextRow,nextCol,rows,cols) && !visited[nextRow][nextCol]) {
					visited[nextRow][nextCol] = true;
					Info tmp1;
					tmp1.i = nextRow;
					tmp1.j = nextCol;
					tmp1.dist = currDist + 1;
					q.push(tmp1);
				}
			}
		}		
	}

	return A;

}
