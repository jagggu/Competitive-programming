/*
Coin Sum Infinite
Problem Description

You are given a set of coins A. In how many ways can you make sum B assuming you have infinite amount of each coin in the set.

NOTE:

Coins in set A will be unique. Expected space complexity of this problem is O(B).
The answer can overflow. So, return the answer % (106 + 7).


Problem Constraints
1 <= A <= 500
1 <= A[i] <= 1000
1 <= B <= 50000



Input Format
First argument is an integer array A representing the set.
Second argument is an integer B.



Output Format
Return an integer denoting the number of ways.



Example Input
Input 1:

 A = [1, 2, 3]
 B = 4
Input 2:

 A = [10]
 B = 10


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 The 4 possible ways are:
 {1, 1, 1, 1}
 {1, 1, 2}
 {2, 2}
 {1, 3} 
Explanation 2:

 There is only 1 way to make sum 10.

 */



#define MOD 1000007

int Solution::coinchange2(vector<int> &A, int B) {

	int n = A.size();
	if (n < 1) {
		if (B == 0) {
			return 1;
		}
		return 0;
	}

	sort(A.begin(), A.end());

	vector<vector<int> > coins(B + 1, vector<int>(n + 1, 0));

	coins[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		coins[0][i] = 1;
	}

	for (int i = 1; i <= B; i++) {

		for (int j = 1; j <= n; j++) {

			for (int k = 1; k <= j; k++) {
				if (i >= A[k - 1]) {
					coins[i][j] = (coins[i][j] % MOD + coins[i-A[k-1]][k]%MOD)%MOD;
				}
			}
		}
	}

	return coins[B][n] % MOD;
}
