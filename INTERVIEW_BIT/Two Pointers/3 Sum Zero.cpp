/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

*/


#define ll long long int

vector<vector<int> > Solution::threeSum(vector<int> &A) {

    vector<vector<int> > res;

    int n = A.size();
    sort(A.begin(),A.end());

    for(int i = 0;i<n-2;i++) {
        if(i != 0 && A[i] == A[i-1]){
            continue;
        }
        
        int start = i+1;
        int end = n-1;
        
        ll target = -1 * A[i];

        while(start < end) {
            ll a = A[start];
            ll b = A[end];
            ll c = A[i];
            //ll sum =  a + b + c;
            ll sum = (long long)((long long)(A[i]) + (long long)(A[start]) + (long long)(A[end]));
            //cout<<target<<' '<<A[start]<<' '<<A[end]<<' '<<sum<<endl;
            if(sum == 0) {
                vector<int> tmp(3);
                tmp[0] = A[i];
                tmp[1] = A[start];
                tmp[2] = A[end];
                res.push_back(tmp);

                while(start < end && A[start] == A[start+1]){
                    start++;
                }

                while(start < end && A[end] == A[end-1]) {
                    end--;
                }

                start++;
                end--;
            } else if(sum > 0) {
                end--;
            } else {
                start++;
            }
        }
    }

    return res;

}
