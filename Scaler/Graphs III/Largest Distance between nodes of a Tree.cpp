/*
Largest Distance between nodes of a Tree
Problem Description

Find largest distance Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes.

The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).

The nodes will be numbered 0 through N - 1.

The tree is given as an array A, there is an edge between nodes A[i] and i (0 <= i < N). Exactly one of the i's will have A[i] equal to -1, it will be root node.



Problem Constraints
2 <= |A| <= 40000



Input Format
First and only argument is vector A



Output Format
Return the length of the longest path



Example Input
Input 1:

 
A = [-1, 0]
Input 2:

 
A = [-1, 0, 0]


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 Path is 0 -> 1.
Explanation 2:

 Path is 1 -> 0 -> 2.



*/



pair<int,int> bfs(int src, int V, vector<vector<int> > &adj) {

	vector<int> dist(V,-1);
	dist[src] = 0;
	queue<pair<int,int> > q;
	q.push(make_pair(src,0));

	while(!q.empty()) {
		auto top = q.front();
		int currNode = top.first;
		int currDist = top.second;
		q.pop();

		for(int neighbor : adj[currNode]) {
			if(dist[neighbor] == -1) {
				dist[neighbor] = currDist+1;
				q.push(make_pair(neighbor,dist[neighbor]));
			}
		}
	}

	int maxDist = 0;
	int vertex = src;

	for(int i = 0;i<V;i++) {
		if(dist[i] > maxDist) {
			maxDist = dist[i];
			vertex = i;
		}
	}

	return make_pair(vertex,maxDist);
}

int Solution::solve(vector<int> &A) {

	int nodes = A.size();
	vector<vector<int> > adj(A.size());
 
	int root;
	for(int i = 0;i<A.size();i++) {
		if(A[i] == -1) {
			root = i;
			continue;
		}

		adj[i].push_back(A[i]);
		adj[A[i]].push_back(i);
	}

	pair<int,int> firstEndPoint = bfs(root,nodes,adj);
	pair<int,int> secondEndPoint = bfs(firstEndPoint.first,nodes,adj);

	return secondEndPoint.second;
}
