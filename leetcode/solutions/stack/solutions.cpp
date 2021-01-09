/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-08 21:47:01
 * @LastEditTime : 2021-01-09 20:43:24
 * @Descripttion : stack solutions from leetcode
 */
#include <stdint.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class solutions {

    /**
     * 20. 有效的括号
     * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
     * 有效字符串需满足：
     * 左括号必须用相同类型的右括号闭合。
     * 左括号必须以正确的顺序闭合。
     * 注意空字符串可被认为是有效字符串。
     */
    bool isValid(string s) {
        stack<char> stk;
        for (char& ch : s) {
            switch (ch) {
                case '{' : stk.push('}');
                case '[' : stk.push(']');
                case '(' : stk.push(')'); 
                default : 
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
    int trap(vector<int>& height) {
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
     * 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
     * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。更多信息请参阅：Linux / Unix中的绝对路径 vs 相对路径
     * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。最后一个目录名（如果存在）不能以 / 结尾。
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
     * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
     * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
     */
    int largestRectangleArea(vector<int>& heights) {
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
            maxArea = max(maxArea, heights[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
        } 
        
        return maxArea;
    }

    /**
     * 85. 最大矩形
     * 给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，
     * 找出只包含 1 的最大矩形，并返回其面积。
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n], right[n], height[n];
        fill_n(left, n, 0); fill_n(right, n, n - 1); fill_n(height, n, 0);
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

    /*
     * 189. 旋转数组
     * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
     */
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }

    void reverse(vector<int> &A, int l, int r) {
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