/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 15:34:52
 * @LastEditTime : 2020-03-15 18:57:21
 * @Descripttion : 单链表的定义
 */
#ifndef LIST_NODE_H
#define LIST_NODE_H

struct ListNode {
    ListNode *next;
    int val;
    ListNode(int val) : val(val), next(NULL) {}
};

#endif