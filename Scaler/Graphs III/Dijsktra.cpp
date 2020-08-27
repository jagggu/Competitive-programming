/*
Dijsktra
Problem Description

Given a weighted undirected graph having A nodes and M weighted edges, and a source node C.

You have to find an integer array D of size A such that:

=> D[i] : Shortest distance form the C node to node i.

=> If node i is not reachable from C then -1.

Note:

There are no self-loops in the graph.

No multiple edges between two pair of vertices.

The graph may or may not be connected.

Nodes are numbered from 0 to A-1.

Your solution will run on multiple testcases. If you are using global variables make sure to clear them.



Problem Constraints
1 <= A <= 1e5

0 <= B[i][0],B[i][1] < A

0 <= B[i][2] <= 1e3

0 <= C < A



Input Format
The first argument given is an integer A, representing the number of nodes.

The second argument given is the matrix B of size M x 3, where nodes B[i][0] and B[i][1] are connected with an edge of weight B[i][2].

The third argument given is an integer C.



Output Format
Return the integer array D.



Example Input
Input 1:

A = 6
B = [   [0, 4, 9]
        [3, 4, 6] 
        [1, 2, 1] 
        [2, 5, 1] 
        [2, 4, 5] 
        [0, 3, 7] 
        [0, 1, 1] 
        [4, 5, 7] 
        [0, 5, 1] ] 
C = 4
Input 2:

A = 5
B = [   [0, 3, 4]
        [2, 3, 3] 
        [0, 1, 9] 
        [3, 4, 10] 
        [1, 3, 8]  ] 
C = 4


Example Output
Output 1:

D = [7, 6, 5, 6, 0, 6]
Output 2:

D = [14, 18, 13, 10, 0]


Example Explanation
Explanation 1:

 All Paths can be considered from the node C to get shortest path
Explanation 2:

 All Paths can be considered from the node C to get shortest path

*/



#define inf 10007

vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {


	vector<vector<pair<int,int> > > adj(A);

	for(int i = 0;i<B.size();i++) {
		int src = B[i][0];
		int dest = B[i][1];
		int wt = B[i][2];
		adj[src].push_back(make_pair(dest,wt));
		adj[dest].push_back(make_pair(src,wt));
	}

	vector<int> dist(A,inf);
	//vector<bool> visited(A,false);

	dist[C] = 0;
	vector<bool> visited(A,false);
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > minHeap;

	minHeap.push(make_pair(0,C));

	while(!minHeap.empty()) {
		pair<int,int> top = minHeap.top();
		minHeap.pop();
		int currDist = top.first;
		int currNode = top.second;

		if(visited[currNode] == true) {
			continue;
		}
		visited[currNode] = true;
		for(auto neighbor : adj[currNode]) {
			if(dist[neighbor.first] > currDist + neighbor.second) {
				dist[neighbor.first] = currDist + neighbor.second;
				minHeap.push(make_pair(dist[neighbor.first],neighbor.first));
			}
		}
	}

	for(int i = 0;i<A;i++) {
		if(dist[i] == inf) {
			dist[i] = -1;
		}
	}

	return dist;
}
