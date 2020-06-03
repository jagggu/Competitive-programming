/*
Reverse Link List II
Problem Description
Reverse a linked list A from position B to C.  NOTE: Do it in-place and in one-pass.  


Problem Constraints
1 <= |A| <= 106  1 <= B <= C <= |A|  


Input Format
The first argument contains a pointer to the head of the given linked list, A. The second arugment contains an integer, B.  The third argument contains an integer C.  


Output Format
Return a pointer to the head of the modified linked list.


Example Input
Input 1:
A = [1, 2, 3, 4, 5]
B = 2
C = 4
Input 2:
A = [1, 2, 3, 4, 5]
B = 1
C = 5


Example Output
Output 1:
[1, 4, 3, 2, 5]
Output 2:
[5, 4, 3, 2, 1]


Example Explanation
In the first example, we want to reverse the highlighted part of the given linked list : [1, [2, 3, 4], 5]. Thus, the output is [1, 4, 3, 2, 5].  In the second example, we want to reverse the highlighted part of the given linked list : [[1, 2, 3, 4, 5]]. Thus, the output is [5, 4, 3, 2, 1].  



*/





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
	
ListNode* reverseLL(ListNode *head) {
	ListNode *curr = head;
	ListNode *prev = NULL;
	ListNode *next;

	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {

	ListNode *start, *end;
	ListNode *prevStart, *nextEnd;

	ListNode *curr = A;
	int cnt = 0;
	while(curr != NULL && cnt < B-2) {
		curr = curr->next;
		cnt++;
	}

	if(B-2 < 0) {
		prevStart = A;
		start = A;
	} else {
		prevStart = curr;
		start = curr->next;
	}
	cnt = 0;
	curr = A;

	while(curr != NULL && cnt < C-1) {
		cnt++;
		curr = curr->next;
	}
	end = curr;
	nextEnd = curr->next;
	end->next = NULL;
	ListNode *reverseHead = reverseLL(start);

	if(prevStart != A) {
		prevStart->next = reverseHead;
	}
	if(nextEnd != NULL) {
		start->next = nextEnd;
	}
	return A;

}


