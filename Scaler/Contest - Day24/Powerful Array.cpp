#define ll long long int

ll findGCD(ll a, ll b) {
	ll minELe = min(a,b);
	ll maxEle = max(a,b);
	while(minELe>0) {
		ll tmp = maxEle%minELe;
		maxEle = minELe;
		maxEle = tmp;
	}
	return maxEle;
}

int Solution::solve(vector<int> &A, vector<int> &B) {

	//sort(A.begin(),A.end());
	//sort(B.begin(),B.end());

	ll gcdA = A[0];
	ll gcdB = B[0];
	for(int i = 0;i<A.size();i++) {
			gcdA = findGCD(gcdA,A[i]);
			gcdB = findGCD(gcdB,B[i]);	
		}
	if(gcdA>=gcdB) {
		return 1;
	}
	return 0;

}
