/*
int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.size();
	int index = 0;
	int count = 0;
	int i = 0;
	while(i<n-1) {

		if(count>=2) {
			if(A[i] != A[i+1]) {
				count = 0;
			}
			i++;
			continue;
		}

		if(A[i] == A[i+1]) {
			count++;
		} else {
			count = 0;
			

		
		}
		A[index++] = A[i++];
		}
		if(count < 2) {
			A[index++] = A[n-1];
		}
		//cout<<index<<endl;
		return index;
	}
	


*/


int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	int n = A.size();
	int index = 0;
	int count = 0;
	int i = 0;
	while(i<n-1) {

		if(count>=2) {
			if(A[i] != A[i+1]) {
				count = 0;
			}
			i++;
			continue;
		}

		if(A[i] == A[i+1]) {
			count++;
		} else {
			count = 0;
			

		
		}
		A[index++] = A[i++];
		}
		if(count < 2) {
			A[index++] = A[n-1];
		}
		//cout<<index<<endl;
		return index;
	}
	

