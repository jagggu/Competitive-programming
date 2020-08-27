def find(node,parent):
    	if parent[node] == node:
    		return node

    	parent[node] = find(parent[node],parent)

    	return parent[node]


class Solution:
    # @param A : integer
    # @param B : list of integers
    # @param C : list of list of integers
    # @param D : integer
    # @return an integer

    

    def solve(self, A, B, C, D):
    	parent = [0]*(A+1)
    	size = [1]*(A+1)
    	strength = [0] * (A+1)

    	for i in range(1,A+1):
    		parent[i] = i
    		strength[i] = B[i-1]

    	for i in range(len(C)):
    		a = C[i][0]
    		b = C[i][1]

    		c = find(a,parent)
    		d = find(b,parent)

    		if c != d:
    			if size[c] < size[d]:
    				c,d = d,c
    			parent[d] = c
    			size[c] += size[d]
    			strength[c] += strength[d]

    	num_batches = 0

    	for i in range(1,A+1):
    		if parent[i] == i and strength[i] >= D:
    			num_batches+=1

    	return num_batches



