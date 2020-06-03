/*
Alternate positive and negative elements
Problem Description
Given an array of integers A, arrange them in an alternate fashion such that every non-negative number is followed by negative and vice-versa, starting from a negative number, maintaining the order of appearance. The number of non-negative and negative numbers need not be equal. If there are more non-negative numbers they appear at the end of the array. If there are more negative numbers, they too appear at the end of the array. Note: Try solving with O(1) extra space.  


Problem Constraints
1 <= length of the array <= 7000
-10^9 <= A[i] <= 109


Input Format
The first argument given is the integer array A.


Output Format
Return the modified array.


Example Input
Input 1:
A = [-1, -2, -3, 4, 5]
Input 2:
A = [5, -17, -100, -11]
 


Example Output
Output 1:
[-1, 4, -2, 5, -3]
Output 2:
[-17, 5, -100, -11]
 


Example Explanation
Explanation 1:
A = [-1, -2, -3, 4, 5]
Move 4 in between -1 and -2, A => [-1, 4, -2, -3, 5]
Move 5 in between -2 and -3, A => [-1, 4, -2, 5, -3]
 
 */



void rightRotateArray(vector<int> &A, int start, int end) {
	int tmp = A[end];
	for(int i = end;i>start;i--) {
		A[i] = A[i-1];
	}
	A[start] = tmp;
}

vector<int> Solution::solve(vector<int> &A) {

	int wrongIndex = -1;
	int n = A.size();
   // cout<<"Len: "<<n<<endl;
	for(int i = 0; i<n; i++) {
	    //cout<<"i: "<<i<<endl;
	   // cout<<"WrongIndex: "<<wrongIndex<<endl;
		if(wrongIndex>=0) {
		    //cout<<"Reached";
		    //cout<<A[wrongIndex]<<' '<<A[i]<<endl;
			if((A[wrongIndex]>=0 && A[i]<0) || (A[wrongIndex]<0 && A[i]>=0)) {
			   // cout<<"checkPoint1"<<endl;
				rightRotateArray(A,wrongIndex,i);
				
				if((i-wrongIndex)>=2) {
				wrongIndex+=2;
			} else {
				wrongIndex = -1;
			}
			}
			

		}

		if(wrongIndex == -1) {
			if((i&1 && A[i]<0) || (!(i&1) && A[i]>=0)) {
				wrongIndex = i;
			}
		}
	}
	return A;
}
