
#define ll long long int

ll MOD = 1000000007;

vector<ll> segTreeValues;
vector<ll> segTreeIndx;

void buildTreeVal(int node, int start, int end, int actualSize, vector<int> &A) {
	if(start == end) {
		if(start>=actualSize) {
			segTreeValues[node] = 0;
		} else {
			segTreeValues[node] = A[start];
		}

		return;
	}

	int mid = start + (end-start)/2;

	buildTreeVal(2*node,start,mid,actualSize,A);
	buildTreeVal(2*node+1,mid+1,end,actualSize,A);

	segTreeValues[node] = (segTreeValues[2*node]%MOD + segTreeValues[2*node+1]%MOD) %MOD;

}

void buildTreeIndx(int node, int start, int end, int actualSize) {
	if(start == end) {
		if(start>=actualSize) {
			segTreeIndx[node] = 0;
		} else {
			segTreeIndx[node] = 1;
		}

		return;
	}

	int mid = start + (end-start)/2;

	buildTreeIndx(2*node,start,mid,actualSize);
	buildTreeIndx(2*node+1,mid+1,end,actualSize);

	segTreeIndx[node] = segTreeIndx[2*node] + segTreeIndx[2*node+1];
}

void updateVal(int node, int start, int end, int indx, int val) {
	if(start == end) {
		segTreeValues[node] = val;
		return;
	}

	int mid = start + (end-start)/2;

	if(start<=indx && indx<=mid) {
		updateVal(2*node,start,mid,indx,val);
	} else {
		updateVal(2*node+1,mid+1,end,indx,val);
	}

	segTreeValues[node] = (segTreeValues[2*node]%MOD + segTreeValues[2*node+1]%MOD) % MOD;
}

void updateIndx(int node, int start, int end, int indx, int val) {
	if(start == end) {
		segTreeIndx[node] = val;
		return;
	}

	int mid = start + (end-start)/2;

	if(start<=indx && indx<=mid) {
		updateIndx(2*node,start,mid,indx,val);
	} else {
		updateIndx(2*node+1,mid+1,end,indx,val);
	}

	segTreeIndx[node] = segTreeIndx[2*node] + segTreeIndx[2*node+1];
}

int queryIndx(int node, int start, int end, int k) {

	if(start == end) {
		return start;
	}

	int leftOnes = segTreeIndx[2*node];
	int mid = start + (end-start)/2;

	if(leftOnes>=k) {
		return queryIndx(2*node,start,mid,k);
	} else {
		return queryIndx(2*node+1,mid+1,end,k-leftOnes);
	}
}

int queryVal(int node, int start, int end, int l, int r) {
	if(r<start || end < l) {
		return 0;
	}

	if(l<=start && end<=r) {
		return segTreeValues[node];
	}

	int mid = start + (end-start)/2;

	ll left = queryVal(2*node,start,mid,l,r);
	ll right = queryVal(2*node+1,mid+1,end,l,r);

	ll ans = (left%MOD + right%MOD) % MOD;

	return ans%MOD;
}

int findIndxToRemove(unordered_map<int,bool> &track, int indx) {
	while(true) {
		if(track.find(indx) == track.end()) {
			return indx;
		}
		indx++;
	}
}

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {

	segTreeValues.clear();
	segTreeIndx.clear();

	int n = A.size();
	int actualSize = n;
	for(int i = 0;i<B.size();i++) {
		if(B[i][0] == 1) {
			n++;
		}
	}

	segTreeValues.resize(4*n);
	segTreeIndx.resize(4*n);

	buildTreeVal(1,0,n-1,actualSize,A);
	buildTreeIndx(1,0,n-1,actualSize);

	vector<int> res;
	unordered_map<int,bool> track;

	for(int i = 0;i<B.size();i++) {
		if(B[i][0] == 1) {
			updateVal(1,0,n-1,actualSize,B[i][1]);
			updateIndx(1,0,n-1,actualSize,1);
			actualSize++;
		} else if(B[i][0] == 2) {
			updateVal(1,0,n-1,B[i][1]-1,B[i][2]);
		} else if(B[i][0] == 3) {
			int index = findIndxToRemove(track,B[i][1]-1);
			
			track[index] = true;
			updateIndx(1,0,n-1,index,0);
			updateVal(1,0,n-1,index,0);
		} else {
			int l = queryIndx(1,0,n-1,B[i][1]);
			int r = queryIndx(1,0,n-1,B[i][2]);

			int ans = queryVal(1,0,n-1,l,r);
			res.push_back(ans);
		}
	}

	return res;
}
