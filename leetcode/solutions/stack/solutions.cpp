/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-08 21:47:01
 * @LastEditTime : 2021-01-08 21:53:53
 * @Descripttion : stack solutions from leetcode
 */
#include<stdlib.h>
#include<vector>

using namespace std;
class solutions {

    /*
     * 189. 旋转数组
     * 给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
     */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums, 0, n - k - 1);
        reverse(nums, n - k, n - 1);
        reverse(nums, 0, n - 1);
    }
    
    void reverse(vector<int>& A, int l, int r) {
        while(l < r) {
            swap(A[l], A[r]);
            l++;
            r--;
        }
    }
};