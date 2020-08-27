/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.

*/


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
  		if(grid.size()<1 || grid[0].size() < 1) {
  			return 0;
  		}      

  		int rows = grid.size();
  		int cols = grid[0].size();

  		vector<vector<int> > minSum(rows,vector<int>(cols,0));

  		minSum[0][0] = grid[0][0];

  		for(int i = 1;i<rows;i++) {
  			minSum[i][0] = minSum[i-1][0] + grid[i][0];
           // cout<<minSum[i][0]<<endl;
  		}

  		for(int j = 1;j<cols;j++) {
  			minSum[0][j] = minSum[0][j-1] + grid[0][j];
  		}

  		for(int i = 1;i<rows;i++) {
  			for(int j = 1;j<cols;j++) {
  				minSum[i][j] = min(minSum[i-1][j],minSum[i][j-1]) + grid[i][j];
            
  				
  			}
  		}

  		return minSum[rows-1][cols-1];
    }
};