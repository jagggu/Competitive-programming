/*
Clone a linked list
Given a doubly linked list of integers with one pointer of each node pointing to the next node (just like in a single link list) while the second pointer, however, can point to any node in the list and not just the previous node. You have to create a copy of this list and return the head pointer of the duplicated list.  
Input Format
The only argument given is head pointer of the doubly linked list.
Output Format
Return the head pointer of the duplicated list. 
Constraints
1 <= length of the list <= 100000
1 <= Value of node <= 10^5
For Example
Input 1:
     1 -> 2 -> 3 -> 4 -> 5
     random pointer of each node 
     1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1


Output 1:
    1 -> 2 -> 3 -> 4 -> 5
    random pointer of each node 
    1 -> 5 2 -> 4 3 -> 3 4 -> 2 5 -> 1

  */


/*
struct ListNode { 
    int val; 
    ListNode *next,*random; 
    ListNode(int x) { 
        val = x; 
        next = random = NULL; 
    } 
}; 
*/
ListNode* clonelist(ListNode *A) {

	unordered_map<ListNode*,ListNode*> m;

	ListNode *curr = A;
	while(curr != NULL) {
		ListNode *tmp = new ListNode(curr->val);
		m[curr] = tmp;
		curr = curr->next;
	}
	//cout<<"Curr: "<<curr<<' '<<"A: "<<A<<endl;
	curr = A;
	ListNode *head = m[curr];
	ListNode *tmp = head;
	while(curr != NULL) {
		tmp->next = m[curr->next];
		tmp->random = m[curr->random];
		tmp = tmp->next;
		curr = curr->next;
	}
	return head;

}