
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

	ListNode *curr = A;
	ListNode *next;

	while(curr != NULL) {
		next = curr->next;
	//	cout<<curr->val<<' ';
		ListNode *tmp = new ListNode(curr->val);
		curr->next = tmp;
		tmp->next = next;
		curr = next;
	}
	

	curr = A;
	while(curr != NULL) {
	    //cout<<curr->val<<' ';
		if(curr->next != NULL) {
			curr->next->random = curr->random?curr->random->next:curr->random;
		}
		curr = curr->next?curr->next->next:curr->next;
	}

	ListNode *original = A;
	ListNode *pseudo = A->next;
    ListNode *copy = pseudo;
	while(original != NULL && pseudo != NULL) {
		  //cout<<pseudo->val<<' ';
		//pseudo->random = original->random?original->random->next:original->random;
		original->next = original->next?original->next->next:original->next;
		pseudo->next = pseudo->next?pseudo->next->next : pseudo->next;
		
        
		original = original->next;
		pseudo = pseudo->next;		
	}
    //cout<<endl;
	return copy;


}