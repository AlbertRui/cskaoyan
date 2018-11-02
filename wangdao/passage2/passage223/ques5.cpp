#include "common.h"
bool Del_s_t(SqList &L, ElemType s, ElemType t) {
    int i, k = 0;
    if(s >= t || L.length == 0) return false;
    for (i = 0; i < L.length; i++) {
        if(L.data[i] >= s && L.data[i] <= t) k++;
        else L.data[i - k] = L.data[i];
    }
    L.length -= k;
    return true;
}