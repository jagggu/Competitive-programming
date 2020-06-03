/*
Colorful Number
Problem Description
For Given Number A find if its COLORFUL number or not. If number A is a COLORFUL number return 1 else return 0. 
 What is a COLORFUL Number:
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different.
 


Problem Constraints
1 <= A <= 1010


Input Format
Single Argument which denotes integer A.


Output Format
Return 1 if integer A is COLORFUL else return 0.


Example Input
A = 23


Example Output
1


Example Explanation
Possible Sub-sequences: [2, 3, 23] where
2 -> 2
3 -> 3
23 -> 6  (product of digits)
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

*/


#define ll long long int

int Solution::colorful(int A) {

	unordered_set<string> s;

   string str = to_string(A);
  
   for(int i = 0; i<str.size(); i++) {
        string tmp = "";
        tmp+=str[i];
   		if(s.find(tmp) != s.end()) {
   			return 0;
   		}
   		s.insert(tmp);
   		ll mul = str[i] - '0';
   	for(int j = i+1;j<str.size(); j++) {
   		
   		int second = str[j] - '0';

   		 mul = mul * second;

   		string tmp1 = to_string(mul);
   		if(s.find(tmp1) != s.end()) {
   			return 0;
   		}
   		s.insert(tmp1);
   	}
   }
   return 1;
}
