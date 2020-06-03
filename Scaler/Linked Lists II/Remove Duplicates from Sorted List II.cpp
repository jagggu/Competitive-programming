/*
Remove Duplicates from Sorted List II
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. For example, Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {

	ListNode *resHead = new ListNode(0);
	ListNode *resTail  = resHead;

	ListNode *curr = A;

	while(curr != NULL) {
		//ListNode *next = curr->next;
		bool isDuplicate = false;
		while(curr->next != NULL && curr->val == curr->next->val) {
			ListNode *tmp = curr;
			curr = curr->next;
			isDuplicate = true;
			delete tmp;
		}
		if(!isDuplicate) {
			resTail->next = curr;
			resTail = resTail->next;
			curr = curr->next;
		} else {
			ListNode *tmp = curr;
			curr = curr->next;
			delete tmp;
		}	

		/*
		if(curr->val == curr->next->val) {
			ListNode *tmp = curr;
			delete tmp;
		} else {
			resTail->next = curr;
			resTail = resTail->next;
		}
		curr = next;
		*/
	}
	resTail->next = NULL;
	return resHead->next;

}
