/*
Problem Description
Given N balls on the X-axis, where i-th ball is on position A[i]. Call a ball an endpoint ball if it has the smallest or largest position. Each turn, you pick up an endpoint ball and move it to an unoccupied position so that it is no longer an endpoint ball. The game ends when you cannot make any more moves, i.e the balls are in consecutive positions. When the game ends, what is the minimum and maximum number of moves that you could have made? Return the answer as an length 2 array: answer = [minimum_moves, maximum_moves]    


Problem Constraints
3 <= N <= 105
1 <= A[i] <= 109


Input Format
The first and the only argument contains an integer array A, representing the X-coordinates of the balls.


Output Format
Return an one-dimensional array of 2 integers, representing the minimum and maximum number of moves required to bring all the balls together.


Example Input
Input 1:
 A = [1, 2, 3]
Input 2:
 A = [1, 3, 5, 7]
    


Example Output
Output 1:
 [0, 0]
Output 2:
 [2, 2]
    


Example Explanation
Explanation 1:
 The balls are already in consecutive positions, so there is no need to move any of them.
Explanation 2:
 In both the case of minimum and maximum number of moves, this process will take place:
        1. Move ball at position 1 to position 6.
        2. Move ball at position 7 to position 4.

       */


vector<int> Solution::solve(vector<int> &A) {

	int i = 0;
	int j = 0;
	int minMoves = A.size();
	int n = A.size();
	sort(A.begin(),A.end());
	while(j < n) {
		int windowSize = A[j]-A[i]+1;
		int stonesCount = j-i+1;

		if(windowSize > n) {
			i++;
			continue;
		}
		if(windowSize == n-1 && stonesCount == n-1) {
			minMoves = min(minMoves,2);
		} else {
			//No.of Elements outside the window
			int elements = n - stonesCount;
			minMoves = min(minMoves,elements);
		}
		//cout<<minMoves<<endl;
		j++;
	}

	int fromLeft = A[n-1]-A[1]-1-(n-3);
	int fromRight = A[n-2]-A[0]-1-(n-3);
	vector<int> res;
	res.push_back(minMoves);
	res.push_back(max(fromRight,fromLeft));
	return res;

}
