/*
Coins in a Line
There are A coins (Assume A is even) in a line.

Two players take turns to take a coin from one of the ends of the line until there are no more coins left.

The player with the larger amount of money wins.

Assume that you go first.

Return the maximum amount of money you can win.

Input Format:

The first and the only argument of input contains an integer array, A.
Output Format:

Return an integer representing the maximum amount of money you can win.
Constraints:

1 <= length(A) <= 500
1 <= A[i] <= 1e5
Examples:

Input 1:
    A = [1, 2, 3, 4]

Output 1:
    6

Explanation 1:

    You      : Pick 4
    Opponent : Pick 3
    You      : Pick 2
    Opponent : Pick 1

    Total money with you : 4 + 2 = 6

Input 2:
    A = [5, 4, 8, 10]

Output 2:
    15

Explanation 2:

    You      : Pick 10
    Opponent : Pick 8
    You      : Pick 5
    Opponent : Pick 4

    Total money with you : 10 + 5 = 15

    */



int maxcoinHelper(vector<int> &A, int i, int j, vector<vector<int> > &dp) {

	if(i > j) {
		return  0;
	}

	if(i == j) {
		return A[i];
	}

	if(dp[i][j] != -1) {
		return dp[i][j];
	}

	int first = A[i] + min(maxcoinHelper(A,i+2,j,dp), maxcoinHelper(A,i+1,j-1,dp));

	int last = A[j]  + min(maxcoinHelper(A,i,j-2,dp), maxcoinHelper(A,i+1,j-1,dp));

	return dp[i][j] = max(first,last);
}

int Solution::maxcoin(vector<int> &A) {
	if(A.size() < 1) {
		return 0;
	}	

	int n = A.size();
	vector<vector<int> > dp(n,vector<int>(n,-1));
	return maxcoinHelper(A,0,n-1,dp);
}
