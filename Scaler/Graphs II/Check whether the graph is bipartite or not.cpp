/*
Check whether the graph is bipartite or not
Problem Description

Given a undirected graph having A nodes. A matrix B of size M x 2 is given which represents the edges such that there is an edge between B[i][0] and B[i][1].

Find whether the given graph is bipartite or not.

A graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B

Note:

There are no self-loops in the graph.

No multiple edges between two pair of vertices.

The graph may or may not be connected.

Nodes are Numbered from 0 to A-1.

Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



Problem Constraints
1 <= A <= 100000

1 <= M <= min(A*(A-1)/2,200000)

0 <= B[i][0],B[i][1] < A



Input Format
The first argument given is an integer A.

The second argument given is the matrix B.



Output Format
Return 1 if the given graph is bipartide else return 0.



Example Input
Input 1:

A = 2
B = [ [0, 1] ]
Input 2:

A = 3
B = [ [0, 1], [0, 2], [1, 2] ]


Example Output
Output 1:

1
Output 2:

0


Example Explanation
Explanation 1:

Put 0 and 1 into 2 different subsets.
Explanation 2:

 
It is impossible to break the graph down to make two different subsets for bipartite matching


*/

void dfs(int node, int currColor, vector<int> &colors, vector<vector<int> > &adj, bool &isBipartite) {
	colors[node] = currColor;

	for (int neighbor : adj[node]) {
		if (colors[neighbor] == currColor) {
			isBipartite = false;
			return;

		} else if (colors[neighbor] == 1 - currColor) {
			continue;
		} else {
			dfs(neighbor, 1 - currColor, colors, adj, isBipartite);
		}
	}
}


int Solution::solve(int A, vector<vector<int> > &B) {

	vector<vector<int> > adj(A + 1);

	for (int i = 0; i < B.size(); i++) {
		int src = B[i][0];
		int dest = B[i][1];

		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}

	bool isBipartite = true;
	vector<int> colors(A + 1, -1);
	for (int i = 0; i < A; i++) {
		if (colors[i] == -1) {
			dfs(i, 1, colors, adj, isBipartite);
		}
	}

	return isBipartite;
}
