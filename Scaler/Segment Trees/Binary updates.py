segTree = []

def buildTree(node, start, end):
	global segTree
	if start == end:
		segTree[node]=1
		return
	mid = (start + end)//2
	buildTree(2*node,start,mid)
	buildTree(2*node+1,mid+1,end)
	segTree[node] = segTree[2*node] + segTree[2*node+1]

def update(node, start, end, indx):
	global segTree
	if start == end:
		segTree[node] = 0
		return
	mid = (start+end)//2
	if start<=indx and indx<=mid:
		update(2*node,start,mid,indx)
	else:
		update(2*node+1,mid+1,end,indx)

	segTree[node] = segTree[2*node] + segTree[2*node+1]

def query(node,start,end,k):
	if segTree[node] < k:
		return -1

	if start == end:
		return start

	mid = (start+end)//2

	leftOnes = segTree[2*node]
	if leftOnes>=k:
		return query(2*node,start,mid,k)
	else:
		return query(2*node+1,mid+1,end,k-leftOnes) 

class Solution:
    # @param A : integer
    # @param B : list of list of integers
    # @return a list of integers
    def solve(self, A, B):
    	global segTree
    	segTree = []
    	segTree = [0]*(4*A)
        res = []
    	buildTree(1,0,A-1);

    	q = len(B)

    	for i in range(q):
    		if B[i][0] == 0:
    			update(1,0,A-1,B[i][1]-1)
    		else:
    			ans = query(1,0,A-1,B[i][1])
    			if ans != -1:
    				ans+=1
    			res.append(ans)

    	return res

