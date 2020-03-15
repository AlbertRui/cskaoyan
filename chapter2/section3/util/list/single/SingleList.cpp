/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 15:57:30
 * @LastEditTime : 2020-03-15 18:24:47
 * @Descripttion :
 */
#include <iostream>

#include "./SingleList.h"

using namespace std;

/**
 * @description: 头插法建立单链表
 * @param head 待建立的链表头结点
 * @return:
 */
ListNode *head4BuildListNode(ListNode *head) {
    if (head == NULL) {
        head = new ListNode(0);
    }
    cout << "please input node value : " << endl;
    int x = 0;
    cin >> x;
    while (x != 9999) {
        ListNode *node = new ListNode(x);
        node->next = head->next;
        head->next = node;
        cin >> x;
    }
    return head;
}

/**
 * @description: 尾插法建立单链表
 * @param head 链表的头结点
 * @return: 建立好的单链表
 */
ListNode *tail4BuildListNode(ListNode *head) {
    if (head == NULL) {
        head = new ListNode(0);
    }
    ListNode *tail = head;
    cout << "please input node value : " << endl;
    int val = 0;
    cin >> val;
    while (val != 9999) {
        ListNode *node = new ListNode(val);
        tail->next = node;
        tail = node;
        cin >> val;
    }
    tail->next = NULL;
    return head;
}

/**
 * @description: 根据索引查找节点
 * @param head 给定单链表的头结点
 * @param index 给定待查找索引
 * @return: 查找到的节点
 */
ListNode *getNodeByIndex(ListNode *head, int index) {
    if (index < 0)
        return nullptr;
    int i = 0;
    while (head != nullptr) {
        if (i++ == index)
            return head;
        head = head->next;
    }
    return nullptr;
}

/**
 * @description: 按值查找节点
 * @param head 待查找链表头结点
 * @param val 待查找的节点对应的值
 * @return: 查找到的节点
 */
ListNode *getNodeByValue(ListNode *head, int val) {
    while (head != nullptr) {
        if (head->val == val)
            return head;
    }
    return nullptr;
}

/**
 * @description: 在索引位置index之后插入节点node
 * @param head 待插入链表的头结点
 * @param node 待插入节点
 * @param index 待插入节点前置索引
 * @return: 插入操作后的新链表
 */
ListNode *insertAfterIndex(ListNode *head, ListNode *node, int index) {
    ListNode *pre = getNodeByIndex(head, index);
    insertAfterNode(pre, node);
    return head;
}

ListNode *insertBeforeIndex(ListNode *head, ListNode *node, int index) {
    if (index <= 0)
        return nullptr;
    if (index == 1) {
        node->next = head;
        return node;
    }
    ListNode *pre = getNodeByIndex(head, index - 1);
    insertAfterNode(pre, node);
    return head;
}

/**
 * @description: 在节点pre之后插入节点node
 * @param pre 前置节点
 * @param node 待插入节点
 * @return: 插入操作之后的新链表
 */
void insertAfterNode(ListNode *pre, ListNode *node) {
    if (pre != nullptr) {
        node->next = pre->next;
        pre->next = node;
        cout << "插入成功！" << endl;
    }
}

/**
 * @description: 删除索引位置为index的节点
 * @param head 链表头结点
 * @param index 待删除节点对应索引
 * @return: 删除的节点
 */
ListNode *deleteNodeByIndex(ListNode *head, int index) {
    if (head == nullptr || index < 1)
        return nullptr;
    ListNode *pre = getNodeByIndex(head, index - 1);
    return deleteAfterNode(pre);
}

/**
 * @description: 删除指定节点之后的节点
 * @param pre 给定节点
 * @return: 删除的节点
 */
ListNode *deleteAfterNode(ListNode *pre) {
    ListNode *node = pre->next;
    if (node == nullptr) return nullptr;
    pre->next = node->next;
    node->next == nullptr;
    return node;
}

/**
 * @description:  求表长
 * @param head 给定链表头结点
 * @return: 链表长度
 */
int getLength(ListNode *head) {
    int length = -1;
    while (head != nullptr) {
         length++;
         head = head->next;
    } 
    return length;
}