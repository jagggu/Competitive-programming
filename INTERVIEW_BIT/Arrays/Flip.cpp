/*
You are given a binary string(i.e. with characters 0 and 1) S consisting of characters S1, S2, …, SN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters SL, SL+1, …, SR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised. If you don’t want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

Notes:

Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.
For example,

S = 010

Pair of [L, R] | Final string
_______________|_____________
[1 1]          | 110
[1 2]          | 100
[1 3]          | 101
[2 2]          | 000
[2 3]          | 001

We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].
Another example,

If S = 111

No operation can give us more than three 1s in final string. So, we return empty array [].

*/


vector<int> Solution::flip(string A) {

	int maxEndingHere = 0;
	int maxSoFar = 0;
	vector<int> res;

	bool isZero = false;

	for(auto ch : A) {
		if(ch == '0') {
			isZero = true;
			break;
		}
	}

	if(isZero == false) {
		return res;
	}

	int start = 0;
	int ansStart;
	int ansEnd;

	int n = A.size();

	for(int i= 0;i<n;i++) {

		int tmp = (A[i] == '1')?-1:1;

		maxEndingHere += tmp;

		if(maxEndingHere < 0) {
			maxEndingHere = 0;
			start = i+1;
		}

		if(maxEndingHere > maxSoFar) {
			ansStart = start;
			ansEnd = i;
			maxSoFar = maxEndingHere;
		}
	}

	res.push_back(ansStart + 1);
	res.push_back(ansEnd + 1);

	return res;
}
