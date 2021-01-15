/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 18:35:38
 * @LastEditTime : 2020-03-15 19:11:50
 * @Descripttion : 双向链表操作实现（不重要，不做特殊处理，如控指针异常等）
 */
#include "./DoubleList.h"

/**
 * @description: 在pre之后插入节点node
 * @param pre 前置节点
 * @param node 待插入节点
 * @return: void
 */
void insert(DListNode *pre, DListNode *node) {
    node->next = pre->next;
    pre->next->pre = node;
    node->pre = pre;
    pre->next = node;
}

/**
 * @description: 删除pre节点的后继节点
 * @param pre 给定节点
 * @return: void
 */
void deleteNode(DListNode *pre, DListNode *next) {
    pre->next = next->next;
    next->next->pre = pre;
}