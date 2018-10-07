//
// Created by Administrator on 2018/10/7.
//
#include "common.h"
void del_x_1(SqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i)
        if(L.data[i] != x) L.data[k++] = L.data[i];
    L.length = k;
}
void del_x_2(SqList &L, ElemType x) {
    int k = 0, i;
    while (i < L.length) {
        if (L.data[i] == k) k++;
        else L.data[i - k] = L.data[i];
        i ++;
    }
    L.length = L.length - k;
}

