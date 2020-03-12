/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:58:22
 * @LastEditTime : 2020-03-13 00:52:36
 * @Descripttion : main method for section2
 */
#include <iostream>

#include "./util/Util.h"

using namespace std;

int main() {
    SqList sqList;
    initSqList(sqList, 10, 100);
    // clearSqList(sqList);
    listInsert(sqList, 2, 10);
    listDelete(sqList, 2);
    return 0;
}