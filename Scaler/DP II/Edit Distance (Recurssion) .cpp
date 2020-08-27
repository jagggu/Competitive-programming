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


vector<vector<int> > dist;

int minDistanceHelper(string A, string B, int i, int j) {
	if(i == 0 || j == 0) {
		return max(i,j);
	}
	
//	cout<<i<<' '<<j<<endl;

	if(dist[i][j] != -1) {
	    //cout<<"checkPoint"<<endl;
		return dist[i][j];
	}

	if(A[i-1] == B[j-1]) {
		return dist[i][j] = minDistanceHelper(A,B,i-1,j-1);
	} else {
		 dist[i][j] =  (min(minDistanceHelper(A,B,i-1,j-1),min(minDistanceHelper(A,B,i,j-1), minDistanceHelper(A,B,i-1,j)))) + 1;
		
	//	dist[i][j] += 1;
		return dist[i][j];
	}
}


int Solution::minDistance(string A, string B) {

	int ALen = A.size();
	int BLen = B.size();

	dist.clear();
    vector<int> tmp;
	for(int i = 0;i<=ALen;i++) {
	    tmp.clear();
		for(int j = 0;j<=BLen;j++) {
		  tmp.push_back(-1);
		}
		dist.push_back(tmp);
	}

	int ans = minDistanceHelper(A,B,ALen,BLen);

	return ans;
}