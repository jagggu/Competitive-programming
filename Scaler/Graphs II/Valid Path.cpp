
int rows[] = { -1, 0, 1, 0, -1, 1, -1, 1};
int cols[] = {0, -1, 0, 1, -1, 1, 1, -1};

bool canGo(int i, int j, vector<vector<int> > &mat, int r, int c) {
	if (i >= r || i < 0 || j >= c || j < 0 || mat[i][j] == -1) {
		return false;
	}

	return true;
}

bool isValid(int i, int j, int r, int c) {
	return (i >= 0 && i < r && j >= 0 && j < c);
}

void dfs(int i, int j, vector<vector<bool> > &visited, vector<vector<int> > &mat, bool &isPathExists, int &x, int &y) {
	visited[i][j] = true;


//	cout<<i<<' '<<j<<endl;


	for (int k = 0; k < 8; k++) {
		int nextRow = i + rows[k];
		int nextCol = j + cols[k];
		if (canGo(nextRow, nextCol, mat, x, y) && !visited[nextRow][nextCol]) {
			if (i == x && j == y) {
				isPathExists = true;
				return;
			}
			dfs(nextRow, nextCol, visited, mat, isPathExists, x, y);
		}

	}

}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {

	int x = A;
	int y = B;
	int totalCircles = C;
	int radius = D;

	vector<vector<int> > mat(x + 1, vector<int>(y + 1, 1));

	for (int i = 0; i < totalCircles; i++) {
		int ci = E[i];
		int cj = F[i];
		//mat[ci][cj] = -1;
		for (int r = 1; r <= radius; r++) {
			//cout<<"CheckPoint 2"<<endl;
			for (int k = 0; k < 8; k++) {
				int nextRow = ci + r * rows[k];
				int nextCol = cj + r * cols[k];
				if (isValid(nextRow, nextCol, x, y)) {
					mat[nextRow][nextCol] = -1;
				}
			}
		}
	}

//	cout<<"checkPoint 1"<<endl;

	if (mat[0][0] == -1) {
		return "NO";
	}
	if (mat[x][y] == -1) {
		return "NO";
	}
	//cout<<"checkPoint 3"<<endl;
	vector<vector<bool> > visited(x + 1, vector<bool>(y + 1, false));



	bool isPathExists = false;
	dfs(0, 0, visited, mat, isPathExists, x, y);
	if (isPathExists) {
		return "YES";
	}

	return "NO";

}
