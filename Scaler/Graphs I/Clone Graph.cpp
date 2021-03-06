/*
Clone Graph
Problem Description

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.



Problem Constraints
1 <= Number of nodes <= 105



Input Format
First and only argument is a node A denoting the root of the undirected graph.



Output Format
Return the node denoting the root of the new clone graph.



Example Input
Input 1:

      1
    / | \
   3  2  4
        / \
       5   6
Input 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Output
Output 1:

 Output will the same graph but with new pointers:
      1
    / | \
   3  2  4
        / \
       5   6
Output 2:

      1
     / \
    3   4
   /   /|\
  2   5 7 6


Example Explanation
Explanation 1:

 We need to return the same graph, but the pointers to the node should be different.

 */



/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    
    if(node == NULL) {
    	return NULL;
    }

	//UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
	queue<UndirectedGraphNode*> q;
	unordered_map<UndirectedGraphNode*,bool> visited;

	unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mapNode;


	q.push(node);
	visited[node] = true;

	while(!q.empty()) {
		UndirectedGraphNode *currNode = q.front();
		UndirectedGraphNode *tmp = new UndirectedGraphNode(currNode->label);
		mapNode[currNode] = tmp;
		q.pop();
		for(auto neighbor : currNode->neighbors) {
			if(!visited[neighbor]) {
				visited[neighbor] = true;
				//UndirectedGraphNode *copyNeighbor = new UndirectedGraphNode(neighbor->label);
				//currNode->neighbors
				q.push(neighbor);
			}
		}
	}

	visited.clear();
//	q.clear()

	q.push(node);
	//visited[node] = true;

	while(!q.empty()) {
		UndirectedGraphNode *currNode = q.front();
		q.pop();
		if(visited[currNode]) {
		    continue;
		}
		
		visited[currNode] = true;

		for(auto neighbor: currNode->neighbors) {
			//if(!visited[neighbor]) {
				//visited[neighbor] = true;
				mapNode[currNode]->neighbors.push_back(mapNode[neighbor]);
				//mapNode[neighbor]->neighbors.push_back(mapNode[currNode]);
				q.push(neighbor);
				
		}
	}

	return mapNode[node];
}
