/*
Knight On Chess Board
Problem Description

Given any source point, (C, D) and destination point, (E, F) on a chess board of size A x B, we need to find whether Knight can move to the destination or not.


The above figure details the movements for a knight ( 8 possibilities ).

If yes, then what would be the minimum number of steps for the knight to move to the said point. If knight can not move from the source point to the destination point, then return -1.

NOTE: A knight cannot go out of the board.



Problem Constraints
1 <= A, B <= 500



Input Format
The first argument of input contains an integer A.
The second argument of input contains an integer B.
The third argument of input contains an integer C.
The fourth argument of input contains an integer D.
The fifth argument of input contains an integer E.
The sixth argument of input contains an integer F.



Output Format
If it is possible to reach the destination point, return the minimum number of moves.
Else return -1.



Example Input
Input 1:

 A = 8
 B = 8
 C = 1
 D = 1
 E = 8
 F = 8
Input 2:

 A = 2
 B = 4
 C = 2
 D = 1
 E = 4
 F = 4


Example Output
Output 1:

 6
Output 2:

 -1


Example Explanation
Explanation 1:

 The size of the chessboard is 8x8, the knight is initially at (1, 1) and the knight wants to reach position (8, 8).
 The minimum number of moves required for this is 6.
Explanation 2:

 It is not possible to move knight to position (4, 4) from (2, 1)

 */



int rows[] = {-2,-1,1,2,2,1,-1,-2};
int cols[] = {1,2,2,1,-1,-2,-2,-1};

bool isValid(int i,int j, int r, int c) {
	if(i<1 || i>r || j<1 || j>c) {  // 1- indexing
		return false;
	}

	return true;
}

int Solution::knight(int A, int B, int C, int D, int E, int F) {

	queue<pair<int,int> > q;
	q.push(make_pair(C,D));
	vector<vector<bool> > visited(A+1,vector<bool>(B+1,false));
	visited[C][D] = true;

	int currLevel = -1;
	while(!q.empty()) {
		currLevel++;
		int size = q.size();
		for(int s = 0;s<size;s++) {
			pair<int,int> cords = q.front();
			q.pop();
			int i = cords.first;
			int j = cords.second;
		//	cout<<i<<' '<<j<<endl;
			if(i == E && j == F) {
			    
				return currLevel;
			}
			for(int k = 0;k<8;k++) {
				int nextRow = i + rows[k];
				int nextCol = j + cols[k];
				if(isValid(nextRow,nextCol,A,B) && !visited[nextRow][nextCol]) {
					visited[nextRow][nextCol] = true;
					q.push(make_pair(nextRow,nextCol));
				}
			}
		}
	}

	return -1;
}
