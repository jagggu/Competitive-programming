void rightRotateArray(vector<int> &A, int start, int end) {
	int tmp = A[end];
	for(int i = end;i>start;i--) {
		A[i] = A[i-1];
	}
	A[start] = tmp;
}

vector<int> Solution::solve(vector<int> &A) {

	int wrongIndex = -1;
	int n = A.size();
   // cout<<"Len: "<<n<<endl;
	for(int i = 0; i<n; i++) {
	    //cout<<"i: "<<i<<endl;
	   // cout<<"WrongIndex: "<<wrongIndex<<endl;
		if(wrongIndex>=0) {
		    //cout<<"Reached";
		    //cout<<A[wrongIndex]<<' '<<A[i]<<endl;
			if((A[wrongIndex]>=0 && A[i]<0) || (A[wrongIndex]<0 && A[i]>=0)) {
			   // cout<<"checkPoint1"<<endl;
				rightRotateArray(A,wrongIndex,i);
				
				if((i-wrongIndex)>=2) {
				wrongIndex+=2;
			} else {
				wrongIndex = -1;
			}
			}
			

		}

		if(wrongIndex == -1) {
			if((i&1 && A[i]<0) || (!(i&1) && A[i]>=0)) {
				wrongIndex = i;
			}
		}
	}
	return A;
}
