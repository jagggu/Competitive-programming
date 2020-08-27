/*
Floyd Warshall Algorithm
Problem Description

Given a matrix of integers A of size N x N, where A[i][j] represents the weight of directed edge from i to j (i ---> j).

If i == j, A[i][j] = 0, and if there is no directed edge from vertex i to vertex j, A[i][j] = -1.

Return a matrix B of size N x N where B[i][j] = shortest path from vertex i to vertex j.

If there is no possible path from vertex i to vertex j , B[i][j] = -1

Note: Rows are numbered from top to bottom and columns are numbered from left to right.



Problem Constraints
1 <= N <= 200
-1 <= A[i][j] <= 1000000


Input Format
The first and only argument given is the integer matrix A.


Output Format
Return a matrix B of size N x N where B[i][j] = shortest path from vertex i to vertex j
If there is no possible path from vertex i to vertex j, B[i][j] = -1.


Example Input
A = [ [0 , 50 , 39]
          [-1 , 0 , 1]
          [-1 , 10 , 0] ]


Example Output
[ [0 , 49 , 39 ]
   [-1 , 0 , -1 ] 
   [-1 , 10 , 0 ] ]


Example Explanation
Shortest Path from 1 to 2 would be 1 ---> 3 ---> 2 and not directly from 1 to 2, 
All remaining distances remains same.


*/


#define inf 1000009

vector<vector<int> > Solution::solve(vector<vector<int> > &A) {


	int rows = A.size();
	int cols = A[0].size();
	vector<vector<int> > dist(rows,vector<int>(cols,inf));

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(A[i][j] != -1) {
				dist[i][j] = A[i][j];
			}
		}
	}

	int v = rows;

	for(int k = 0;k<v;k++) {
		for(int i = 0;i<v;i++) {
			for(int j = 0;j<v;j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	for(int i = 0;i<rows;i++) {
		for(int j = 0;j<cols;j++) {
			if(dist[i][j] == inf) {
				dist[i][j] = -1;
			}
		}
	}

	return dist;

}
