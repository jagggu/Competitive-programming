/*
Black Shapes
Problem Description

Given character matrix A of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)



Problem Constraints
1 <= |A|,|A[0]| <= 1000

A[i][j] = 'X' or 'O'



Input Format
The First and only argument is character matrix A.



Output Format
Return a single integer denoting number of black shapes.



Example Input
Input 1:

 A = [ [X, X, X], [X, X, X], [X, X, X] ]
Input 2:

 A = [ [X, O], [O, X] ]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 All X's belong to single shapes
Explanation 2:

 Both X's belong to different shapes

 */



int rows[] = {-1,0,1,0};
int cols[] = {0,1,0,-1};

bool isValid(int i, int j, vector<string> &A) {
	int rows = A.size();
	int cols = A[0].size();

	if(i>=rows || i<0 || j>=cols || j<0 || A[i][j] == 'O'){
		return false;
	}

	return true;
}

void dfs(int i, int j, vector<vector<bool> > &visited, vector<string> &A) {
	visited[i][j] = true;

	for(int k = 0;k<4;k++) {
		int newI = i + rows[k];
		int newJ = j + cols[k];
		if(isValid(newI,newJ,A) && visited[newI][newJ] == false) {
			dfs(newI,newJ,visited,A);
		}
	}
}

int Solution::black(vector<string> &A) {

	if(A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int ans = 0;
	int rows = A.size();
	int cols = A[0].size();

	vector<vector<bool> > visited(rows+1,vector<bool>(cols+1,false));

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(!visited[i][j] && A[i][j] == 'X') {
				ans++;
				//cout<<i<<' '<<j<<endl;
				dfs(i,j,visited,A);
			}
		}
	}

	return ans; 
}
