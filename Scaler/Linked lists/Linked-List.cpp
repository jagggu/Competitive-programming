#include<iostream>
using namespace std;
class ListNode {
  public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *head = NULL;
void insert_node(int position, int value) {
    // @params position, integer
    // @params value, integer
    ListNode *tmp = new ListNode(value);
    if(position == 1) {
        head = tmp;
    } else {
        int cnt = 1;
        ListNode *curr = head;
        while(curr->next != NULL) {
            if(cnt == position-1) {
                break;
            }
            cnt++;
            curr = curr->next;
        }
        if(cnt == position) {
            curr->next = tmp;
        }
    }
}

void delete_node(int position) {
    // @params position, integer
    if(position == 1) {
        ListNode *tmp = head;
        head = head->next;
        delete tmp;
        return;
    } 
    int cnt = 1;
    ListNode *curr = head;
    while(curr->next != NULL) {
        if(cnt == position-1) {
            break;
        }
        cnt++;
        curr = curr->next;
    }
    if(cnt = position) {
        ListNode *tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
    }
}


void print_ll() {
    // Output each element followed by a space
    ListNode *tmp = head;
    while(tmp != NULL) {
        cout<<tmp->val<<' ';
        tmp = tmp->next;
    }
}
