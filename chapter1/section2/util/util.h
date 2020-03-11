/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:11:58
 * @LastEditTime : 2020-03-11 23:37:51
 * @Descripttion : util define for section2
 */
#ifndef UTIL_H
#define UTIL_H

#include "SqList.h"
#include "SeqList.h"

/**
 * 初始化静态顺序表
 */
void initSqList(SqList& list, int size, int elemRange); 

/**
 * 将元素e插入到顺序表的第i个位置
 */
bool listInsert(SqList& l, int i, ElemType e);

/**
 * 打印SqList数组元素 
 */
void printSqList(SqList list);

#endif