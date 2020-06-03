/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
ListNode* reverseLL(ListNode *head, int k) {

	ListNode *curr = head;
	ListNode *prev = NULL;
	ListNode *next;
	int cnt = 0;
	while(cnt < k-1) {
		curr = curr->next;
		cnt++;
	}
	curr->next = NULL;
	curr = head;
	while(curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

ListNode* swapPairsHelper(ListNode *A, int k) {
	if(A == NULL) {
		return A;
	}
	int cnt = 0;
	ListNode *curr = A;
	while(curr != NULL && cnt<k) {
		curr = curr->next;
		cnt++;
	}
	if(cnt == k) {
		ListNode *reverseHead = reverseLL(A,k);
		A->next = swapPairsHelper(curr,k);
		return reverseHead;
	} else {
		return A;
	}
}

ListNode* Solution::swapPairs(ListNode* A) {

	return swapPairsHelper(A,2);
}
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* swapNodes(ListNode *a1, ListNode *b1) {
	a1->next = b1->next;
	b1->next = a1;
	return b1;
}

ListNode* Solution::swapPairs(ListNode* A) {

	ListNode *ans = new ListNode(0);
    ans->next = A;
	ListNode *curr = ans;
	while(curr->next != NULL && curr->next->next != NULL) {
		//ListNode *tmp = curr->next->next;
		curr->next = swapNodes(curr->next, curr->next->next);
		curr = curr->next->next;
	}
	return ans->next;

}