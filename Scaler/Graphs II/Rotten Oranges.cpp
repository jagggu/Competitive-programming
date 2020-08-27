/*
Rotten Oranges
Problem Description

Given a matrix of integers A of size N x M consisting of 0, 1 or 2.

Each cell can have three values:

The value 0 representing an empty cell.

The value 1 representing a fresh orange.

The value 2 representing a rotten orange.

Every minute, any fresh orange that is adjacent (Left, Right, Top, or Bottom) to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1 instead.

Note: Your solution will run on multiple test cases. If you are using global variables, make sure to clear them.



Problem Constraints
1 <= N, M <= 1000

0 <= A[i][j] <= 2



Input Format
The first argument given is the integer matrix A.



Output Format
Return the minimum number of minutes that must elapse until no cell has a fresh orange.

If this is impossible, return -1 instead.



Example Input
Input 1:

A = [   [2, 1, 1]
        [1, 1, 0]
        [0, 1, 1]   ]
Input 2:

 
A = [   [2, 1, 1]
        [0, 1, 1]
        [1, 0, 1]   ]


Example Output
Output 1:

 4
Output 2:

 -1


Example Explanation
Explanation 1:

 Max of 4 using (0,0) , (0,1) , (1,1) , (1,2) , (2,2)
Explanation 2:

 Task is impossible

 */



int rowsDir[] = {-1,0,1,0};
int colsDir[] = {0,1,0,-1};

bool isValid(int i, int j, vector<vector<int> > &A) {
	int r = A.size();
	int c = A[0].size();
	if(i<0 || i>=r || j<0 || j>=c || A[i][j] == 0) {
		return false;
	}

	return true;
}

int Solution::solve(vector<vector<int> > &A) {

	queue<pair<int,int> > q;

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	vector<vector<bool> > visited(rows,vector<bool>(cols,false));

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == 2) {
				q.push(make_pair(i,j));
				visited[i][j] = true;
			}
		}
	}

	int currLevel = -1;

	while(!q.empty()) {

		int size = q.size();
		currLevel++;
		for(int l = 0;l<size;l++) {
			pair<int,int> cords = q.front();
			q.pop();
			int i = cords.first;
			int j = cords.second;
			for(int k = 0;k<4;k++) {
				int nextRow = i + rowsDir[k];
				int nextCol = j + colsDir[k];
				if(isValid(nextRow,nextCol,A) && !visited[nextRow][nextCol]) {
					A[nextRow][nextCol] = 2;
					visited[nextRow][nextCol] = true;
					q.push(make_pair(nextRow,nextCol));
				}
			}

		}
	}

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == 1) {
				return -1;
			}
		}
	}

	return currLevel;
}
