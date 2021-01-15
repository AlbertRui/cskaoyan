/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 18:35:18
 * @LastEditTime : 2020-03-15 19:10:38
 * @Descripttion : 双向链表的操作(不重要)
 */
#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include "../../../entity/DListNode.h"

/**
 * @description: 在pre之后插入节点node
 * @param pre 前置节点
 * @param node 待插入节点
 * @return: void
 */
void insert(DListNode *pre, DListNode *node);

/**
 * @description: 删除pre节点的后继节点
 * @param pre 给定节点
 * @return: void
 */
void deleteNode(DListNode *pre, DListNode *next);

#endif