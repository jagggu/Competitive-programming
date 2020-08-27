/*
Candies in Box
Problem Description

There are 2 * N small boxes containing candies denoted by an integer array A of size 2 * N.

There are N-1 big boxes and each big box can accomodate exactly 2 small boxes.

So, we can use exactly 2 * (N-1) small boxes.

The cost of each big box is the absolute difference of candies in that box.

For example: A big box contain two small boxes with candies 4 and 6 then the cost of this big box will be | 4 - 6 | = 2.

You have to fill all the big boxes such that the total cost of big boxes are minimized.

Find and return the minimum total cost of big boxes.



Problem Constraints
1 <= N <= 50

1 <= A[i] <= 107



Input Format
First argument is an integer array A of size 2 * N.



Output Format
Return an integer denoting the minimum total cost of big boxes.



Example Input
A = [2, 4, 1, 10, 6, 15]


Example Output
3


Example Explanation
Since 2 * N = 6. So there are 2 big boxes, we can place 4 small boxes inside the 2 big boxes.
Inorder to minimize the cost, we will select boxes with candies (2, 1) and (4, 6). So the minimum cost will be 2 + 1 =3.


*/


int findDiff(vector<int> &arr) {
	int diff = 0;

	for(int i = 0;i<arr.size();i+=2) {
	  //  cout<<arr[i]<<' '<<arr[i+1]<<endl;
		diff += (abs(arr[i]-arr[i+1]));
	}

	return diff;
}


int Solution::solve(vector<int> &A) {

	int n = A.size();
	if(n<1) {
		return 0;
	}

	int size = n/2;

	int ans = INT_MAX;

	sort(A.begin(),A.end());

	vector<int> res;

	//We need to discard any 2 boxes at any given point of time
	for(int i = 0;i<n;i++) {
		
		for(int j = i+1;j<n;j++) {
            res.clear();
			for(int k = 0;k<n;k++) {
				if(k == i || k == j) {
					continue;
				}
				res.push_back(A[k]);
			}
			
			//cout<<res.size()<<endl;
			
			int t = findDiff(res);
		    //cout<<"Ans: "<<t<<endl;
		    ans = min(ans,t);
		}

		
		
	}

	return ans;
}
