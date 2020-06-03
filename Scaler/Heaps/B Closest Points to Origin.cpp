/*
B Closest Points to Origin
Problem Description
We have a list A, of points(x,y) on the plane. Find the B closest points to the origin (0, 0). Here, the distance between two points on a plane is the Euclidean distance. You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.) NOTE: Euclidean distance between two points P1(x1,y1) and P2(x2,y2) is sqrt( (x1-x2)^2 + (y1-y2)^2 ).     


Problem Constraints
1 <= B <= length of the list A <= 100000
-100000 <= A[i][0] <= 100000
-100000 <= A[i][1] <= 100000


Input Format
The argument given is list A and an integer B.


Output Format
Return the B closest points to the origin (0, 0) in any order.


Example Input
Input 1:
 A = [ 
       [1, 3],
       [-2, 2] 
     ]
 B = 1
Input 2:
 A = [
       [1, -1],
       [2, -1]
     ] 
 B = 1
 


Example Output
Output 1:
 [ [-2, 2] ]
Output 2:
 [ [1, -1] ]
 


Example Explanation
Explanation 1:
 The Euclidean distance will be sqrt(10) for point [1,3] and sqrt(8) for point [-2,2].
 So one closest point will be [-2,2].
Explanation 2:
 The Euclidean distance will be sqrt(2) for point [1,-1] and sqrt(5) for point [2,-1].
 So one closest point will be [1,-1].

 */



#define ll long long int


struct Point {
	int x;
	int y;
	ll dist;
};

class Heap{

	vector<Point> minHeap;
	int heapSize;

	int leftChild(int i) {
		int l = 2*i+1;
		return l;
	}

	int rightChild(int i) {
		int r = 2*i+2;
		return r;
	}

	int parent(int i) {
		int p = (i-1)/2;
		return p;
	}

	void percolateDown(int i) {
		int left = leftChild(i);
		int right = rightChild(i);

		int smallest = i;

		if(left < heapSize && minHeap[left].dist < minHeap[smallest].dist) {
			smallest = left;
		}

		if(right < heapSize && minHeap[right].dist < minHeap[smallest].dist) {
			smallest = right;
		}

		if(smallest != i) {
			swap(minHeap[i],minHeap[smallest]);
			percolateDown(smallest);
		}
	}

	void constructMinHeap() {
		for(int i = heapSize-1;i>=0;i--) {
			percolateDown(i);
		}
	}

	void deleteRoot() {
		swap(minHeap[0],minHeap[heapSize-1]);
		heapSize--;
		percolateDown(0);
	}

public:
	Heap(vector<vector<int> > &A) {
		heapSize = A.size();
		for(int i = 0;i<A.size();i++) {
			Point p;
			p.x = A[i][0];
			p.y = A[i][1];
			ll dist = sqrt((p.x * p.x) + (p.y * p.y));
			p.dist = dist;
			
			minHeap.push_back(p);
		}
		
		

		constructMinHeap();
		
		
	}

	vector<vector<int> > findAns(int k) {
		vector<vector<int> > res;
        vector<int> tmp;
		for(int i = 0;i<k;i++) {
			tmp.clear();
			tmp.push_back(minHeap[0].x);
			tmp.push_back(minHeap[0].y);
			//cout<<minHeap[0].x<<' '<<minHeap[0].y<<' '<<minHeap[0].dist<<endl;
			res.push_back(tmp);
			deleteRoot(); 

		}

		return res;
	}
};

bool myComparator(vector<int> p1, vector<int> p2) {
	ll d1 = ((p1[0]*p1[0]) + (p1[1] * p1[1]));
	ll d2 = ((p2[0]*p2[0]) + (p2[1] * p2[1])) ;

	return d1<d2;
}

vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {

	vector<vector<int> > res;
	/*
	if(A.size() < B) {
		return res;
	}

	Heap hp = Heap(A);

	res = hp.findAns(B);

	return res;
	*/

	sort(A.begin(),A.end(),myComparator);

	for(int i= 0;i<B;i++) {
		res.push_back(A[i]);
	}

	return res;
}
