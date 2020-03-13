/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-13 19:29:07
 * @LastEditTime : 2020-03-13 22:27:36
 * @Descripttion : 
 */
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