/*

Find the closest pair from two sorted arrays
Given two sorted arrays of distinct integers, A and B, and an integer C, find and return the pair whose sum is closest to C and the pair has one element from each array. More formally, find A[i] and B[j] such that abs((A[i] + B[j]) - C) has minimum value. If there are multiple solutions find the one with minimum i and even if there are multiple values of j for the same i then return the one with minimum j. Note: Return an array with two elements {A[i], B[j]}. 
Input Format
The first argument given is the integer array A.
The second argument given is the integer array B.
The third argument given is integer C.
Output Format
Return the pair which has sum closest to C.
Constraints
1 <= length of both the arrays <= 100000
1 <= A[i], B[i] <= 10^9 
1 <= C <= 10^9
For Example
Input 1:
    A = [1, 2, 3, 4, 5]
    B = [2, 4, 6, 8]
    C = 9
Output 1:
    [1, 8]

Input 2:
    A = [5, 10, 20]
    B = [1, 2, 30]
    C = 13
Output 2:
    [10, 2]

*/



#define ll long long int

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {

	int Alen = A.size();
	int Blen = B.size();

	int start = 0;
	int end = Blen-1;

	ll diff = INT_MAX;
	int resL,resR;

	while(start<Alen && end>=0) {
		ll tmp = A[start] + B[end] - C;
            //cout<<diff<<endl;
            //cout<<start<<' '<<end<<endl;
		if(abs(tmp) < diff) {
			diff = abs(tmp);
			resL = start;
			resR = end;
		//	cout<<resL<<' '<<resR<<endl;
		} else if(abs(tmp) == diff) {
          //  cout<<"Reached";
			//Finding min resL and resR
			if(start < resL) {
				resL = start; 
				resR = end;
				diff = abs(tmp);
			} else if(start == resL) {
				if(end < resR) {
					resR = end;
					resL = start;
					diff = abs(tmp);
				}
			}
		}

		tmp = A[start] + B[end];
	//	cout<<start<<' '<<end<<' '<<A[start]+A[end]<<' '<<tmp<<endl;
		if(tmp > C) {
			end--;
		} else {
			start++;
		}
	}

	vector<int> res;
	res.push_back(A[resL]);
	res.push_back(B[resR]);
	return res;
}
