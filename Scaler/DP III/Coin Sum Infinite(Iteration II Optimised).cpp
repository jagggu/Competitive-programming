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

//dp[i][j] --> No of ways to get sum i using the coins <= A(coins)[j]

int Solution::coinchange2(vector<int> &A, int B) {

	int n = A.size();
	if(n<1) {
		if(B == 0) {
			return 1;
		}
		return 0;
	}

	vector<vector<int> > coins(B+1,vector<int>(2,0));
	coins[0][0] = 1;
	coins[0][1] = 1;

	sort(A.begin(),A.end());

	for(int j = 1;j<=n;j++) {
		for(int i = 1;i<=B;i++) {
			if(i>=A[j-1]) {
				coins[i][j%2] = (coins[i-A[j-1]][j%2]%MOD + coins[i][(j-1)%2]%MOD)%MOD;
			} else {
			    coins[i][j%2] = coins[i][(j-1)%2];
			}
		}
	}

	return coins[B][n%2];
}
