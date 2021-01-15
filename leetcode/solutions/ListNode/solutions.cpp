/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-15 14:18:46
 * @LastEditTime : 2021-01-15 15:59:34
 * @Descripttion : ListNode cases for LeetCode
 */

#include <vector>
#include <queue>

#include "../../entity/ListNode.h"

using namespace std;

class solutoins {
    /**
     * 2.两数相加
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 or l2 or extra) {
            if (l1) extra += l1->val, l1 = l1->next;
            if (l2) extra += l2->val, l2 = l2->next;
            p->next = new ListNode(extra % 10);
            extra /= 10;
            p = p->next;
        }
        return preHead.next;
    }

    /**
     * 19.删除链表倒数第n个节点
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = new ListNode(0), *res = slow, *fast = head;
        slow->next = fast;
        while (n--) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return res->next;
    }

    /**
     * 21.合并两个升序链表
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0), *p = dummy;
        while (l1 and l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            } 
            p = p->next;
        }
        if (l2) {
            l1 = l2;
        }
        while (l1) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        }
        return dummy->next;
    }

    /**
     * 23.合并k个升序链表
     */
    struct compare {
        bool operator() (const ListNode* l, const ListNode* r) {
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        ListNode* dummy = new ListNode(0), *tail = dummy;
        while (!pq.empty()) {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next) {
                pq.push(tail->next);
            }
        }
        return dummy->next;
    }
};