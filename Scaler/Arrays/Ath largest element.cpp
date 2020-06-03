vector<int> Solution::solve(int A, vector<int> &B) {

	priority_queue<int,vector<int>, greater<int> > minPQ;

	int n = B.size();
	vector<int> res;

	if(A>=n) {
		for(int i = 0;i<n;i++) {
			res.push_back(-1);
		}

		return res;
	}

	for(int i = 0;i<A;i++) {
		minPQ.push(B[i]);
		res.push_back(-1);
	}

	res.pop_back();
    res.push_back(minPQ.top());
	//minPQ.push(B[A-1]);

	for(int i = A;i<n;i++) {
		int ele = minPQ.top();
		
		//res.push_back(ele);
		
		if(B[i]>ele) {
			minPQ.pop();
			minPQ.push(B[i]);
			res.push_back(minPQ.top());
		} else {
			res.push_back(minPQ.top());
		}
	}

	return res;

}
