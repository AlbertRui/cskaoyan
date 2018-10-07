//
// Created by Administrator on 2018/10/7.
//
#include "common.h"
void del_x_l(SqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i)
        if(L.data[i] != x) L.data[k++] = L.data[i];
    L.length = k;
}

