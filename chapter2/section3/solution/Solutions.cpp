/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 22:26:05
 * @LastEditTime : 2020-03-16 23:51:01
 * @Descripttion : solutions for section3
 */
#include <iostream>

#include "./Solutions.h" 

using namespace std;

/**
 * @description: 第一题，递归删除不带头节点的单链表中所有值为x的节点
 * @param first 链表中的第一个元素
 * @param x 待删除的节点x
 * @return: void
 */
void deleteX(ListNode *first, int x) {
    if (first == nullptr) return;
    if (first->val == x) {
        ListNode *p = first;
        first = first->next;
        delete p;
        deleteX(first, x);
    } else {
        deleteX(first->next, x);
    }
}

/**
 * @description: 第二题，删除带头节点的单链表中所有值为x的节点
 * @param head 链表中的第一个元素
 * @param x 待删除的节点x
 * @return: void
 */
void deleteXWithHead(ListNode *head, int x) {
    if (head == nullptr) return;
    ListNode *pre = head, *cur = head->next;
    while (cur != nullptr) {
        if (cur->val == x) {
            cur = cur->next;
            pre->next = cur;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
}

/**
 * @description: 第三题，从尾到头反向输出每个节点的值
 * @param head 给定单链表的头结点
 * @return: void
 */
void printValReversely(ListNode *head) {
    if (head == nullptr) return;
    printValReversely(head->next);
    cout << head->val << "\t" << endl;
}

/**
 * @description: 第四题，删除最小值节点
 * @param head 给定链表的头结点
 * @return: 最小值节点
 */
ListNode *deleteMinVal(ListNode *head) {
    ListNode *pre = head, *cur = pre->next;
    ListNode *minPre = pre, *minCur = minPre->next;
    while (cur != nullptr) {
        if (cur->val < minCur->val) {
            minPre = pre;
            minCur = cur;
        }
        pre = cur;
        cur = cur->next;
    }
    minPre->next = minCur->next;
    delete minCur;
    return head;
}

/**
 * @description: 第五题，逆置带头结点的单链表(递归)
 * @param head 给定单链表的头结点
 * @return: 逆置后的单链表
 */
ListNode *reverse(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *newHead = reverse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

/**
 * @description: 第六题，使链表递增有序
 * @param head 给定链表的头结点
 * @return: 调整后的升序链表
 */
ListNode *makeAscend(ListNode *head) {
    ListNode *pre = head, *cur = pre->next, *next;
    while (cur != nullptr); {
        next = cur->next;
        pre = head->next;
        while (pre != nullptr && pre->val < cur->val) {
            pre = pre->next;
        }
        pre->next = cur->next;
        cur->next = pre;
        cur = next;
    }
    return head;
}

/**
 * @description: 第七题，删除无序链表中元素值介于（m，n）之间的元素
 * @param head 给定链表的头结点
 * @param m 上界m
 * @param n 下界n
 * @return: 删除操作之后的新链表
 */
ListNode *deleteByScope(ListNode *head, int m, int n) {
    ListNode *pre = head, *cur = pre->next;
    while (cur != nullptr) {
        if (cur->val < n && cur->val > m) {
            pre->next = cur->next;
        } else {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

/**
 * @description: 第八题，找出两个链表的公共节点
 * @param headA 链表A
 * @param headB 链表B
 * @return: 公共节点
 */
ListNode *findCommonNode(ListNode *headA, ListNode *headB) {
    ListNode *tempA = headA, *tempB = headB;
    while (tempA != tempB) {
        if (tempA == nullptr) {
            tempA = headB;
        } else {
            tempA = tempA->next;
        }
        if (tempB == nullptr) {
            tempB = headA;
        } else {
            tempB = tempB->next;
        }
    }
    return tempA;
}

/**
 * @description: 第九题，按递增顺序输出链表中的元素，不允许使用数组作为辅助空间
 * @param head 给定链表的头结点
 * @return: void
 */
void printValByAsc(ListNode *head) {
    if (head == nullptr) return;
    ListNode *pre = head, *cur = pre->next, *preMin, *curMin;
    while (head->next != nullptr) {
        preMin = head;
        cur = preMin->next;
        while (cur->next != nullptr) {
            if (cur->next->val < preMin->next->val) {
                preMin = cur;
            }
            cur = cur->next;
        }
        cout << preMin->next->val << "\t";
        curMin = preMin->next;
        preMin->next = curMin->next;
        delete curMin;
    }
    delete head;
}

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
ListNode *decompose(ListNode *head);

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
 * @description: 从两个升序链表的公共元素中产生单链表
 * @param headA 升序链表A
 * @param headB 升序链表B
 * @return: 生成的新链表
 */
ListNode *getListNodeByCommon(ListNode *headA, ListNode *headB);