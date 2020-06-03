#define ll long long int

int Solution::solve(int A, int B, int C) {
	int ans = INT_MIN;
	int start = B;
	int end = C;
	/*
	while(start <= end) {
		int mid = start + (end-start)/2;
		int tmpAns = A^mid;
		if(tmpAns>=ans) {
			ans = tmpAns;
			start++;
		} else {
			end--;
		}
	}
	return ans;
	*/
	int x = 0;
	/*
	for(int i = log2(C);i>=0; i--) {
		if(A & (1 << i)) {
			if(x < B) {
				x ^= (1<<i);
			}
		} else {
			if(x^(1<<i) <= C) {
				x^=(1<<i);
			}
		}
	}*/
	for (int i = log2(C); i >= 0; --i) { 
	  //  cout<<i<<endl;
		if (A & (1 << i)) { // Set bit 
		   
			if ((x + (1<<i)-1) < B) 
			{
				x ^= (1 << i); 
			    // cout<<"x Val: "<<x<<endl;
			    
			}
		} 
		else { // Unset bit 
			if ((x ^ (1 << i)) <= C) 
				x ^= (1 << i); 
		} 
	}
	//cout<<x<<endl;
	return A^x;
}
