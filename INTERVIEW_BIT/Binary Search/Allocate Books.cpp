/*
Allocate Books
Problem Description
Given an array of integers A of size N and an integer B. College library has N books,the ith book has A[i] number of pages. You have to allocate books to B number of students so that maximum number of pages alloted to a student is minimum.
A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
Calculate and return that minimum possible number. 
 NOTE: Return -1 if a valid assignment is not possible. 


Problem Constraints
1 <= N <= 105
1 <= A[i], B <= 105


Input Format
The first argument given is the integer array A.
The second argument given is the integer B.


Output Format
Return that minimum possible number


Example Input
A = [12, 34, 67, 90]
B = 2


Example Output
113


Example Explanation
There are 2 number of students. Books can be distributed in following fashion : 
        1) [12] and [34, 67, 90]
        Max number of pages is allocated to student 2 with 34 + 67 + 90 = 191 pages
        2) [12, 34] and [67, 90]
        Max number of pages is allocated to student 2 with 67 + 90 = 157 pages 
        3) [12, 34, 67] and [90]
        Max number of pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
        Of the 3 cases, Option 3 has the minimum pages = 113.

  */


#define ll long long int

bool isPossible(vector<int> &books, int students, int pages) {
	int currPerson = 1;
	int currPages = 0;
	for(int i = 0;i<A.size();i++) {
		if(books[i] > pages) {
			return false;
		}
		currPages+=books[i];
		if(currPages>pages) {
			currPages = books[i];
			currPerson++;
		}
	}

	return currPerson>=B;
}

int Solution::books(vector<int> &A, int B) {

	ll sum = 0;
	for(int ele : A) {
		sum+=ele;
	}
	ll start = 0;
	ll end = sum;
	if(B > A.size()) {
		return -1;
	}
	int ans = -1;
	while(start <= end) {
		ll mid = start + (end-start)/2;

		if(isPossible(A,B,mid)) {
			ans = mid;
			end = mid-1;
		} else {
			start = mid +1;
		}
	}

	return ans;

}
