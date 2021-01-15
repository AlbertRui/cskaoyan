/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-15 14:18:46
 * @LastEditTime : 2021-01-15 14:32:41
 * @Descripttion : ListNode cases for LeetCode
 */

#include "../../entity/ListNode.h"

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
};