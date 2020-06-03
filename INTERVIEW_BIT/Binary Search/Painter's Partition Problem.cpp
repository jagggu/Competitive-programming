/*
Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003



Input Format

The first argument given is the integer A.
The second argument given is the integer B.
The third argument given is the integer array C.
Output Format

Return minimum time required to paint all boards under the constraints that any painter will only paint contiguous sections of board % 10000003.
Constraints

1 <=A <= 1000
1 <= B <= 10^6
1 <= C.size() <= 10^5
1 <= C[i] <= 10^6
For Example

Input 1:
    A = 2
    B = 5
    C = [1, 10]
Output 1:
    50
Explanation 1:
    Possibility 1:- same painter paints both blocks, time taken = 55units
    Possibility 2:- Painter 1 paints block 1, painter 2 paints block 2, time take = max(5, 50) = 50
    There are no other distinct ways to paint boards.
    ans = 50%10000003

Input 2:
    A = 10
    B = 1
    C = [1, 8, 11, 3]
Output 2:
    11

 */


#define ll long long int
 
bool isPossible(vector<int> &boards, int guess, int painters) {
	int currPainters = 1;
	int currBoard = 0;
	int n = boards.size();

	for(int i = 0;i<n;i++) {
		if(boards[i] > guess) {
			return false;
		}
		currBoard+=boards[i];

		if(currBoard > guess) {
			currBoard = boards[i];
			currPainters++;
			if(currPainters>painters) {
				return false;
			}
		}
	}

	return true;
}

int Solution::paint(int A, int B, vector<int> &C) {

	ll sum = 0;
	for(int ele : C) {
		sum+=ele;
	}

	ll start = 0;
	ll end = sum;
	ll ans;
	while(start <= end) {
		ll mid = start + (end-start)/2;

		if(isPossible(C,mid,A)) {
			ans = mid;
			end = mid-1;
		} else {
			start = mid+1;
		}
	}

	ans = (ans%10000003 * B%10000003) % 10000003;
	return ans;

}
