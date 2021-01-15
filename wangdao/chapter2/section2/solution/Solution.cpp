/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-13 19:29:07
 * @LastEditTime : 2020-03-15 14:15:29
 * @Descripttion : 
 */
#include <string.h>

#include "./Solution.h"

/**
 * @description: 第一题，删除顺序表中最小元素的值并返回,
 * 删除元素位置由表中最后一个元素填补,不存在则返回-1
 * @param list 待操作顺序表
 * @return: 删除的最小元素
 */
ElemType deleteMin(SqList& list) {
    if (list.length > 0) {
        ElemType* data = list.data;
        int minIndex = 0;
        for (int i = 1; i < list.length; i++) {
            if (data[i] < data[minIndex]) {
                minIndex = i;
            }
        }
        ElemType min = data[minIndex];
        data[minIndex] = data[list.length - 1];
        list.length--;
        return min;
    }
    return -1;
}

/**
 * @description: 第二题，将顺序表中的元素逆置，要求空间复杂度为O(1)
 * @param list 待逆置顺序表
 * @return: void
 */
void reverseSqList(SqList& list) {
    ElemType temp = 0;
    int left = 0, right = list.length - 1;
    ElemType* data = list.data;
    while (left < right) {
        temp = data[left];
        data[left] = data[right];
        data[right] = temp;
        left++;
        right--;
    }
}

/**
 * @description: 第三题，删除顺序表中所有值为x的元素，
 * 要求时间复杂度为O(n),空间复杂度为O(1);
 * @param list 待操作顺序表
 * @param x 元素x的值
 * @return: void
 */
void deleteAllValOfX(SqList& list, ElemType x) {
    int i = 0; 
    ElemType* data = list.data;
    for (int j = 0; j < list.length; j++) {
        if (data[j] != x) {
            data[i++] = data[j];
        }
    }
    list.length = i;
}

/**
 * @description: 第四题，删除有序表中元素值在(s, t)之间的元素
 * @param list 待操作有序表
 * @param (s,t) 元素范围
 * @return: void
 */
void deleteS2TSorted(SqList& list, ElemType s, ElemType t) {
    if (s >= t || list.length == 0) return;
    ElemType* data = list.data;
    int i, j;
    for (i = 0; i < list.length && data[i] < s; i++);
    if (i == list.length) return;
    for (j == i; j < list.length && data[j] <= t; j++);
    while (j < list.length) {
        data[i] = data[j];
        i++, j++;
    }
    list.length = i;
}

/**
 * @description: 第五题，删除线性表中元素值在[s, t]之间的元素
 * @param list 待操作线性表
 * @param [s, t] 元素范围
 * @return: void
 */
void deleteS2T(SqList& list, ElemType s, ElemType t) {
    if (s > t || list.length == 0) return;
    ElemType* data = list.data;
    int k = 0;
    for (int i = 0; i < list.length; i++) {
        if (data[i] >= s && data[i] <= t) {
            k++;
        } else {
            data[i - k] = data[i];
        }
    }
    list.length -= k;
}

/**
 * @description: 第六题，从有序顺序表中删除值重复的元素
 * @param list 待操作顺序表
 * @return: void
 */
void deleteSameValSorted(SqList& list) {
    if (list.length == 0) return;
    ElemType* data = list.data;
    int i, j;
    for (i = 0, j = 1; j < list.length; j++) {
        if (data[i] != data[j]) {
            data[++i] = data[j];
        }
    }
    list.length = i + 1;
}

/**
 * @description: 第七题，合并两个有序顺序表
 * @param a,b 待合并的两个有序表
 * @return: 合并生成的新的有序表
 */
SeqList merge(SeqList a, SeqList b) {
    SeqList newList;
    int newLength = a.length + b.length;
    if (newLength > newList.maxSize) return;
    newList.data = new ElemType[newLength];
    int i = 0, j = 0, k = 0;
    ElemType *dataA = a.data, *dataB = b.data, *newData = newList.data;
    while (i < a.length && j < b.length) {
        if (dataA[i] < dataB[j]) {
            newData[k++] = dataA[i++];
        } else {
            newData[k++] = dataB[j++];
        }
    }
    while (i < a.length) {
        newData[k++] = dataA[i++];
    }
    while (j < b.length) {
        newData[k++] = dataB[j++];
    }
    newList.length = k;
    return newList;
}

/**
 * @description: 第八题，交换两个线性表的位置
 * @param nums 给定的数组
 * @param m 前m个元素
 * @param n 后n个元素
 * @return: void
 */
void exchangeListLocate(int nums[], int m, int n, int arraySize) {
    reverse(nums, 0, m + n - 1, arraySize);
    reverse(nums, 0, n - 1, arraySize);
    reverse(nums, n, m + n - 1, arraySize);
}

/**
 * @description: 第九题，d在顺序表中查找元素，如果找到，则与后继交换
 * 如果没有找到则继续插入到顺序表中使有序表继续有序
 * @param nums 给定有序表
 * @param length 有序表的长度
 * @param x 待插入元素
 * @return: void
 */
void searchExchangeInsert(ElemType nums[], int length, ElemType x) {
    int low = 0, high = length - 1, mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == x) break;
        if (nums[mid] > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (nums[mid] == x && mid != length - 1) {
        int temp = nums[mid];
        nums[mid] = nums[mid + 1];
        nums[mid + 1] = temp;
    } else {
        int i = length;
        for (; i > mid + 1; i--) {
            nums[i] = nums[i - 1];
        }
        nums[i] = x;
    }
}

/**
 * @description: 第十题，数组循环左移p个元素 
 * @param nums 给定数组
 * @param n 数组长度
 * @param p 循环左移元素个数；
 * @return: 
 */
void moveLeft(int nums[], int n, int p) {
    reverse(nums, 0, p - 1, n);
    reverse(nums, p, n - 1, n);
    reverse(nums, 0, n - 1, n);
}

/**
 * @description: 第十一题，求两个升序序列的中位数
 * @param A 升序序列A
 * @param B 升序序列B
 * @param n 序列长度
 * @return: 中位数
 */
int searchMid(int A[], int B[], int n) {
    int leftA = 0, rightA = n - 1, midA, leftB = 0, rightB = n - 1, midB;
    while (leftA <= rightA || leftB <= rightB) {
        midA = leftA + (rightA - leftA) / 2;
        midB = leftB + (rightB - leftB) / 2;
        if (A[midA] == B[midB]) return A[midA];
        if (A[midA] < B[midB]) {
            if ((rightA - leftA) % 2 == 0) { //元素个数为奇数
                leftA = midA;
            } else {
                leftA = midA + 1;
            }
            rightB = midB;
        } else {
            if ((rightB - leftB) % 2 == 0) {
                leftB = midB;
            } else {
                leftB = midB + 1;
            }
            rightA = midA;
        }
    }
    if (A[midA] < B[midB]) return A[midA];
    return B[midB];
}

/**
 * @description: 第十二题，寻找数组中的主元素
 * @param nums 数组
 * @param n 数组长度 
 * @return: 主元素，没找到则返回-1
 */
int majority(int nums[], int n) {

    int res = nums[1], count = 1;
    
    for (int i = 1; i < n; i++) {
        if (res == nums[i]) {
            count++;
        } else {
            if (count > 0) {
                count--;
            } else {
                res = nums[i];
                count = 1;
            }
        }
    }

    for (int i = count = 0; i < n; i++) {
        if (nums[i] == res) {
            count++;
        }
    }
    
    if (count > n / 2) return res;
    return -1;

}

/**
 * @description: 第十三题，找出数组中未出现的最小正整数
 * @param nums 待查找数组
 * @param n 数组中元素个数
 * @return: 未出现的最小正整数
 */
int findMissMin(int nums[], int n) {
    int i = 0; 
    int* B = new int[n];
    memset(B, 0, n);
    for (; i < n; i++) {
        if (nums[i] > 0 && nums[i] <= n) {
            B[nums[i] - 1] = 1;
        }
    }
    for (i = 0; i < n; i++) {
        if (B[i] == 0) break;
    }
    return i + 1;
}

/*==========================private methods===========================*/

/**
 * @description: 翻转left-right之间的数组元素
 */
void reverse(int nums[], int left, int right, int arraySize) {
    if (left < 0 || right >= arraySize || left >= right) return;
    int temp = 0;
    while (left < right) {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}