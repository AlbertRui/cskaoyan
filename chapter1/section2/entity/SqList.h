/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:26:31
 * @LastEditTime : 2020-03-11 23:36:56
 * @Descripttion : define for SqList
 */
#ifndef SQLIST_H
#define SQLIST_H

#define MaxSize 50

typedef int ElemType;

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

#endif
