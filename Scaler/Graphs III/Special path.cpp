
#define inf 100009


struct Info {
	int dist;
	int node;
	int special;
	int nonSpecial;
};

class MyComparator {
public:
	int ()operator(Info f1, Info f2) {
		return f1.dist > f2.dist;
	}
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C, int D) {

	int nodes = A.size();

	vector<vector<pair<int,int> > > adj(nodes+1);
	for(int i = 0;i<B.size();i++) {
		int src = B[i][0];
		int dest = B[i][1];
		int wt = B[i][2];
		adj[src].push_back(make_pair(dest,wt));
		adj[dest].push_back(make_pair(src,wt));
	}

	int dist[nodes+1][11][11];
	int visited[nodes+1][11][11];

	for(int i = 0;i<=nodes;i++) {
		for(int j = 0;j<=10;j++) {
			for(int k = 0;k<=10;k++) {
				dist[i][j][k] = inf;
				visited[i][j][k] = false;
			}
		}
	}

	pripority_queue<Info,vector<Info>, MyComparator > minHeap;

	Info f;
	f.dist = 0;
	f.src = 1;
	f.special = A[1] == 1;
	f.nonSpecial = A[1] == 0;
	minHeap.push(f);

	while(!minHeap.empty()) {
		Info top = minHeap.top();
		minHeap.pop();
		int currNode = top.node;
		int currDist = top.dist;
		int spl = top.special;
		int nonSpl = top.nonSpecial;
		if(visited[currNode][spl][nonSpl]) {
			continue;
		}

		visited[currNode][spl][nonSpl] = true;

		for(auto neighbor : adj[currNode]) {
			int wt = neighbor.second;
			int neighborNode = neighbor.first;

			spl += A[neighborNode] == 1;
			//spl = min(spl,10);
			nonSpl += A[neighborNode] == 0;

			if(dist[neighborNode][spl][nonSpl] > currDist + wt){
				dist[neighborNode][spl][nonSpl] = currDist + wt;
				Info tmp;
				tmp.node = neighborNode;
				tmp.dist = dist[neighborNode];
				tmp.special = min(spl,10);
				tmp.nonSpecial = min(nonSpl,10);
				minHeap.push(tmp);
			}
		}
	}

	return dist[A.size()][C][D] == inf?-1:dist[nodes][C][D];

}
