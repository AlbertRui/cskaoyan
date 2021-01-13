#ifndef LIST_NODE_H
#define LIST_NODE_H

struct ListNode {
    ListNode *next;
    int val;
    ListNode(int val) : val(val), next(NULL) {}
};

#endif