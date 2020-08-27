/*
First Depth First Search
Problem Description

You are given n towns (1 to n). All towns are connected via unique directed path as mentioned in the input.

Given 2 towns find whether you can reach the first town from the second without repeating any edge.

x y : query to find whether x is reachable from y.

Input contains an integer array A of size n and 2 integers x and y ( 1 <= x, y <= n ).

There exist a directed edge from A[i] to i+1 for every 1 <= i < n. Also, it's guaranteed that A[i] <= i.

NOTE: Array A is 0-indexed.



Problem Constraints
1 <= n <= 100000



Input Format
First argument is vector A

Second argument is integer B

Third argument is integer C



Output Format
Return 1 if reachable, 0 otherwise.



Example Input
Input 1:

 A = [1, 1, 2]
 B = 1
 C = 2
Input 2:

 A = [1, 1, 2]
 B = 2
 C = 1


Example Output
Output 1:

 0
Output 2:

 1


Example Explanation
Explanation 1:

 Tree is 1--> 2--> 3 and hence 1 is not reachable from 2.
Explanation 2:

 Tree is 1--> 2--> 3 and hence 2 is reachable from 1.

*/





int Solution::solve(vector<int> &A, const int B, const int C) {
    if(C > B) {
        return 0;
    }
    
    //Both source and destination are equal
    if(C == B) {
        return 1;
    }
    
    int n = A.size();
    vector<vector<int> > adjList(n+1);

    for(int i = 0;i<n;i++) {
    	adjList[A[i]].push_back(i+1);
    }

    queue<int> q;
    int src = C;
    int dest = B;

    q.push(src);
    vector<bool> visited(n+1,false);
    visited[src] = true;

    while(!q.empty()) {
    	int size = q.size();
    	for(int i = 0;i<size;i++) {
    		int currNode = q.front();
    		q.pop();
    		for(int neighbour : adjList[currNode]) {
    			if(neighbour == dest) {
    				return 1;
    			}
    			if(!visited[neighbour]) {
    				visited[neighbour] = true;
    				q.push(neighbour);
    			}
    		}
    	}
    }

    return 0;
}
