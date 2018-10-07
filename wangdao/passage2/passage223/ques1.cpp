//
// Created by Administrator on 2018/10/7.
//
#include "common.h"
//#define MaxSize 50
//typedef int ElemType;
//typedef struct {
//    ElemType data[MaxSize];
//    int length;
//}SqList;
bool Del_Min(SqList &L, ElemType &value) {
    if (L.length == 0) return false;
    value = L.data[0];
    int pos = 0;
    for (int i = 1; i < L.length; i++) {
        if(L.data[i] < value) {
            value = L.data[i];
            pos = i;
        }
    }
    L.data[pos] = L.data[L.length - 1];
    L.length --;
    return true;
}

