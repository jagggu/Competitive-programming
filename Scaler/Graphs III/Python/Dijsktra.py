
inf = 10007
import heapq
class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @param C : integer
    # @return a list of integers
    def solve(self, A, B, C):
    	dist = [inf] * A;
    	dist[C] = 0;
    	heapq.push((0,C))
    	visited = [False] * A;
    	minHeap = [(0,C)]
    	heapq.heapify(minHeap)
    	adj = [[] for i in range(len(B))]
    	
    	for i in range(len(B)):
    		src = B[i][0]
    		dest = B[i][1]
    		wt = B[i][2]
    		adj[src].append((dest,wt))
    		adj[dest].append((src,wt))

    	while len(minHeap)>0:
    		curr_dist, curr_node = heapq.heappop(minHeap)
    		if visited[curr_node] == True:
    			continue
    		visited[curr_node] = True
    		for neighbor in adj[curr_node]:
    			neighbor_node = neighbor[0]
    			neighbor_dist = neighbor[1]
    			if dist[neighbor_node] > curr_dist + neighbor_dist:
    				dist[neighbor_node] = curr_dist + neighbor_dist
    				heapq.heappush(minHeap,(dist[neighbor_node],neighbor_node))

    	for index,dist_obj in enumerate(dist):
    		if dist_obj == inf:
    			dist[index] = -1

    	return dist

