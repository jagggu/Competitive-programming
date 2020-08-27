/*
Edit Distance
Problem Description

Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character


Problem Constraints
1 <= length(A), length(B) <= 450



Input Format
The first argument of input contains a string, A.
The second argument of input contains a string, B.



Output Format
Return an integer, representing the minimum number of steps required.



Example Input
Input 1:

 A = "abad"
 B = "abac"
Input 2:

 A = "Anshuman"
 B = "Antihuman


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Exlanation 1:

 A = "abad" and B = "abac"
 After applying operation: Replace d with c. We get A = B.
 
Explanation 2:

 A = "Anshuman" and B = "Antihuman"
 After applying operations: Replace s with t and insert i before h. We get A = B.

 */

/*
	dp[i][j] --> min Edit distance from (0,0) to (i,j)
*/



int Solution::minDistance(string A, string B) {

	int ALen = A.size();
	int BLen = B.size();

	vector<vector<int> > dist(ALen + 1, vector<int>(BLen + 1));

	dist[0][0] = 0;
	for (int i = 1; i <= ALen; i++) {
		dist[i][0] = i;
	}

	for (int i = 1; i <= BLen; i++) {
		dist[0][i] = i;
	}

	for (int i = 1; i <= ALen; i++) {
		for (int j = 1; j <= BLen; j++) {
			if (A[i - 1] == B[j - 1]) {
				dist[i][j] = dist[i - 1][j - 1];
			} else {
				dist[i][j] = 1 + min(dist[i - 1][j - 1], min(dist[i][j - 1], dist[i - 1][j]));
			}
		}
	}

	return dist[ALen][BLen];
}
