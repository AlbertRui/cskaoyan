/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:26:31
 * @LastEditTime : 2020-03-12 23:25:54
 * @Descripttion : define for SqList
 */
#ifndef SQLIST_H
#define SQLIST_H

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length = 0;
} SqList;

#endif
