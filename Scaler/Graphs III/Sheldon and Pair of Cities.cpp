
#define inf 1000009

vector<int> Solution::solve(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F, vector<int> &G, vector<int> &H) {

	vector<vector<int> > graph(A+1,vector<int>(A+1,inf));

	vector<vector<int> > dist(A+1,vector<int>(A+1));

	for(int i = 0;i<B;i++) {
		int src = D[i];
		int dest = E[i];
		int wt = F[i];

		graph[src][dest] = wt;
		//graph[dest][src] = wt;
	}

	for(int i = 0;i<=A;i++) {
		graph[i][i] = 0;
	}

	for(int i = 0;i<=A;i++) {
		for(int j = 0;j<=A;j++) {
			dist[i][j] = graph[i][j];
		}
	}

	for(int k = 0;k<=A;k++) {
		for(int i = 0;i<=A;i++) {
			for(int j = 0;j<=A;j++) {
				//graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
				
				if(dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	vector<int> res;

	for(int i = 0;i<C;i++) {
		int src = G[i];
		int dest = H[i];
		int tmp = dist[src][dest];
		if(tmp == inf) {
			tmp = -1;
		}
		res.push_back(tmp);
	}

	return res;
}
