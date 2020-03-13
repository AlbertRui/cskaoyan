/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:11:58
 * @LastEditTime : 2020-03-13 01:21:46
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
 * @description: 删除第i个元素，i从1开始
 * @param list 待删除的list
 * @param i 待删除元素的位序
 * @return: 成功返回true，失败返回false
 */
bool listDelete(SqList& list, int i); 

/**
 * @description: 查找元素e，并返回其位序
 * @param sqList 待查找顺序表
 * @param e 待查找元素
 * @return: 查找成功返回位序，失败返回0
 */
int locateElem(SqList sqList, ElemType e);

/**
 * @description: 打印SqList数组元素 
 * @param {type} 
 * @return: 
 */
void printSqList(SqList list);

#endif