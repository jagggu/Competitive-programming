/*
Capture Regions on Board
Problem Description

Given a 2-D board A of size N x M containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.



Problem Constraints
1 <= N, M <= 1000



Input Format
First and only argument is a N x M character matrix A.



Output Format
Make changes to the the input only as matrix is passed by reference.



Example Input
Input 1:

 A = [ 
       [X, X, X, X],
       [X, O, O, X],
       [X, X, O, X],
       [X, O, X, X] 
     ]
Input 2:

 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Output
Output 1:

 After running your function, the board should be:
 A = [
       [X, X, X, X],
       [X, X, X, X],
       [X, X, X, X],
       [X, O, X, X]
     ]
Output 2:

 After running your function, the board should be:
 A = [
       [X, O, O],
       [X, O, X],
       [O, O, O]
     ]


Example Explanation
Explanation 1:

 O in (4,2) is not surrounded by X from below.
Explanation 2:

 No O's are surrounded.


*/




int rowsDir[] = {-1,0,1,0};
int colsDir[] = {0,1,0,-1};

bool isValid(vector<vector<char> > &A, int i, int j, int r, int c) {
	if(i<0 || i>=r || j<0 || j>=c || A[i][j] == 'X') {
		return false;
	}

	return true;
}

void Solution::solve(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	
	queue<pair<int,int> > q;
	if(A.size() < 1 || A[0].size() < 1) {
		return;
	}	    

	int rows = A.size();
	int cols = A[0].size();

	vector<vector<bool> > visited(rows,vector<bool>(cols,false));

	for(int i = 0;i<rows;i++) {
	    //cout<<A[i][0]<<endl;
		if(A[i][0] == 'O') {
		    //cout<<"CheckPoint1"<<endl;
			//A[i][0] = '#';
			q.push(make_pair(i,0));
			visited[i][0] = true;
		}

		if(A[i][cols-1] == 'O') {
			//A[i][cols-1] = '#';
			if(!visited[i][cols-1]) { 
			q.push(make_pair(i,cols-1));
			visited[i][cols-1] = true;
			}
		}
	}

	for(int i = 1;i<=cols-2;i++) {
		if(A[0][i] == 'O') {
			//A[0][i] = '#';
			q.push(make_pair(0,i));
			visited[0][i] = true;
		}

		if(A[rows-1][i] == 'O') {
			//A[rows-1][i] = '#';
			q.push(make_pair(rows-1,i));
			visited[rows-1][i] = true;
		}
	}

	while(!q.empty()) {
		int size = q.size();
		for(int i = 0;i<size;i++) {
			pair<int,int> cords = q.front();
			q.pop();
			int currRow = cords.first;
			int currCol = cords.second;
			A[currRow][currCol] = '#';
		//	cout<<"Checkpoint2"<<endl;
		    //cout<<currRow<<' '<<currCol<<endl;
			for(int k = 0;k<4;k++) {
				int nextRow = currRow + rowsDir[k];
				int nextCol = currCol + colsDir[k];
				if(isValid(A,nextRow,nextCol,rows,cols) && !visited[nextRow][nextCol]) {
					visited[nextRow][nextCol] = true;
					q.push(make_pair(nextRow,nextCol));
				}
			}
		}
	}

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] == '#') {
				A[i][j] = 'O';
			} else if(A[i][j]  == 'O') {
				A[i][j] = 'X';
			}
		}
	}
}
