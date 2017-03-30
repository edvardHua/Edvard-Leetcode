//
// Created by edvard on 29/03/2017.
//
// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    // Constructor
    ListNode(int x): val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    // Check null or not
    if(l1 == NULL && l2 != NULL)
        return l2;
    if(l1 != NULL && l2 == NULL)
        return l1;
    if(l1 == NULL && l2 == NULL)
        return NULL;

    // Merging list
    struct ListNode *head = NULL;
    struct ListNode *mergedList = NULL;
    while (l1 != NULL && l2 != NULL){
        int tmp;
        if(l1->val > l2->val){
            tmp = l2->val;
            l2 = l2->next;
        }else{
            tmp = l1->val;
            l1 = l1->next;
        }

        if(mergedList == NULL){
            struct ListNode* newNode = new ListNode(tmp);
            mergedList = newNode;
            head = mergedList;
        }else{
            struct ListNode* newNode = new ListNode(tmp);
            mergedList->next = newNode;
            mergedList = mergedList->next;
        }
    }

    // Moving the rest of element
    if(l1 == NULL && l2 != NULL){
        mergedList->next = l2;
    }else if(l1 != NULL && l2 == NULL){
        mergedList->next = l1;
    }

    return head;
}

int main(void) {
    return 0;
}