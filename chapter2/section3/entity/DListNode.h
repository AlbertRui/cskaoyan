/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-15 18:16:50
 * @LastEditTime : 2020-03-15 18:19:48
 * @Descripttion : 自定义双向链表
 */
struct DListNode {
    int val;
    DListNode *pre;
    DListNode *next;
    DListNode(int val) : val(val), pre(nullptr), next(nullptr) {}
};
