
int Solution::maximumGap(const vector<int> &A) {
    
    int n = A.size();

    int minEle = *min_element(A.begin(),A.end());
    int maxEle = *max_element(A.begin(),A.end());

    int gap = (maxEle-minEle)/(n-1) + 1;

    vector<int> minArr(n-1,INT_MAX);
    vector<int> maxArr(n-1,INT_MIN);

    for(int i = 0;i<n;i++) {
        int index = (A[i]/gap) - 1;
        minArr[index] = min(minArr[index],A[i]);
        maxArr[index] = max(maxArr[index],A[i]);
    }

    int finalAns = 0;
    for(int i = 1;i<(n-1);i++) {
        int max1 = maxArr[i-1];
        int min1 = minArr[i];

        finalAns = max(finalAns,min1-max1);
    }

    return finalAns;
}
