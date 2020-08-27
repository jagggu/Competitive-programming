/*
Minimum Weighted Cycle
Problem Description

Given an integer A, representing number of vertices in a graph.

Also you are given a matrix of integers B of size N x 3 where N represents number of Edges in a Graph and Triplet (B[i][0], B[i][1], B[i][2]) implies there is an undirected edge between B[i][0] and B[i][1] and weight of that edge is

B[i][2].

Find and return the weight of minimum weighted cycle and if there is no cycle return -1 instead.

NOTE: Graph may contain multiple edges and self loops.



Problem Constraints
1 <= A <= 1000

1 <= B[i][0], B[i][1] <= A

1 <= B[i][2] <= 100000



Input Format
The first argument given is the integer A.

The second argument given is the integer matrix B.



Output Format
Return the weight of minimum weighted cycle and if there is no cycle return -1 instead.



Example Input
Input 1:

 A = 4
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]
        [3 ,4 ,1]
        [4 ,1 ,4]
        [1 ,3 ,15]  ]
Input 2:

 A = 3
 B = [  [1 ,2 ,2]
        [2 ,3 ,3]  ]


Example Output
Output 1:

 10 
Output 2:

 -1


Example Explanation
Explanation 1:

 Given graph forms 3 cycles
 1. 1 ---> 2 ---> 3 ---> 4 ---> 1 weight = 10
 2. 1 ---> 2 ---> 3 ---> 1 weight = 20
 3. 1 ---> 3---> 4 ---> 1 weight = 20
 so answer would be 10.
Explanation 2:

 Given graph forms 0 cycles so return -1.

 */



#define inf 100000

void addEdge(vector<vector<pair<int, int> > > &adj, int src, int dest, int wt) {
	adj[src].push_back(make_pair(dest, wt));
	adj[dest].push_back(make_pair(src, wt));
}

void removeEdge(vector<vector<pair<int, int> > > &adj, int src, int dest, int wt) {
	//adj[src].remove(make_pair(dest, wt));
	//adj[dest].remove(make_pair(src, wt));

   
   // cout<<"Src Size before: "<<adj[src].size()<<endl;
    //cout<<"Dest size befor: "<<adj[dest].size()<<endl;
	auto itr1 = remove(adj[src].begin(), adj[src].end(), make_pair(dest,wt));
	auto itr2 = remove(adj[dest].begin(), adj[dest].end(), make_pair(src,wt));
	adj[src].erase(itr1+1);
	adj[dest].erase(itr2+1);
	/*
	cout<<"Src Size After: "<<adj[src].size()<<endl;
    cout<<"Dest size After: "<<adj[dest].size()<<endl;
	 	int A = 4;
	for(int i = 1;i<=A;i++) {
		    cout<<i<<" --> ";
		    for(auto neighbor : adj[i]) {
		        cout<<"("<<neighbor.first<<' '<<neighbor.second<<") , ";
		    }
		    
		    cout<<endl;
		}
    */
}

void dijkstra(int src, vector<vector<pair<int, int> > > &adj, vector<int> &dist, int A) {
	vector<bool> visited(A + 1, false);

	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

	pq.push(make_pair(0, src));
	
	dist[src] = 0;

	while (!pq.empty()) {
		auto top = pq.top();
		int currNode = top.second;
		int currDist = top.first;
		pq.pop();

		if (visited[currNode] == true) {
			continue;
		}

		visited[currNode] = true;

		for (auto neighbor : adj[currNode]) {
			int neighborNode = neighbor.first;
			int wt = neighbor.second;

			if (dist[neighborNode] > currDist + wt) {
				dist[neighborNode] = currDist + wt;
				pq.push(make_pair(dist[neighborNode],neighborNode));
			}
		}
	}
}

int Solution::solve(int A, vector<vector<int> > &B) {

	vector<vector<pair<int, int> > > adj(A + 1);

	for (int i = 0; i < B.size(); i++) {
		int src = B[i][0];
		int dest = B[i][1];
		int wt = B[i][2];

		adj[src].push_back(make_pair(dest, wt));
		adj[dest].push_back(make_pair(src, wt));
	}

	priority_queue<pair<int, int>, vector<pair<int, int> > , greater<pair<int, int> > > pq;

	int minWtCycle = inf;
	
	

	for (int i = 0; i < B.size(); i++) {


		int src = B[i][0];
		int dest = B[i][1];
		int wt = B[i][2];

		removeEdge(adj, src, dest, wt);
		
	//	cout<<"Removed Edge: "<<src<<' '<<dest<<' '<<wt<<endl;
	    	

		vector<int> dist(A + 1, inf);

		dijkstra(src, adj, dist, A);

		addEdge(adj, src, dest, wt);


    //cout<<src<<" "<<dest<<' '<<dist[dest]<<' '<<' '<<wt<<' '<<dist[dest] + wt<<endl;
		minWtCycle = min(minWtCycle, dist[dest] + wt);
	}

	if (minWtCycle == inf) {
		return -1;
	}

	return minWtCycle;
}
