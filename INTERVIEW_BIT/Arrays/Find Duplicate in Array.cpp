/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1


*/



int repeatedNumberHelper(const vector<int> &A, int n) {

	int sq = sqrt(n);

	int blocks = (n/sq) + 1;

	vector<int> cnt(blocks,0);

	for(int ele : A) {

		cnt[(ele - 1)/sq]++;
	}

	int validBlock = blocks-1;

	for(int i = 0;i<(blocks-1); i++) {

		if(cnt[i] > sq) {
			validBlock = i;
			break;
		}
	}

	unordered_set<int> s;

	for(int ele : A) {

		int b = (ele - 1)/sq;
		if(b == validBlock) {
			if(s.find(ele) != s.end()) {
				return ele;
			}

			s.insert(ele);
		}
	}

	return -1;

}

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	return repeatedNumberHelper(A,A.size()-1);

}
