/*
Flatten a linked list
Given a linked list where every node represents a linked list and contains two pointers of its type:
Pointer to next node in the main list (right pointer)
Pointer to a linked list where this node is head (down pointer). All linked lists are sorted.
You are asked to flatten the linked list into a single list. Use down pointer to link nodes of the flattened list. The flattened linked list should also be sorted. 
Input Format
The only argument given is head pointer of the doubly linked list.
Output Format
Return the head pointer of the Flattened list. 
Constraints
1 <= Total nodes in the list <= 100000
1 <= Value of node <= 10^9
For Example
Input 1:
       3 -> 4 -> 20 -> 20 ->30
       |    |    |     |    |
       7    11   22    20   31
       |               |    |
       7               28   39
       |               |
       8               39

Output 1:
3 -> 4 -> 7 -> 7 -> 8 -> 11 -> 20 -> 20 -> 20 -> 22 -> 28 -> 30 -> 31 -> 39 -> 39 

*/


/*
struct ListNode {
    int val;
    ListNode *right,*down;
    ListNode(int x) {
        val = x;
        right = down = NULL;
    }
};
*/
ListNode* mergeSortedLL(ListNode *h1, ListNode *h2) {
	ListNode *resHead = new ListNode(0);
	ListNode *resTail = resHead;

	while(h1 != NULL && h2 != NULL) {
		if(h1->val < h2->val) {
			resTail->down = h1;
			h1 = h1->down;
		} else {
			resTail->down = h2;
			h2 = h2->down;
		}
		resTail = resTail->down;
	}

	if(h1 != NULL) {
		resTail->down = h1;
	}

	if(h2 != NULL) {
		resTail->down = h2;
	}
	
	return resHead->down;

}

ListNode* flatten (ListNode* root) {

	if(root == NULL) {
		return root;
	}

	ListNode *curr = root->right;
	ListNode *res = root;
	//res->right = res->down;
	ListNode *next;
	
	
	while(curr != NULL) {
		next = curr->right;
		//curr->right = curr->down;
		res = mergeSortedLL(res,curr);
		curr = next;
	}
	return res;
}