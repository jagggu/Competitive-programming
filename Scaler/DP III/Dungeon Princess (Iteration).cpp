/*
Dungeon Princess
Problem Description

The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Given a 2D array of integers A of size M x N. Find and return the knight's minimum initial health so that he is able to rescue the princess.



Problem Constraints
1 <= M, N <= 500

-100 <= A[i] <= 100



Input Format
First and only argument is a 2D integer array A denoting the grid of size M x N.



Output Format
Return an integer denoting the knight's minimum initial health so that he is able to rescue the princess.



Example Input
Input 1:

 A = [ 
       [-2, -3, 3],
       [-5, -10, 1],
       [10, 30, -5]
     ]
Input 2:

 A = [ 
       [1, -1, 0],
       [-1, 1, -1],
       [1, 0, -1]
     ]


Example Output
Output 1:

 7
Output 2:

 1


Example Explanation
Explanation 1:

 Initially knight is at A[0][0].
 If he takes the path RIGHT -> RIGHT -> DOWN -> DOWN, the minimum health required will be 7.
 At (0,0) he looses 2 health, so health becomes 5.
 At (0,1) he looses 3 health, so health becomes 2.
 At (0,2) he gains 3 health, so health becomes 5.
 At (1,2) he gains 1 health, so health becomes 6.
 At (2,2) he looses 5 health, so health becomes 1.
 At any point, the health point doesn't drop to 0 or below. So he can rescue the princess with minimum health 7.
 
Explanation 2:

 Take the path DOWN -> DOWN ->RIGHT -> RIGHT, the minimum health required will be 1.


*/




int Solution::calculateMinimumHP(vector<vector<int> > &A) {

	if(A.size() < 1 || A[0].size()<1) {
		return 0;
	}

	int rows = A.size();
	int cols = A[0].size();

	if(A[rows-1][cols-1] <= 0) {
		A[rows-1][cols-1] = 1 - (A[rows-1][cols-1]);
	} else {
	    A[rows-1][cols-1] = 1;
	}

	for(int i = cols-2;i>=0;i--) {
		if(A[rows-1][i] <= 0){
			int currEnergy = 1 - (A[rows-1][i]);
			currEnergy += (A[rows-1][i+1] - 1);
			A[rows-1][i] = currEnergy;
		} else {
			int currEnergy = 1 + A[rows-1][i];

			if(currEnergy < A[rows-1][i+1]) {
				currEnergy = (A[rows-1][i+1] - A[rows-1][i]);
			} else {
				currEnergy = 1;
			}
			A[rows-1][i] = currEnergy;

		}
	}

	for(int i = rows-2;i>=0;i--) {
		if(A[i][cols-1] <= 0) {
			int currEnergy = 1 - (A[i][cols-1]);
			currEnergy += (A[i+1][cols-1] - 1);
			A[i][cols-1] = currEnergy;
		} else {
			int currEnergy = 1 + A[i][cols-1];

			if(currEnergy < A[i+1][cols-1]) {
				currEnergy = A[i+1][cols-1] - A[i][cols-1];
			} else {
				currEnergy = 1;
			}

			A[i][cols-1] = currEnergy;
		}
	}

	for(int i = rows-2;i>=0;i--) {
		for(int j = cols-2;j>=0;j--) {

			if(A[i][j] <= 0) {
				int currEnergy = 1-(A[i][j]);
				int minEnergy = min(A[i+1][j],A[i][j+1]);
				currEnergy += (minEnergy-1);
				A[i][j] = currEnergy;
			} else {
				int currEnergy = 1 + A[i][j];
				int minEnergy = min(A[i+1][j],A[i][j+1]);
				if(currEnergy < minEnergy) {
					currEnergy = minEnergy - A[i][j];
				} else {
					currEnergy = 1;
				}
				A[i][j] = currEnergy;
			}
		}
	}

	return A[0][0];
}
