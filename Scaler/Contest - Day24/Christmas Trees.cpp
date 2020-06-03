#define ll long long int

int findUsefulEle(vector<int> &A, vector<int> &B, int start, int end, int index, bool isSmall) {
	
	int height = A[index];
	int ans = -1;
	for(int i = start; i<end; i++) {
		if(isSmall) { 
			if(A[i]<height) {
				if(ans == -1) {
					ans = i;
				} else {
					if(B[ans] > B[i]) {
						ans = i;
					}
				}
			} 
			
		} else {
			if(A[i] > height) {
				if(ans == -1) {
					ans = i;
				} else {
					if(B[ans]>B[i]) {
						ans = i;
					}
				}
			}
		}
	}

	return ans;
}

int Solution::solve(vector<int> &A, vector<int> &B) {
	/*
	--> Brute Force

	int ans = INT_MAX;
	int n = A.size();
	if(n<=3) {
		return -1;
	}
	for(int i = 0;i<n;i++) {
		int a = A[i];
		for(int j = i+1;j<n;j++) {
			if(A[j]<=a) {
				continue;
			}
			int b = A[j];
			for(int k = j+1;k<n;k++) {
				if(A[k]<=b) {
					continue;
				}
				int tmpAns = B[i]+B[j] + B[k];
				ans = min(ans,tmpAns);
			}
		}
	}

	return ans;
	*/

	ll ans = INT_MAX;
	int n = A.size();
	if(n<3) {
		return -1;
	}
    
    for(int i = 0; i<n;i++) {
    	int first = findUsefulEle(A,B,0,i,i,true);
    	int second = findUsefulEle(A,B,i+1,n,i,false);

    	if(first != -1 && second != -1) {
    		ll tmpAns = B[i] + B[first] + B[second];
    		ans = min(ans,tmpAns);
    	}

    }

    return ans;
}
