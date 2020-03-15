/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-13 19:28:48
 * @LastEditTime : 2020-03-15 14:15:43
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

/**
 * @description: 第八题，交换两个线性表的位置
 * @param nums 给定的数组
 * @param m 前m个元素
 * @param n 后n - m个元素
 * @return: void
 */
void exchangeListLocate(int nums[], int m, int n);

/**
 * @description: 第九题，在顺序表中查找元素，如果找到，则与后继交换
 * 如果没有找到则继续插入到顺序表中使有序表继续有序
 * @param nums 给定有序表
 * @param length 有序表的长度
 * @param x 待插入元素
 * @return: void
 */
void searchExchangeInsert(ElemType nums[], int length, ElemType x);

/**
 * @description: 第十题，数组循环左移p个元素 
 * @param nums 给定数组
 * @param n 数组长度
 * @param p 循环左移元素个数；
 * @return: 
 */
void moveLeft(int nums[], int n, int p);

/**
 * @description: 第十一题，求两个升序序列的中位数
 * @param A 升序序列A
 * @param B 升序序列B
 * @param n 序列长度
 * @return: 中位数
 */
int searchMid(int A[], int B[], int n);

/**
 * @description: 第十二题，寻找数组中的主元素
 * @param nums 数组
 * @param n 数组长度 
 * @return: 主元素，没找到则返回-1
 */
int majority(int nums[], int n);

/**
 * @description: 第十三题，找出数组中未出现的最小正整数
 * @param nums 待查找数组
 * @param n 数组中元素个数
 * @return: 未出现的最小正整数
 */
int findMissMin(int nums[], int n);