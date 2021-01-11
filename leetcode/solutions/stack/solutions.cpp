/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-08 21:47:01
 * @LastEditTime : 2021-01-11 17:38:43
 * @Descripttion : stack solutions from leetcode
 */
#include <queue>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

#include "../../entity/TreeNode.h"

using namespace std;

class solutions {

    /**
     * 20. 有效的括号
     * 给定一个只包括 '('，')'，'{'，'}'，'['，']'
     * 的字符串，判断字符串是否有效。 有效字符串需满足：
     * 左括号必须用相同类型的右括号闭合。
     * 左括号必须以正确的顺序闭合。
     * 注意空字符串可被认为是有效字符串。
     */
    bool isValid(string s) {
        stack<char> stk;
        for (char &ch : s) {
            switch (ch) {
            case '{':
                stk.push('}');
            case '[':
                stk.push(']');
            case '(':
                stk.push(')');
            default:
                if (stk.size() == 0 || ch != stk.top()) {
                    return false;
                } else {
                    stk.pop();
                }
            }
        }
        return stk.size() == 0;
    }

    /**
     * 42. 接雨水给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，
     * 计算按此排列的柱子，下雨之后能接多少雨水。
     */
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int res = 0;
        int maxLeft = 0, maxRight = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] > maxLeft) {
                    maxLeft = height[left];
                } else {
                    res += maxLeft - height[left];
                }
                left++;
            } else {
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    res += maxRight - height[right];
                }
                right--;
            }
        }
        return res;
    }

    /**
     * 71. 简化路径
     * 以 Unix
     * 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
     * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点
     * （..）
     * 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux
     * / Unix中的绝对路径 vs 相对路径 请注意，返回的规范路径必须始终以斜杠 /
     * 开头，并且两个目录名之间必须只有一个斜杠
     * /。最后一个目录名（如果存在）不能以 / 结尾。
     * 此外，规范路径必须是表示绝对路径的最短字符串。
     */
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "" or tmp == ".") {
                continue;
            } else if (tmp == "..") {
                if (!stk.empty()) {
                    stk.pop_back();
                }
            } else {
                stk.push_back(tmp);
            }
        }
        for (string str : stk) {
            res += "/" + str;
        }
        if (res.empty()) {
            return "/";
        }
        return res;
    }

    /**
     * 84. 柱状图中最大的矩形
     * 给定 n
     * 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1
     * 。 求在该柱状图中，能够勾勒出来的矩形的最大面积。
     */
    int largestRectangleArea(vector<int> &heights) {
        int len = heights.size();
        int lessFromLeft[len];
        int lessFromRight[len];
        lessFromLeft[0] = -1;
        lessFromRight[len - 1] = len;

        for (int i = 1; i < len; i++) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = lessFromLeft[p];
            }
            lessFromLeft[i] = p;
        }

        for (int i = len - 2; i >= 0; i--) {
            int p = i + 1;
            while (p < len && heights[p] >= heights[i]) {
                p = lessFromRight[p];
            }
            lessFromRight[i] = p;
        }

        int maxArea = 0;
        for (int i = 0; i < len; i++) {
            maxArea = max(
                maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        }

        return maxArea;
    }

    /**
     * 85. 最大矩形
     * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，
     * 找出只包含 1 的最大矩形，并返回其面积。
     */
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left, n, 0);
        fill_n(right, n, n - 1);
        fill_n(height, n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            int rB = n - 1;
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], rB);
                } else {
                    right[j] = n - 1;
                    rB = n - 1;
                }
            }

            int lB = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(left[j], lB);
                    height[j]++;
                    maxArea = max(maxArea, (right[j] - left[j] + 1));
                } else {
                    height[j] = 0;
                    left[j] = 0;
                    lB = j + 1;
                }
            }
        }
        return maxArea;
    }

    /**
     * 94. 二叉树的中序遍历
     * 给定一个二叉树的根节点 root ，返回它的 中序 遍历
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode *> nodes;
        while (cur != nullptr or !nodes.empty()) {
            while (cur) {
                nodes.push(cur);
                cur = cur->left;
            }
            cur = nodes.top();
            nodes.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
        return res;
    }

    /**
     * 103. 二叉树的锯齿形层序遍历
     * 给定一个二叉树，返回其节点值的锯齿形层序遍历。
     * （即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        bool zigzag = true;
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> curRes(size);
            for (int i = 0; i < size; i++) {
                TreeNode *cur = nodes.front();
                nodes.pop();
                int index = (zigzag) ? i : (size - 1 - i);
                curRes[index] = cur->val;
                TreeNode *left = cur->left;
                if (left) {
                    nodes.push(left);
                }
                TreeNode *right = cur->right;
                if (right) {
                    nodes.push(right);
                }
            }
            zigzag = !zigzag;
            res.push_back(curRes);
        }
        return res;
    }

    /**
     * 144.二叉树前序遍历
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> nodes;
        TreeNode *cur = root;
        while (cur) {
            res.push_back(cur->val);
            if (cur->right) {
                nodes.push(cur->right);
            }
            cur = cur->left;
            if (!cur and !nodes.empty()) {
                cur = nodes.top();
                nodes.pop();
            }
        }
        return res;
    }

    /**
     * 145.二叉树后序遍历
     */
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> nodes;
        if (!root)
            return nodes;
        stack<TreeNode *> todo;
        TreeNode *cur = root, *last = nullptr;
        while (cur or !todo.empty()) {
            if (cur) {
                todo.push(cur);
                cur = cur->left;
            } else {
                TreeNode *node = todo.top();
                if (node->right and last != node->right) {
                    cur = node->right;
                } else {
                    nodes.push_back(node->val);
                    last = node;
                    todo.pop();
                }
            }
        }
        return nodes;
    }

    /**
     * 逆波兰表达式求值
     */
    int evalRPN(vector<string> &tokens) {
        int a, b;
        stack<int> vals;
        for (string token : tokens) {
            if (token == "+") {
                int a = vals.top();
                vals.pop();
                int b = vals.top();
                vals.pop();
                vals.push(a + b);
            } else if (token == "-") {
                int b = vals.top();
                vals.pop();
                int a = vals.top();
                vals.pop();
                vals.push(a - b);
            } else if (token == "/") {
                int b = vals.top();
                vals.pop();
                int a = vals.top();
                vals.pop();
                vals.push(a / b);
            } else if (token == "*") {
                int b = vals.top();
                vals.pop();
                int a = vals.top();
                vals.pop();
                vals.push(a * b);
            } else {
                vals.push(stoi(token));
            }
        }
        return vals.top();
    }

    /**
     * 224.基本计算器
     */
    int calculate(string s) {
        stack<int> vals;
        int res = 0, num = 0, sign = 1;
        for (char ch : s) {
            if (isdigit(ch)) {
                num += 10 * num + (ch - '0');
            } else if (ch == '+') {
                res += sign * num;
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                res += sign * num;
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                vals.push(res);
                vals.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                res += sign * num;
                num = 0;
                res *= vals.top();
                vals.pop();
                res += vals.top();
                vals.pop();
            }
        }
        if (num == 0) {
            res += sign * num;
        }
        return res;
    }

    /**
     * 基本计算器II
     */
    int calculateII(string s) {
        if (s.size() == 0) return 0;
        stack<int> vals;
        s += '+';
        char op = '+';
        for (int i = 0, n = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                n = n * 10 + c - '0';
                continue;
            }
            if (c == ' ') continue;
            if (op == '+') vals.push(n);
            else if (op == '-') vals.push(-n);
            else if (op == '*') {
                int val = vals.top(); vals.pop();
                vals.push(val * n);
            } else if (op == '/') {
                int val = vals.top(); vals.pop();
                vals.push(val / n);
            }
            op = c;
            n = 0;
        }

        int total = 0;
        while (!vals.empty()) {
            total += vals.top();
            vals.pop();
        }
        return total;
    }

    /**
     * 316.去除重复字母
     */
    string removeDuplicateLetters(string s) {
        int res[26] = {0};
        bool visited[26] = {false};
        for (char ch : s) {
            res[ch - 'a']++;
        }
        stack<char> chars;
        int index = 0;
        for (char c : s) {
            index = c - 'a';
            res[index]--;
            if (!visited[index]) {
                while (!chars.empty() and c < chars.top() and res[chars.top() - 'a'] != 0) {
                    visited[chars.top() - 'a'] = false;
                    chars.pop();
                }
                visited[index] = true;
                chars.push(c);
            }
        }
        string ans = "";
        while (!chars.empty()) {
            ans = chars.top() + ans;
            chars.pop();
        }
        return ans;
    }

    /**
     * 331.验证二叉树的前序序列化
     */
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;
        preorder += ",";
        int diff = 1;
        for (int idx = 0; idx < preorder.size(); idx++) {
            if (preorder[idx] == ',') {
                if (--diff < 0) return false;
                if (preorder[idx - 1] != '#') diff += 2; 
            }
        }
        return diff == 0;
    }

    /**
     * 394.字符串解码
     */
    string decodeString(string s) {
        string res = "";
        stack<int> countStack;
        stack<string> resStack;
        int k = 0;
        for (char ch : s) {
            if (isdigit(ch)) {
                k += 10 * k + ch - '0';
            } else if (ch == '[') {
                countStack.push(k);
                resStack.push(res);
                res = "";
                k = 0;
            } else if (ch == ']') {
                string tmp = res;
                res = resStack.top(); resStack.pop();
                k = countStack.top(); countStack.pop();
                while (k-- > 0) {
                    res += tmp;
                }
            } else {
                res += ch;
            }
        }
        return res;
    }

    /**
     * 移掉k位数字
     */
    string removeKdigits(string num, int k) {
        int len = num.size();
        if (len == 0) return "0";
        stack<char> chars;
        for (char ch : num) {
            while (k > 0 and !chars.empty() and chars.top() > ch) {
                chars.pop();
                k--;
            }
            chars.push(ch);
        }
        while (k-- > 0) chars.pop();
        string ans = "";
        while (!chars.empty()) {
            ans = chars.top() + ans;
            chars.pop();
        }
        if (ans.size() == 0) return "0";
        int pos = 0;
        while (pos < ans.size()) {
            if (ans[pos++] != '0') {
                break;
            }
        }
        return ans.substr(pos - 1);
    }

    /**
     * 456. 132模式
     */
    bool find132pattern(vector<int>& nums) {
        int s3 = INT_MIN;
        stack<int> vals;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < s3) return true;
            while (!vals.empty() and nums[i] > vals.top()) {
                s3 = vals.top(); vals.pop();
            }
            vals.push(nums[i]);
        }
        return false;
    }

    /**
     * 496.下一个更大元素
     */
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        stack<int> vals;
        for (int num : nums2) {
            while (!vals.empty() and vals.top() < num) {
                m[vals.top()] = num;
                vals.pop();
            }
            vals.push(num);
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (m.count(nums1[i])) {
                nums1[i] = m[nums1[i]];
            } else {
                nums1[i] = -1;
            }
        }
        return nums1;
    }

    /**
     * 下一个更大元素II
     */
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> stack, res(n, -1);
        for (int i = 0; i < n * 2; i++) {
            while (stack.size() and nums[stack.back()] < nums[i % n]) {
                res[stack.back()] = nums[i % n];
                stack.pop_back();
            }
            stack.push_back(i % n);
        }
        return res;
    }

    /**
     * 棒球比赛
     */
    int calPoints(vector<string>& ops) {
        int ans = 0;
        vector<int> vals;
        for (string op : ops) {
            if (op == "C") {
                ans -= vals.back();
                vals.pop_back();
            } else {
                if (op == "D") {
                    vals.push_back(vals.back() * 2);
                } else if (op == "+") {
                    int size = vals.size();
                    vals.push_back(vals[size - 1] + vals[size - 2]);
                } else {
                    vals.push_back(stoi(op));
                }
                ans += vals.back();
            }
        }
        return ans;
    }

    /**
     * 行星碰撞
     */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0 or s.empty() or s.back() < 0) {
                s.push_back(asteroids[i]);
            } else if (s.back() <= -asteroids[i]) {
                if (s.back() < -asteroids[i]) i--;
                s.pop_back();
            }
        }
        return s;
    }

    /**
     * 739.每日温度
     */
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> idxs;
        int len = T.size();
        vector<int> res(len ,0);
        for (int i = 0; i < len; i++) {
            while (!idxs.empty() and T[i] > T[idxs.top()]) {
                int idx = idxs.top(); idxs.pop();
                res[idx] = i - idx;
            }
            idxs.push(i);
        }
        return res;
    }

    /*
     * 189. 旋转数组
     * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
     */
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse1(nums, 0, n - k - 1);
        reverse1(nums, n - k, n - 1);
        reverse1(nums, 0, n - 1);
    }

    void reverse1(vector<int> &A, int l, int r) {
        while (l < r) {
            swap(A[l], A[r]);
            l++;
            r--;
        }
    }

    /**
     * 190. 颠倒二进制位
     * 颠倒给定的 32 位无符号整数的二进制位。
     */
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            if (n & (1 << i)) {
                ans += (1 << (31 - i));
            }
        }
        return ans;
    }

    /**
     * 191. 位1的个数
     * 编写一个函数，输入是一个无符号整数（以二进制串的形式），
     * 返回其二进制表达式中数字位数为 '1' 的个数（也被称为汉明重量）。
     */
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n) {
            n &= (n - 1);
            ans++;
        }
        return ans;
    }
};