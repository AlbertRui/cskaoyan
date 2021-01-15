/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 18:16:50
 * @LastEditTime : 2020-03-15 18:57:47
 * @Descripttion : 自定义双向链表
 */
#ifndef DOUBLE_LIST_NODE_H
#define DOUBLE_LIST_NODE_H

struct DListNode {
    int val;
    DListNode *pre;
    DListNode *next;
    DListNode(int val) : val(val), pre(nullptr), next(nullptr) {}
};

#endif
