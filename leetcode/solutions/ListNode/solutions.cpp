/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-15 14:18:46
 * @LastEditTime : 2021-01-15 20:40:37
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

    /**
     * 24.两两交换链表中的节点
     */
    ListNode* swapPairs(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }

    /**
     * 25.k个一组反转链表
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        for (ListNode* i = head; i; n++, i = i->next);
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        for (ListNode *pre = dummy, *tail = head; n >= k; n -= k) {
            for (int i = 1; i < k; i++) {
                ListNode* next = tail->next->next;
                tail->next->next = pre->next;
                pre->next = tail->next;
                tail->next = next;
            }
            pre = tail;
            tail = tail->next;
        }  
        return dummy->next;
    }

    /**
     * 61.旋转链表
     */
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* tail = head;
        int len = 1;
        while (tail->next) tail = tail->next, len++;
        tail->next = head;
        if (k %= len) {
            for (int i = 0; i < len - k; i++) tail = tail->next;
        }    
        ListNode* newHead = tail->next;
        tail->next = NULL;
        return newHead;
    }

    /**
     * 82.删除排序链表中的重复元素
     */
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0), *pre = dummy, *cur = head;
        dummy->next = head;
        while(cur){
            while(cur->next and cur->val == cur->next->val){
                cur = cur->next;
            }
            if(pre->next == cur){
                pre = pre->next;
            } else {
                pre->next = cur->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};