/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:11:58
 * @LastEditTime : 2020-03-12 23:35:40
 * @Descripttion : util define for section2
 */
#ifndef UTIL_H
#define UTIL_H

#include "../entity/SqList.h"
#include "../entity/SeqList.h"

/**
 * @description: 初始化静态顺序表
 * @param {type} 
 * @return: 
 */
void initSqList(SqList& list, int size, int elemRange); 

/**
 * @description: 顺序表清零
 * @param {type} 
 * @return: 
 */
void clearSqList(SqList& list);

/**
 * @description: 将元素e插入到顺序表的第i个位置
 * @param {type} 
 * @return: 
 */
bool listInsert(SqList& l, int i, ElemType e);

/**
 * @description: 打印SqList数组元素 
 * @param {type} 
 * @return: 
 */
void printSqList(SqList list);

#endif