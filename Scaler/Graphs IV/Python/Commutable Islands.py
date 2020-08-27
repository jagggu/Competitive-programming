def find(node,parent):
		if parent[node] == node:
			return node
		parent[node] = find(parent[node],parent)

		return parent[node]

class Solution:
	# @param A : integer
	# @param B : list of list of integers
	# @return an integer



	def solve(self, A, B):

		parent = [i for i in range(A+1)]

		size = [1 for i in range(A+1)]

		B.sort(key = lambda x:x[2])

		min_wt = 0

		for i in range(len(B)):
			src = B[i][0]
			dest = B[i][1]
			wt = B[i][2]

			c = find(src,parent)
			d = find(dest, parent)

			if c != d:
				if size[c] < size[d]:
					c,d = d,c
				parent[d] = c
				size[c] += size[d]
				min_wt += wt

		return min_wt