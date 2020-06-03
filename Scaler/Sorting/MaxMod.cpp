
//THis problem reduces to 2nd largest ele in the array

int Solution::solve(vector<int> &A) {
    /*
    int n = A.size();
    auto ip = unique(A.begin(),A.begin()+n);
    A.resize(std::distance(A.begin(),ip));
    
    if(A.size() < 2) {
        return 0;
    }
    sort(A.begin(),A.end());
    return A[A.size() - 2];
    */

    int max1 = INT_MIN, max2 = INT_MIN;

    for(int i = 0;i<A.size();i++) {
        if(A[i]>max1) {
            max2 = max1;
            max1 = A[i];
        } else if(A[i]>max2 && A[i] != max1) {
           // cout<<"checkPoint"<<endl;
            max2 = A[i];
        }
    }

    return max2 == INT_MIN?0:max2;
}
