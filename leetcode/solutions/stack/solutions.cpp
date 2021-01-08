/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-08 21:47:01
 * @LastEditTime : 2021-01-08 22:06:12
 * @Descripttion : stack solutions from leetcode
 */
#include <stdint.h>
#include <stdlib.h>
#include <vector>

using namespace std;
class solutions {

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
};