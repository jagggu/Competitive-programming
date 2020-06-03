#define ll long long int

ll isPossible(vector<int> &B, int mid, int A) {
	ll sum = 0;
	for(int i = 0;i<mid;i++) {
		sum = sum + (B[i] + (i+1)*mid);
		if(sum>A) {
			return -1;
		}
	}
	return sum;
}

vector<int> Solution::solve(int A, vector<int> &B) {
	int start = 0;
	int end = B.size();
	int students = 0, amount = 0;
	sort(B.begin(),B.end());
	while(start <= end) {
		int mid = start + (end-start)/2;
		
		ll tmpAmount = -1;
		tmpAmount = isPossible(B,mid,A);
		if(tmpAmount != -1) {
			students = mid;
			amount = tmpAmount;
			start = mid+1;
		} else {
			end = mid-1;
		}

	}
	vector<int> res;
	res.push_back(students);
	res.push_back(amount);
	return res;
}