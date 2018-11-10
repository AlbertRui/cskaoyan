#include "common.h"
bool Delete_Same(SqList& L) {
    if(L.length == 0) return false;
    int i, j;
    for (int i = 0, j = 1; j < L.length; ++i)
        if(L.data[i] != L.data[j]) L.data[++i] = L.data[j];
    L.length = i + 1;
    return true;
}