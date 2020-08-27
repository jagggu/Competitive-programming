/*
Shortest Distance in a Maze
Problem Description

Given a matrix of integers A of size N x M describing a maze. The maze consists of empty locations and walls.

1 represents a wall in a matrix and 0 represents an empty location in a wall.

There is a ball trapped in a maze. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given two array of integers of size B and C of size 2 denoting the starting and destination position of the ball.

Find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the starting position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.



Problem Constraints
2 <= N, M <= 100

0 <= A[i] <= 1

0 <= B[i][0], C[i][0] < N

0 <= B[i][1], C[i][1] < M



Input Format
The first argument given is the integer matrix A.

The second argument given is an array of integer B.

The third argument if an array of integer C.



Output Format
Return a single integer, the minimum distance required to reach destination



Example Input
Input 1:

A = [ [0, 0], [0, 0] ]
B = [0, 0]
C = [0, 1]
Input 2:

A = [ [0, 0], [0, 1] ]
B = [0, 0]
C = [0, 1]


Example Output
Output 1:

 1
Output 2:

 1


Example Explanation
Explanation 1:

 Go directly from start to destination in distance 1.
Explanation 2:

 Go directly from start to destination in distance 1.

*/



struct Info {
	int i;
	int j;
	int dist;
};

int rowsDir[] = { -1, 0, 1, 0};
int colsDir[] = {0, 1, 0, -1};

bool isValid(vector<vector<int> > &A, int i, int j, int r, int c) {
	if (i < 0 || i >= r || j < 0 || j >= c || A[i][j] == 1) {
		return false;
	}

	return true;
}

int Solution::solve(vector<vector<int> > &A, vector<int> &B, vector<int> &C) {

	if (A.size() < 1 || A[0].size() < 1) {
		return -1;
	}

	int rows  = A.size();
	int cols = A[0].size();

	int srcRow = B[0];
	int srcCol = B[1];

	int destRow = C[0];
	int destCol = C[1];

	if (A[destRow][destCol] == 1) {
		return -1;
	}

	queue<Info> q;
	vector<vector<bool> > visited(rows, vector<bool>(cols, false));

	visited[srcRow][srcCol] = true;
	Info f;
	f.i = srcRow;
	f.j = srcCol;
	f.dist = 0;
	q.push(f);
	int currLevel = -1;
	while (!q.empty()) {

		int size = q.size();
		currLevel++;
		for (int i = 0; i < size; i++) {
			Info inf = q.front();
			q.pop();
			int currRow = inf.i;
			int currCol = inf.j;
			int currDist = inf.dist;
			if (currRow == destRow && currCol == destCol) {
				return currDist;
			}



			for (int k = 0; k < 4; k++) {
				int nextRow = currRow + rowsDir[k];
				int nextCol = currCol + colsDir[k];

				if (isValid(A, nextRow, nextCol, rows, cols)) {
					int limit = 2;
					int tmpi = nextRow;
					int tmpj = nextCol;
					while (true) {
						nextRow  = currRow + (limit * rowsDir[k]);
						nextCol  = currCol + (limit * colsDir[k]);
						if (isValid(A, nextRow, nextCol, rows, cols)) {
							tmpi = nextRow;
							tmpj = nextCol;
							limit++;
						} else {
							break;
						}
					}
					if (!visited[tmpi][tmpj]) {
						visited[tmpi][tmpj] = true;
						Info inf1;
						inf1.i = tmpi;
						inf1.j = tmpj;
						inf1.dist = currDist + limit - 1;
						q.push(inf1);
					}
				}
			}
		}
	}

	return -1;
}
