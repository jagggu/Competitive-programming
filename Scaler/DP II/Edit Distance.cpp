vector<vector<int> > dist;

int minDistanceHelper(string A, string B, int i, int j) {
	if(i == 0 || j == 0) {
		return max(i,j);
	}
	
//	cout<<i<<' '<<j<<endl;

	if(dist[i][j] != -1) {
	    //cout<<"checkPoint"<<endl;
		return dist[i][j];
	}

	if(A[i-1] == B[j-1]) {
		return dist[i][j] = minDistanceHelper(A,B,i-1,j-1);
	} else {
		 dist[i][j] =  (min(minDistanceHelper(A,B,i-1,j-1),min(minDistanceHelper(A,B,i,j-1), minDistanceHelper(A,B,i-1,j)))) + 1;
		
	//	dist[i][j] += 1;
		return dist[i][j];
	}
}


int Solution::minDistance(string A, string B) {

	int ALen = A.size();
	int BLen = B.size();

	dist.clear();
    vector<int> tmp;
	for(int i = 0;i<=ALen;i++) {
	    tmp.clear();
		for(int j = 0;j<=BLen;j++) {
		  tmp.push_back(-1);
		}
		dist.push_back(tmp);
	}

	int ans = minDistanceHelper(A,B,ALen,BLen);

	return ans;
}