//
// Created by Administrator on 2018/10/7.
//
#include "common.h"
void reverse(SqList &L) {
    ElemType temp;
    for (int i = 0; i < L.length; ++i) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = temp;
    }
}

