/*
Unique Paths in a Grid
Problem Description

Given a grid of size n * m, lets assume you are starting at (1,1) and your goal is to reach (n, m). At any instance, if you are on (x, y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be? An obstacle and empty space is marked as 1 and 0 respectively in the grid.



Problem Constraints
1 <= n, m <= 100
A[i][j] = 0 or 1



Input Format
Firts and only argument A is a 2D array of size n * m.



Output Format
Return an integer denoting the number of unique paths from (1, 1) to (n, m).



Example Input
Input 1:

 A = [
        [0, 0, 0]
        [0, 1, 0]
        [0, 0, 0]
     ]
Input 2:

 A = [
        [0, 0, 0]
        [1, 1, 1]
        [0, 0, 0]
     ]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 Possible paths to reach (n, m): {(1, 1), (1, 2), (1, 3), (2, 3), (3, 3)} and {(1 ,1), (2, 1), (3, 1), (3, 2), (3, 3)}  
 So, the total number of unique paths is 2. 
Explanation 2:

 It is not possible to reach (n, m) from (1, 1). So, ans is 0.


*/




int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {

	if (A.size() < 1 || A[0].size() < 1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();
	if (A[0][0] == 1) {
		return 0;
	}
	/*
	vector<vector<int> > paths(rows+1,vector<int>(cols+1));



	paths[1][1] = 1;



	for(int i = 1;i<=rows;i++) {
		for(int j = 1;j<=cols;j++) {
		    if(A[i-1][j-1]) {
		        paths[i][j] = 0;
		    } else {
			paths[i][j] += paths[i][j-1] + paths[i-1][j];
		    }
		}
	}

	return paths[rows][cols];
	*/

	vector<vector<int> > paths(2, vector<int>(cols + 1));

    

	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= cols; j++) {
		      
		      if(i == 1 && j == 1) {
		          paths[i][j] = 1;
		          continue;
		      }
		    
			if (A[i - 1][j - 1] == 1) {
				paths[i % 2][j] = 0;
			} else {
				paths[i % 2][j] = paths[(i-1)%2][j] + paths[i%2][j-1];
			}
		}
	}

	return paths[rows%2][cols];
}
