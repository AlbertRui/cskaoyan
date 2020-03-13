/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-13 19:28:48
 * @LastEditTime : 2020-03-13 22:06:22
 * @Descripttion : cskaoyan codes for section2.2(API)
 */
#include "../entity/SqList.h"
#include "../entity/SeqList.h"

/**
 * @description: 第一题，删除顺序表中最小元素的值并返回
 * @param list 待操作顺序表
 * @return: 删除的最小元素
 */
ElemType deleteMin(SqList& list);

/**
 * @description: 第二题，将顺序表中的元素逆置，要求空间复杂度为O(1)
 * @param list 待逆置顺序表
 * @return: void
 */
void reverseSqList(SqList& list);

/**
 * @description: 第三题，删除顺序表中所有值为x的元素，
 * 要求时间复杂度为O(n),空间复杂度为O(1);
 * @param list 待操作顺序表
 * @param x 元素x的值
 * @return: void
 */
void deleteAllValOfX(SqList& list, ElemType x);

/**
 * @description: 第四题，删除有序表中元素值在(s, t)之间的元素
 * @param list 待操作有序表
 * @param (s,t) 元素范围
 * @return: void
 */
void deleteS2TSorted(SqList& list, ElemType s, ElemType t);

/**
 * @description: 第五题，删除线性表中元素值在[s, t]之间的元素
 * @param list 待操作有序表
 * @param [s, t] 元素范围
 * @return: void
 */
void deleteS2T(SqList& list, ElemType s, ElemType t);

/**
 * @description: 第六题，从有序顺序表中删除值重复的元素
 * @param list 待操作顺序表
 * @return: void
 */
void deleteSameValSorted(SqList& list);

/**
 * @description: 第七题，合并两个有序顺序表
 * @param a,b 待合并的两个有序表
 * @return: 合并生成的新的有序表
 */
SqList merge(SqList a, SqList b);