/*
Edge in MST
Problem Description

Given a undirected weighted graph with A nodes labelled from 1 to A with M edges given in a form of 2D-matrix B of size M * 3 where B[i][0] and B[i][1] denotes the two nodes connected by an edge of weight B[i][2].

For each edge check whether it belongs to any of the possible minimum spanning tree or not , return 1 if it belongs else return 0.

Return an one-dimensional binary array of size M denoting answer for each edge.

NOTE:

The graph may be disconnected in that case consider mst for each component.
No self-loops and no multiple edges present.
Answers in output array must be in order with the input array B output[i] must denote the answer of edge B[i][0] to B[i][1].


Problem Constraints
1 <= A, M <= 3*105

1 <= B[i][0], B[i][1] <= A

1 <= B[i][1] <= 103



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given is an matrix B of size M x 3 which represents the M edges such that there is a edge between node B[i][0] and node B[i][1] with weight B[i][2].



Output Format
Return an one-dimensional binary array of size M denoting answer for each edge.



Example Input
Input 1:

 A = 3
 B = [ [1, 2, 2]
       [1, 3, 2]
       [2, 3, 3]
     ]


Example Output
Output 1:

 [1, 1, 0]


Example Explanation
Explanation 1:

 Edge (1, 2) with weight 2 is included in the MST           1
                                                          /   \
                                                         2     3
 Edge (1, 3) with weight 2 is included in the same MST mentioned above.
 Edge (2,3) with weight 3 cannot be included in any of the mst possible.
 So we will return [1, 1, 0]


*/


bool myComparator(vector<int> &a, vector<int> &b) {
	return a[2] < b[2];
}

int find(int node, vector<int> &parent) {
	if (parent[node] == node) {
		return node;
	}

	parent[node] = find(parent[node], parent);

	return parent[node];
}

vector<int> Solution::solve(int A, vector<vector<int> > &B) {

	int n = B.size();

	vector<int> isEdge(n, 0);


	//sort(B.begin(),B.end(),myComparator);

	set<pair<int, int> > canEdge;

	map<int, vector<pair<int, int> > > m;

	for (int i = 0; i < n; i++) {
		int src = B[i][0];
		int dest = B[i][1];
		int wt = B[i][2];

		m[wt].push_back(make_pair(src, dest));
	}

	vector<int> parent(A + 1);
	vector<int> size(A + 1, 1);
	//vector<int> canEdge(n);
	for (int i = 1; i <= A; i++) {
		parent[i] = i;
	}

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		for (auto itr2 : itr->second) {
			//cout<<itr2.first<<' '<<itr2.second<<endl;
			int a = itr2.first;
			int b = itr2.second;

			int c = find(a, parent);
			int d = find(b, parent);

			if (c != d) {
				canEdge.insert(make_pair(a, b));
			}


		}

		for (auto itr2 : itr->second) {
			int a = itr2.first;
			int b = itr2.second;

			int c = find(a, parent);
			int d = find(b, parent);

			if (c != d) {
				if (size[c] < size[d]) {
					swap(c, d);
				}

				parent[d] = c;
				size[c] += size[d];

			}
		}
		//return isEdge;
	}

	for(int i = 0;i<n;i++) {
		int src = B[i][0];
		int dest = B[i][1];
		if(canEdge.find(make_pair(src,dest)) != canEdge.end()) {
			isEdge[i] = 1;
		}
	}

	return isEdge;
}