/*
Length of longest palindromic list
Given a linked list of integers. Find and return the length of the longest palindrome list that exists in that linked list. Note: A palindrome list is a list that reads the same backward and forward. Expected memory complexity : O(1) 
Input Format
The only argument given is head pointer of the linked list.
Output Format
Return the length of the longest palindrome list.
Constraints
1 <= length of the linked list <= 2000
1 <= Node value <= 100 
For Example
Input 1:
    2 -> 3 -> 3 -> 3
Output 1:
   3 

Input 2:
    A = 2 -> 1 -> 2 -> 1 ->  2 -> 2 -> 1 -> 3 -> 2 -> 2
Output 2:
    5

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
	
	int maxPalindromeLen(ListNode *a, ListNode *b) {
		int cnt = 0;
		while(a != NULL && b != NULL) {
			if(a->val == b->val) {
				cnt++;
			} else {
				break;
			}
			a = a->next;
			b = b->next;
		}
		return cnt;
	}

int Solution::solve(ListNode* A) {

	ListNode *curr = A;
	ListNode *next;
	ListNode *prev = NULL;
	int res = 0;
	while(curr) {
		next = curr->next;
		curr->next = prev;

		res = max(res,2*maxPalindromeLen(prev,next)+1);

		res = max(res,2*maxPalindromeLen(curr,next));

		prev = curr;
		curr= next;
	}

	return res;
}
