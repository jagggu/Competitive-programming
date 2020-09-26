/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

 NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer.
For example, for this problem, following are some good questions to ask :
Q : Can the input have 0’s before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
A : For the purpose of this question, YES
Q : Can the output have 0’s before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.

*/


vector<int> Solution::plusOne(vector<int> &A) {

	vector<int> res;

	int validIndex;

	int n = A.size();
	for(int i = 0;i<n;i++) {
		if(A[i] == 0) {
			if(i == n-1) {
				res.push_back(1);
				return res;
			}
			continue;
		}

		validIndex = i;
		break;
	}

	int i = n-1;

	while(i >= validIndex) {
		if(A[i] != 9) {
			break;
		}

		i--;
	}
	if(i < validIndex) {
		res.push_back(1);
		for(int j = validIndex;j<n;j++) {
			res.push_back(0);
		}

		return res;
	}

	A[i]++;
	for(int k = validIndex;k<=i;k++) {
		res.push_back(A[k]);
	}

	for(int k = i+1;k<n;k++) {
		res.push_back(0);
	}

	return res;

}
