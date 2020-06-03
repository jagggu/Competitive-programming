/*
Reorder List
Problem Description
Given a singly linked list A
 A: A0 → A1 → … → An-1 → An 
reorder it to:
 A0 → An → A1 → An-1 → A2 → An-2 → … 
You must do this in-place without altering the nodes' values.  


Problem Constraints
1 <= |A| <= 106


Input Format
The first and the only argument of input contains a pointer to the head of the linked list A.


Output Format
Return a pointer to the head of the modified linked list.


Example Input
Input 1:
 A = [1, 2, 3, 4, 5] 
Input 2:
 A = [1, 2, 3, 4] 


Example Output
Output 1:
 [1, 5, 2, 4, 3] 
Output 2:
 [1, 4, 2, 3] 


Example Explanation
In the first example, the array will be arranged to [A0, An, A1, An-1, A2].  In the second example, the array will be arranged to [A0, An, A1, An-1].  


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
	ListNode *prev = NULL;
	ListNode *curr = head;
	ListNode *next;
	while(curr != NULL) {
	   // cout<<"checkPoint1";
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

ListNode *mergeLL(ListNode *h1, ListNode*h2) {
	//ListNode *res = h1;
	ListNode *ans = h1;
	ListNode tmp;
	ListNode tail = &tmp;
	while(h1 != NULL && h2 != NULL) {
		tail->next = h1;
		tail = tail->next;
		tail->next = h2;
		tail = tail->next;
		h1 = h1->next;
		h2 = h2->next;
	}
	return tmp->next;
}
    
    void printLL(ListNode *head) {
        ListNode *tmp = head;
        while(tmp != NULL) {
            cout<<tmp->val<<' ';
            tmp = tmp->next;
        }
    }

ListNode* Solution::reorderList(ListNode* A) {

	ListNode *slowPtr = A;
	ListNode *fastPtr = A;

	while(fastPtr != NULL && fastPtr->next != NULL) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	ListNode *mid = slowPtr;
	ListNode *head1 = A;
	ListNode *head2 = mid->next;
	mid->next = NULL;
	ListNode *reverseHead = reverseLL(head2);
    //printLL(head1);
   // cout<<endl;
	//return mergeLL(head1,reverseHead);
	return A;
}
