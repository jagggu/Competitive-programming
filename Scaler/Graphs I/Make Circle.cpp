
void dfs(int src, vector<vector<int> > &adj, vector<bool> &visited) {
	visited[src] = true;

	for(auto neighbor : adj[src]) {
		if(!visited[neighbor]) {
			dfs(neighbor,adj,visited);
		}
	}
}

int Solution::solve(vector<string> &A) {

	vector<int> inDegree(27,0);
	vector<int> outDegree(27,0);

	vector<vector<int> > adj(26);

	for(int i = 0;i<A.size();i++) {
		string str = A[i];
		int src = str[0] - 'a';
		int dest = str[str.size()-1] - 'a';
		outDegree[src]++;
		inDegree[dest]++;
		adj[src].push_back(dest);
	}

	int connectedComponents = 0;
	vector<bool> visited(26,false);
	for(int i = 0;i<26;i++) {
		if(!visited[i]) {
			connectedComponents++;
			if(connectedComponents > 1) {
				return 0;
			}
			dfs(i,adj,visited);
		}
	}



	for(int i = 0;i<26;i++) {
		if(inDegree[i] != outDegree[i]) {
			return 0;
		}
	}

	return 1;
}
