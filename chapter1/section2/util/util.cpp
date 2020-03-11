/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:11:58
 * @LastEditTime : 2020-03-12 00:05:07
 * @Descripttion : util implements for section2
 */
#include<stdio.h>
#include<stdlib.h>

#include "util.h"
/**
 * 初始化静态顺序表
 */
void initSqList(SqList& list, int size, int elemRange) {
    if (size > MaxSize || size < 0) {
        printf("error, the size %d is illegal, it's must litle than %d!!!", size, MaxSize);
        return;
    }
    ElemType* data = list.data;
    for (int i = 0; i < size; i++) {
        data[i] = rand() % elemRange;
    }
} 

/**
 * 将元素e插入到顺序表的第i个位置
 */
bool listInsert(SqList& l, int i, ElemType e) {
    int length = l.length;
    if (i < 1 || i > length || length == MaxSize)
        return false;
    ElemType* data = l.data;
    for (int j = length; j >= i; j--) {
        data[j] = data[j - 1];
    }
    data[i - 1] = e;
    l.length++;
    return true;
}

/**
 * 打印SqList数组元素 
 */
void printSqList(SqList list) {
    printf("now, the list length is : %d", list.length);
    ElemType* data = list.data;
    for (int i = 0; i < list.length; i++) {
        printf("%d\t", data[i]);
    }
}