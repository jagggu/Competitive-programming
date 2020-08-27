/*
Little Ponny and School Assembly
Problem Description

You are given B boys and G girls.

You want to arrange them to form a school assembly such that no more than C boys and no more thanD girls are standing together.

Two arrangements are different if there exists one position such that there is a girl at this position in one of them and a boy in another.

Since, the result can be large, print it modulo 109 + 7



Problem Constraints
1 <= B, G <= 100

1 <= C, D <= 10



Input Format
The argument of the input is the array A containing 4 elements representing the value of B, G, C and D respectively.



Output Format
Return an integer representing the answer



Example Input
Input 1:

A: [2, 1, 1, 10]
Input 2:

A: [2, 3, 1, 2]
Input 3:

A: [2, 4, 1, 1]


Example Output
Output 1:

1
Output 2:

5
Output 3:

0


Example Explanation
Explanation 1:

In this example the only possible assembly is: BGB
Explanation 2:

In this example 5 possible assembly exist: 

BGBGG
BGGBG
GBGBG 
GBGGB
GGBGB
Explanation 3:

There is no possible arrangement for this example

*/


int dp[101][101][11][11];

long long int MOD = 1e9+7;

int solveHelper(int remBoys, int remGirls, int prevConsecutiveBoys, int prevConsecutiveGirls, int maxBoys, int maxGirls) {

	int ans = 0;

	if(remBoys == 0 && remGirls == 0) {
		return 1;
	}

	if(dp[remBoys][remGirls][prevConsecutiveBoys][prevConsecutiveGirls] != -1) {
		return dp[remBoys][remGirls][prevConsecutiveBoys][prevConsecutiveGirls];
	}

	if(remBoys>0 && prevConsecutiveBoys<maxBoys) {
		ans = (ans%MOD + solveHelper(remBoys-1,remGirls,prevConsecutiveBoys+1,0,maxBoys,maxGirls)%MOD)%MOD;
	}

	if(remGirls>0 && prevConsecutiveGirls<maxGirls) {
		ans = (ans%MOD + solveHelper(remBoys,remGirls-1,0,prevConsecutiveGirls+1,maxBoys,maxGirls)%MOD)%MOD;
	}

	return dp[remBoys][remGirls][prevConsecutiveBoys][prevConsecutiveGirls] =  ans%MOD;
}


int Solution::solve(vector<int> &A) {

//	int dp[A[0]+1][A[1]+1][A[2]+1][A[3]+1];
	for(int i = 0;i<=100;i++) {
		for(int j = 0;j<=100;j++) {
			for(int k = 0;k<=10;k++) {
				for(int l = 0;l<=10;l++) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}

	return solveHelper(A[0],A[1],0,0,A[2],A[3]);
}
