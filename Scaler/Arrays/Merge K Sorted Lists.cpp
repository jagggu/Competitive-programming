/*
Merge K Sorted Lists
Problem Description
Given a list containing head pointers of N sorted linked lists. Merge these N given sorted linked lists and return it as one sorted list.


Problem Constraints
1 <= total number of elements in given linked lists <= 100000


Input Format
First and only argument is a list containing N head pointers.


Output Format
Return a pointer to the head of the sorted linked list after merging all the given linked lists.


Example Input
Input 1:
 1 -> 10 -> 20
 4 -> 11 -> 13
 3 -> 8 -> 9
Input 2:
 10 -> 12
 13
 5 -> 6
   


Example Output
Output 1:
 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20
Output 2:
 5 -> 6 -> 10 -> 12 ->13
   


Example Explanation
Explanation 1:
 The resulting sorted Linked List formed after merging is 1 -> 3 -> 4 -> 8 -> 9 -> 10 -> 11 -> 13 -> 20.
Explanation 2:
 The resulting sorted Linked List formed after merging is 5 -> 6 -> 10 -> 12 ->13.

 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class MyComparator {

public:
	int operator() (pair<int, int> p1, pair<int, int> p2) {
		return p1.first > p2.first;
	}
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	priority_queue<pair<int, int>, vector<pair<int, int> >, MyComparator > minPq;

	int n = A.size();

	for (int i = 0; i < n; i++) {
		if (A[i] != NULL) {
			minPq.push(make_pair(A[i]->val, i));
		}
	}

	ListNode *head = NULL;
	ListNode *tail = NULL;

	while (!minPq.empty()) {
		pair<int,int> p = minPq.top();
		int ele = p.first;
	//	cout<<ele<<endl;
		int indx = p.second;
		minPq.pop();

		ListNode *tmp = new ListNode(ele);

		if (head == NULL) {

			head = tmp;
			tail = tmp;
		} else {
			tail->next = tmp;
			tail = tail->next;
		}

		A[indx] = A[indx]->next;

		if(A[indx] != NULL) {
			minPq.push(make_pair(A[indx]->val,indx));
		}

	}

	return head;
}
