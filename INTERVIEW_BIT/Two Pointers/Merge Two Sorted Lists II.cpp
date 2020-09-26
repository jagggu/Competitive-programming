/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.
TIP: C users, please malloc the result into a new array and return the result. 
If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]

*/


void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int lastPos = A.size() + B.size() - 1;
    int i = A.size()-1;
    int j = B.size()-1;
    A.resize(A.size() + B.size());

    

    while(i>=0 && j >= 0) {
        
        //cout<<"LastPos: "<<lastPos<<endl;
      if(A[i]>B[j]) {
          //cout<<"A: "<<i<<' '<<lastPos<<endl;
        A[lastPos--] = A[i--];
      } else {
          //cout<<"B: "<<j<<' '<<lastPos<<endl;
        A[lastPos--] = B[j--];
      }
    }
    
    //cout<<i<<' '<<j<<' '<<lastPos<<endl;

    while(j>=0) {
      A[lastPos--] = B[j--];
    }

    while( i >= 0) {
      A[lastPos--] = A[i--];
    }

}
