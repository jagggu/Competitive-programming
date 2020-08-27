/*
Poisonous Graph
Problem Description

You are given an undirected unweighted graph consisting of A vertices and M edges given in a form of 2D Matrix B of size M x 2 where (B[i][0], B][i][1]) denotes two nodes connected by an edge.

You have to write a number on each vertex of the graph. Each number should be 1, 2 or 3. The graph becomes Poisonous if for each edge the sum of numbers on vertices connected by this edge is odd.

Calculate the number of possible ways to write numbers 1, 2 or 3 on vertices so the graph becomes poisonous. Since this number may be large, return it modulo 998244353.

NOTE:

Note that you have to write exactly one number on each vertex.
The graph does not have any self-loops or multiple edges.
Nodes are labelled from 1 to A.


Problem Constraints
1 <= A <= 3*105

0 <= M <= 3*105

1 <= B[i][0], B[i][1] <= A

B[i][0] != B[i][1]



Input Format
First argument is an integer A denoting the number of nodes.

Second argument is an 2D Matrix B of size M x 2 denoting the M edges.



Output Format
Return one integer denoting the number of possible ways to write numbers 1, 2 or 3 on the vertices of given graph so it becomes Poisonous . Since answer may be large, print it modulo 998244353.



Example Input
Input 1:

 A = 2
 B = [  [1, 2]
     ]
Input 2:

 A = 4
 B = [  [1, 2]
        [1, 3]
        [1, 4]
        [2, 3]
        [2, 4]
        [3, 4]
    ]


Example Output
Output 1:

 4
Output 2:

 0


Example Explanation
Explanation 1:

 There are 4 ways to make the graph poisonous. i.e, writing number on node 1 and 2 as,
    [1, 2] , [3, 2], [2, 1] or [2, 3] repsectively.
Explanation 2:

 There is no way to make the graph poisonous.

 */


#define ll long long int

ll MOD = 998244353;

ll findPower(int base, int n) {
	ll ans = 1;

	while(n>0) {
		if(n&1) {
			ans = (ans%MOD * base%MOD) % MOD;
			n-=1;
		} else {
			base = (base%MOD * base%MOD) % MOD;
			n/=2;
		}
	}

	return ans%MOD;
}

void dfs(int node, int currColor, vector<int> &colors, vector<vector<int> > &adj, bool &isBipartite,int &evenCnt, int &oddCnt) {
	colors[node] = currColor;
	if(currColor == 0) {
		evenCnt++;
	} else {
		oddCnt++;
	}
	for(auto neighbor : adj[node]) {
		if(colors[neighbor] == currColor) {
			isBipartite = false;
			return;
		} else if(colors[neighbor] == 1 - currColor) {
			continue;
		} else {
			dfs(neighbor,1-currColor, colors, adj, isBipartite, evenCnt, oddCnt);
		}
	}
}

int Solution::solve(int A, vector<vector<int> > &B) {

	vector<vector<int> > adj(A+1);

	for(int i = 0;i<B.size();i++) {
		int src = B[i][0];
		int dest = B[i][1];

		adj[src].push_back(dest);
		adj[dest].push_back(src);
	}

	vector<int> colors(A+1,-1);
	int evenCnt = 0;
	int oddCnt = 0;
	bool isBipartite = true;
	ll ans = 1;
	for(int i = 1;i<=A;i++) {
		if(colors[i] == -1) {

			dfs(i,0,colors,adj,isBipartite,evenCnt,oddCnt);
			if(isBipartite == false) {
				return 0;
			}
			ll tmp1 = findPower(2,evenCnt);
			ll tmp2 = findPower(2,oddCnt);

			ll tmp3 = (tmp1%MOD + tmp2%MOD) % MOD;

			ans = (ans%MOD * tmp3%MOD) % MOD;
			evenCnt = 0;
			oddCnt = 0;
			isBipartite = true;
		}
	}

	return ans%MOD;

}
