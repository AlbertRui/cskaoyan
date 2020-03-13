/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:35:30
 * @LastEditTime : 2020-03-11 23:37:06
 * @Descripttion : define for SeqList
 */
#ifndef SEQLIST_H
#define SEQLIST_H

#define InitSize 100

typedef int ElemType;

typedef struct {
    ElemType* data;
    int length, maxSize;
} SeqList;

#endif