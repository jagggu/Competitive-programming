/*
Smallest Good Base
Given an integer A, we call k >= 2 a good base of A, if all digits of A base k are 1. Now given a string representing A, you should return the smallest good base of A in string format.


Input Format

The only argument given is the string representing A.
Output Format

Return the smallest good base of A in string format.
Constraints

3 <= A <= 10^18
For Example

Input 1:
    A = "13"
Output 1:
    "3"     (13 in base 3 is 111)

Input 2:
    A = "4681"
Output 2:
    "8"     (4681 in base 8 is 11111).


*/



#define ll long long int

ll findSum(ll base, int bits, ll num) {
	ll sum = 1;
	ll prod = 1;

	//Handling the overflows here

	for(int i = 1;i<bits; i++) {
		prod = prod * base;
		sum += prod;

		if(sum > num) {
			return sum;
		} 
	}

	return sum;
}

string Solution::solve(string A) {

	ll num = stoll(A);

	for(int i = 64; i>0;i--) {
		ll start = 2;
		ll end = num;

		while(start <= end) {
			ll mid = start + (end-start)/2;

			ll sum = findSum(mid,i,num);

			if(sum == num) {
				return to_string(mid);
			} else if(sum < num) {
				start =  mid + 1;
			} else {
				end = mid - 1;
			}
		}
	}

	return "";
}
