/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:11:58
 * @LastEditTime : 2020-03-13 01:21:05
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
    printSqList(list);
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
    printf("begining insert %d for %dth.\n", e, i);
    int length = l.length;
    if (i < 1 || i > length || length == MaxSize)
        return false;
    ElemType* data = l.data;
    for (int j = length; j >= i; j--) {
        data[j] = data[j - 1];
    }
    data[i - 1] = e;
    l.length++;
    printf("ending listInsert......\n");
    printSqList(l);
    return true;
}

/**
 * @description: 删除第i个元素，i从1开始
 * @param list 待删除的list
 * @param i 待删除元素的位序
 * @return: 成功返回true，失败返回false
 */
bool listDelete(SqList& list, int i) {
    printf("begining delete list......");
    if (i < 1 || i > list.length) {
        printf("error in delete element!\n");
        return false;
    }
    ElemType* data = list.data;
    ElemType e = data[i - 1];
    for (int j = i; j < list.length; j++) {
        data[j - 1] = data[j]; 
    }
    list.length--;
    printf("success delete the %dth element : %d\n", i, e);
    printSqList(list);
    return true;
}

/**
 * @description: 查找元素e，并返回其位序
 * @param sqList 待查找顺序表
 * @param e 待查找元素
 * @return: 查找成功返回位序，失败返回0
 */
int locateElem(SqList sqList, ElemType e) {
    for (int i = 0; i < sqList.length; i++) {
        if (sqList.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
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
        if (i != 0 && i % 10 == 0) {
            printf("\n");
        }
        printf("%d\t", data[i]);
    }
    printf("\nending print list\n");
}