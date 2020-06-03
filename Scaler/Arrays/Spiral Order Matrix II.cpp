/*
Spiral Order Matrix II
Problem Description
Given an integer A, generate a square matrix filled with elements from 1 to A2 in spiral order.


Problem Constraints
1 <= A <= 1000


Input Format
 First and only argument is integer A


Output Format
Return a 2-D matrix which consists of the elements in spiral order.


Example Input
Input 1:
1
  Input 2:        
2
     


Example Output
Output 1:
[ [1] ]
  Output 2:        
[ [1, 2], [4, 3] ]
     


Example Explanation
Explanation 1:
 
Only 1 is to be arranged.
  Explanation 2:        
1 --> 2
      |
      |
4<--- 3

*/



vector<vector<int> > Solution::generateMatrix(int A) {
   
   vector<vector<int> > arr(A, vector<int>(A));

   int rowStart = 0, colStart = 0;
   int rowEnd = A, colEnd = A;

   int num = 1;

   while(rowStart<rowEnd && colStart<colEnd) {

        for(int i = colStart;i<colEnd;i++) {
            arr[rowStart][i] = num++;
        }
        rowStart++;

        for(int i = rowStart;i<rowEnd;i++) {
            arr[i][colEnd-1] = num++;
        }

        colEnd--;

        if(rowStart < rowEnd) {
            for(int i = colEnd-1; i>=colStart;i--) {
                arr[rowEnd-1][i] = num++;
            }
            rowEnd--;
        }

        if(colStart < colEnd) {
            for(int i = rowEnd-1;i>=rowStart;i--) {
                arr[i][colStart] = num++;
            }

            colStart++;
        }

   }

   return arr;
}

