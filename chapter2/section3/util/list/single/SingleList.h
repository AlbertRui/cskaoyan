/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 15:36:59
 * @LastEditTime : 2020-03-15 18:47:07
 * @Descripttion : 定义对于链表的各种操作
 */
#ifndef UTIL_H
#define UTIL_H

#include "../../../entity/ListNode.h"

/**
 * @description: 头插法建立单链表
 * @param head 待建立的链表头结点
 * @return:
 */
ListNode *head4BuildListNode(ListNode *head);

/**
 * @description: 尾插法建立单链表
 * @param head 链表的头结点
 * @return: 建立好的单链表
 */
ListNode *tail4BuildListNode(ListNode *head);

/**
 * @description: 根据索引查找节点
 * @param head 给定单链表的头结点
 * @param index 给定待查找索引
 * @return: 查找到的节点
 */
ListNode *getNodeByIndex(ListNode *head, int index);

/**
 * @description: 按值查找节点
 * @param head 待查找链表头结点
 * @param val 待查找的节点对应的值
 * @return: 查找到的节点
 */
ListNode *getNodeByValue(ListNode *head, int val);

/**
 * @description: 在索引位置index之后插入节点node
 * @param head 待插入链表的头结点
 * @param node 待插入节点
 * @param index 待插入节点前置索引
 * @return: 插入操作后的新链表
 */
ListNode *insertAfterIndex(ListNode *head, ListNode *node, int index);

/**
 * @description: 在索引位置index之前插入节点node
 * @param head 待插入链表的头结点
 * @param node 待插入节点
 * @param index 待插入节点后置索引
 * @return: 插入操作后的新链表
 */
ListNode *insertBeforeIndex(ListNode *head, ListNode *node, int index);

/**
 * @description: 在节点pre之后插入节点node
 * @param pre 前置节点
 * @param node 待插入节点
 * @return: void
 */
void insertAfterNode(ListNode *pre, ListNode *node);

/**
 * @description: 删除索引位置为index的节点
 * @param head 链表头结点
 * @param index 待删除节点对应索引
 * @return: 删除的节点
 */
ListNode *deleteNodeByIndex(ListNode *head, int index);

/**
 * @description: 删除指定节点之后的节点
 * @param pre 给定节点
 * @return: 删除的节点
 */
ListNode *deleteAfterNode(ListNode *pre);

/**
 * @description:  求表长
 * @param head 给定链表头结点
 * @return: 链表长度，头结点为空则返回-1；
 */
int getLength(ListNode *head);

#endif
