/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-09 20:55:54
 * @LastEditTime : 2021-01-09 20:57:12
 * @Descripttion : Definition for a binary tree node.
 */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };