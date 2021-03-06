/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-15 14:18:46
 * @LastEditTime : 2021-02-21 17:50:01
 * @Descripttion : ListNode cases for LeetCode
 */

#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <map>

#include "../../entity/ListNode.h"
#include "../../entity/TreeNode.h"

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
     * 82.删除排序链表中的重复元素II
     */
    ListNode* deleteDuplicatesII(ListNode* head) {
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

    /**
     * 83.删除排序链表中的重复元素
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        while (pre) {
            if (pre->next and pre->val == pre->next->val) {
                pre->next = pre->next->next;
            } else {
                pre = pre->next;
            }
        }
        return head;
    }

    /**
     * 86.分隔链表
     */
    ListNode* partition(ListNode* head, int x) {
        ListNode node1(0), node2(0);
        ListNode *p1 = &node1, *p2 = &node2;
        while (head) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = node2.next;
        return node1.next;
    }

    /**
     * 92.反转链表II
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0), *pre = dummy, *start, *then;
        dummy->next = head;
        for (int i = 0; i < m - 1; i++) pre = pre->next; 
        start = pre->next, then = start->next;
        for (int i = 0; i < n - m; i++) {
            start->next = then->next;
            then->next = pre->next;
            pre->next = then;
            then = start->next;
        }
        return dummy->next;
    }

    /**
     * 109.有序链表转换二叉搜索树
     */
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode *fast = head->next, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode *mid = slow->next;
        slow->next = nullptr;
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }

    /**
     * 141.判断链表是否有环
     */
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) return true;
        } 
        return false;
    }

    /**
     * 142.环形链表II
     */
    ListNode *detectCycle(ListNode *head) {
        if (!head or !head->next) return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        if (fast != slow) return nullptr;
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

    /**
     * 143.重排链表
     */
    void reorderList(ListNode* head) {
        if (!head or !head->next) return;
        ListNode* p1 = head, *p2 = head;
        while (p2->next and p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        ListNode* preMid = p1, *preCur = p1->next;
        while (preCur->next) {
            ListNode* next = preCur->next;
            preCur->next = next->next;
            next->next = preMid->next;
            preMid->next = next;
        }
        p1 = head;
        p2 = preMid->next;
        while(p1 != preMid) {
            preMid->next = p2->next;
            p2->next = p1->next;
            p1->next = p2;
            p1 = p2->next;
            p2 = preMid->next;
        }
    }

    /**
     * 147.对链表进行插入排序
     */
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy, *cur = head, *next = nullptr;
        while (cur) {
            next = cur->next;
            while (pre->next and pre->next->val < cur->val) {
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            pre = dummy;
            cur = next;
        }
        return dummy->next;
    }

    /**
     * 148.排序链表
     */
    ListNode* sortList(ListNode* head) {
        if (!head or !head->next) return head;
        ListNode* pre = nullptr, *slow = head, *fast = head;
        while (fast and fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }
    private: ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0), *p = dummy;
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
        if (l1) p->next = l1;
        if (l2) p->next = l2;
        return dummy->next;
    }

    /**
     * 160.相交链表
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA or !headB) return nullptr;
        ListNode* a = headA, *b = headB;
        while (a != b) {
            if (a) a = a->next;
            else a = headB;
            if (b) b = b->next;
            else b = headA;
        }
        return a;
    }

    /**
     * 203.移除链表元素
     */
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        head->next = removeElements(head->next, val);
        if (head->val == val) return head->next;
        return head;
    }

    /**
     * 206.反转链表
     */
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead, *next;
        while (head) {
            next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        } 
        return newHead;
    }

    /**
     * 234.回文链表
     */
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast and fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (!fast) slow = slow->next;
        slow = reverseList(slow);
        while (slow) {
            if (slow->val == fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }

    /**
     * 328.奇偶链表
     */
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* odd = head, *even = head->next, *evenHead = even;
        while (even and even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = head;
        return head;
    }

    /**
     * 445.两数相加
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> numsa, numsb;
        while (l1) {
            numsa.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            numsb.push_back(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* newHead = new ListNode(0);
        while (!numsa.empty() or !numsb.empty()) {
            if (!numsa.empty()) {
                sum += numsa.back(), numsa.pop_back();
            }
            if (!numsb.empty()) {
                sum += numsb.back(), numsb.pop_back();
            }
            ListNode* node = new ListNode(sum / 10);
            newHead->val = sum % 10;
            node->next = newHead;
            newHead = node;
            sum /= 10;
        }
        if (newHead->val == 0) return newHead->next;
        return newHead;
    }

    /**
     * 725.分隔链表
     */
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> parts(k, nullptr);
        int len = 0;
        for (ListNode* node = root; node; node = node->next)
            len++;
        int n = len / k, r = len % k;
        ListNode* node = root, *prev = nullptr;
        for (int i = 0; node && i < k; i++, r--) {
            parts[i] = node;
            for (int j = 0; j < n + (r > 0); j++) {
                prev = node;
                node = node->next;
            }
            prev->next = nullptr;
        }
        return parts;
    }

    /**
     * 817.链表组件
     */
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> setG(G.begin(), G.end());
        int res = 0;
        while (head) {
            if (setG.count(head->val) and (!head->next or !setG.count(head->next->val))) res++;
            head = head->next;
        }
        return res;
    }

    /**
     * 876.链表的中间结点
     */
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    /**
     * 1171.从链表中删去总和值为零的连续节点
     */
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        dummy->next = head;
        int prefix = 0;
        map<int, ListNode*> m;
        while (cur) {
            prefix += cur->val;
            if (m.count(prefix)) {
                cur =  m[prefix]->next;
                int p = prefix + cur->val;
                while (p != prefix) {
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[prefix]->next = cur->next;
            } else {
                m[prefix] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};