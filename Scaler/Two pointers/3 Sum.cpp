/*
3 Sum
Problem Description
Given an array A of N integers, find three integers in A such that the sum is closest to a given number B. Return the sum of those three integers. Assume that there will only be one solution.  


Problem Constraints
-108 <= B <= 108
1 <= N <= 104
-108 <= A[i] <= 108


Input Format
First argument is an integer array A of size N. Second argument is an integer B denoting the sum you need to get close to.  


Output Format
Return a single integer denoting the sum of three integers which is closest to B.


Example Input
A = [-1,2,1,-4]
B = 1


Example Output
2


Example Explanation
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)

*/


#define ll long long int

int Solution::threeSumClosest(vector<int> &A, int B) {

    int n = A.size();
    ll ans = INT_MAX;
    ll target = B;
   // int minDist = INT_MAX;
    sort(A.begin(),A.end());
    for(int i = 0; i<n-2;i++) {
    //	int target = B-A[i];
    	int start = i+1;
    	int end = n-1;
    	while(start < end) {
    	    ll tmp = A[start] + A[end] + A[i];
    	    //cout<<abs(B-tmp)<<endl;
    	   // cout<<abs(B-ans)<<endl;
    		if(abs(B-tmp) < abs(B-ans)) {
    		   // cout<<"Reached";
    		    ans = tmp;
    		}
    		if(tmp > B) {
    			
    		//	ans = min(ans,abs(tmp-B));
    			end--;
    		} else  {
    			
    			//ans = min(ans,abs(tmp-B));
    			start++;
    		} 
    	}
    }
  //  cout<<ans<<endl;
    if(ans == INT_MAX) {
        return -1;
    }
    return ans;
}
