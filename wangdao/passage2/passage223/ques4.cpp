#include "common.h"
bool Del_s_t2(SqList &L, ElemType s, ElemType t) {
    int i, j;
    if(s >= t || L.length == 0) return false;
    for (i = 0; i < L.length && L.data[i] < s; i++);
    if(i >= L.length) return false;
    for (j = i; j < L.length && L.data[j] <= t; j++);
    while(j < L.length) L.data[i++] = L.data[j++];
    L.length = i + 1;
    return true;
}


