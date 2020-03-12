/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:11:58
 * @LastEditTime : 2020-03-13 00:02:43
 * @Descripttion : util implements for section2
 */
#include<stdio.h>
#include<stdlib.h>

#include "./Util.h"

/**
 * @description: 静态顺序表初始化
 * @param list 顺序表
 * @param size 顺序表长度
 * @param elemRange 顺序表元素范围
 * @return: void
 */
void initSqList(SqList& list, int size, int elemRange) {
    printf("begining initial sqList......\n");
    if (size > MaxSize || size < 0) {
        printf("error, the size %d is illegal, it's must litle than %d!!!\n", size, MaxSize);
        return;
    }
    ElemType* data = list.data;
    for (int i = 0; i < size; i++) {
        data[i] = rand() % elemRange;
    }
    list.length = size;
    printf("ending initial sqList......\n");
} 

/**
 * @description: 顺序表清零
 * @param {type} 
 * @return: 
 */
void clearSqList(SqList& list) {
    printf("begin clear sqList......\n");
    list.length = 0;
    printf("end clear sqList......\n");
}

/**
 * @description: 将元素e插入到顺序表的第i个位置
 * @param l 要操作的顺序表
 * @param i 插入位置
 * @param e 插入元素
 * @return: 是否插入成功
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
 * @description: 打印顺序表的元素
 * @param list 顺序表 
 * @return: void
 */
void printSqList(SqList list) {
    printf("now, the list length is : %d\n", list.length);
    ElemType* data = list.data;
    for (int i = 0; i < list.length; i++) {
        printf("%d\t", data[i]);
    }
    printf("\n");
}