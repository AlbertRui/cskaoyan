/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 22:25:51
 * @LastEditTime : 2020-03-17 21:23:09
 * @Descripttion : 
 */
#ifndef SOLUTIONS_H
#define SOLUTINOS_H

#include "../entity/ListNode.h"

/**
 * @description: 第一题，递归删除不带头节点的单链表中所有值为x的节点
 * @param first 链表中的第一个元素
 * @param x 待删除的节点x
 * @return: void
 */
void deleteX(ListNode *first, int x);

/**
 * @description: 第二题，删除带头节点的单链表中所有值为x的节点
 * @param head 链表中的第一个元素
 * @param x 待删除的节点x
 * @return: void
 */
void deleteXWithHead(ListNode *head, int x);

/**
 * @description: 第三题，从尾到头反向输出每个节点的值
 * @param head 给定单链表的头结点
 * @return: void
 */
void printValReversely(ListNode *head);

/**
 * @description: 第四题，删除最小值节点
 * @param head 给定链表的头结点
 * @return: 最小值节点
 */
ListNode *deleteMinVal(ListNode *head);

/**
 * @description: 第五题，逆置带头结点的单链表
 * @param head 给定单链表的头结点
 * @return: 逆置后的单链表
 */
ListNode *reverse(ListNode *head);

/**
 * @description: 第六题，使链表递增有序
 * @param head 给定链表的头结点
 * @return: 调整后的升序链表
 */
ListNode *makeAscend(ListNode *head);

/**
 * @description: 第七题，删除无序链表中元素值介于（m，n）之间的元素
 * @param head 给定链表的头结点
 * @param m 上界m
 * @param n 下界n
 * @return: 删除操作之后的新链表
 */
ListNode *deleteByScope(ListNode *head, int m, int n);

/**
 * @description: 第八题，找出两个链表的公共节点
 * @param headA 链表A
 * @param headB 链表B
 * @return: 公共节点
 */
ListNode *findCommonNode(ListNode *headA, ListNode *headB);

/**
 * @description: 第九题，按递增顺序输出链表中的元素，不允许使用数组作为辅助空间
 * @param head 给定链表的头结点
 * @return: void
 */
void printValByAsc(ListNode *head);

/**
 * @description: 第十题，将给定链表分解为两个带头结点的单链表
 * 使得两个单链表分别含有其奇数元素和偶数元素
 * @param head 待操作链表头结点
 * @return: 分解后的另外一个单链表
 */
ListNode *decompose(ListNode *head);

/**
 * @description: 第十一题，{a1, b1, a2, b2 ..., an, bn} -> {a1, a2, ..., an} + {bn, b(n - 1), ..., b1}
 * @param head 待拆分元素的头结点
 * @return: 拆分后的另一个元素
 */
ListNode *decompose2(ListNode *head);

/**
 * @description: 第十二题，去除升序链表中的重复元素
 * @param head 待操作元素头结点
 * @return: 去除重复后的单链表
 */
ListNode *trimDuplication(ListNode *head);

/**
 * @description: 第十三题，合并两个升序链表为一个递减有序链表
 * @param headA 升序链表A
 * @param headB 升序链表B
 * @return: 合并后的递减有序链表
 */
ListNode *merge(ListNode *headA, ListNode *headB);

/**
 * @description: 第十四题，从两个升序链表的公共元素中产生单链表
 * @param headA 升序链表A
 * @param headB 升序链表B
 * @return: 生成的新链表
 */
ListNode *getListNodeByCommon(ListNode *headA, ListNode *headB);

#endif