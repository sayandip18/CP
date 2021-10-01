#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
};

void mergeSort(Node** headref){
    Node* head = *headref;
    Node* a;
    Node* b;
    if ((head == NULL) || (head->next == NULL)) return;
    splitList(head, &a, &b);

    mergeSort(a);
    mergeSort(b);

    *headref = sortedMerge(a, b);
}

Node* sortedMerge(Node* a, Node* b){
    // done already
}

void splitList(Node* head, Node** frontref, Node** backref)
{
    Node* fast; Node* slow;
    slow = head;
    fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontref = source;
    *backref = slow->next;
    slow->next = NULL;
}
