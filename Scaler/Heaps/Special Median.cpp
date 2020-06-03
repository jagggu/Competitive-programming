/*
Special Median
Problem Description
You are given an array A containing N numbers. This array is called special if it satisfies one of the following properties:
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[0], A[1], ...., A[i-1]]
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[i+1], A[i+2], ...., A[N-1]]
Median is the middle element in the sorted list of elements. If the number of elements are even then median will be (sum of both middle elements)/2. Return 1 if the array is special else return 0. NOTE: 
For A[0] consider only the median of elements [A[1], A[2], ..., A[N-1]] (as there are no elements to the left of it)
For A[N-1] consider only the median of elements [A[0], A[1], ...., A[N-2]]


Problem Constraints
1 <= N <= 1000000.
A[i] is in the range of a signed 32-bit integer.


Input Format
First and only argument is an integer array A.


Output Format
Return 1 if the given array is special else return 0.


Example Input
Input 1:
 A = [4, 6, 8, 4]
Input 2:
 A = [2, 7, 3, 1]


Example Output
Output 1:
 1
Output 2:
 0


Example Explanation
Explantion 1:
 Here, 6 is equal to the median of [8, 4].
Explanation 2:
 No element satisfies any condition.

*/



bool isNumber(double x) {
	return floor(x) == ceil(x);
}

int runningMedian(int x,double &median, priority_queue<int> &left, priority_queue<int, vector<int>, greater<int> > &right) {
	double val = x;

		if(isNumber(median)) {
			int tmp = median;
			//cout<<tmp<<' '<<x<<endl;
			if(tmp == x) {
				return 1;
			}
		}

		if(left.size() > right.size()) {
			if(val < median) {
				right.push(left.top());
				left.pop();
				left.push(x);
			} else {
				right.push(x);
			}

			median = (left.top() + right.top())/2.0;
		//	cout<<"Median: "<<median<<endl;
		} else if(left.size() == right.size()) {
			if(val < median) {
				left.push(val);
				median = left.top();
			} else {
				right.push(val);
				median = right.top();
			}
		} else {
			if(val > median) {
				left.push(right.top());
				right.pop();
				right.push(x);
			} else {
				left.push(x);
			}

			median = (left.top() + right.top())/2.0;
		}

		return 0;
}

int Solution::solve(vector<int> &A) {

	priority_queue<int> left;

	priority_queue<int,vector<int>, greater<int> > right;

	left.push(A[0]);

	int n = A.size();
	double median = A[0];
	for(int i = 1;i<n; i++) {
    
		int ans = runningMedian(A[i],median,left,right);

		if(ans == 1) {
			return 1;
		}
		
		

	}

	while(!left.empty()) {
		left.pop();
	}

	while(!right.empty()) {
		right.pop();
	}

	median = A[n-1];
	left.push(A[n-1]);
	for(int i = n-2;i>=0;i--) {
		int ans = runningMedian(A[i],median,left,right);

		if(ans == 1) {
			return 1;
		}
	}

	return 0;
}
