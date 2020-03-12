/*
 * @Author       : Ryan Zhang
 * @Date         : 2020-03-11 21:58:22
 * @LastEditTime : 2020-03-12 23:57:18
 * @Descripttion : main method for section2
 */
#include <iostream>

#include "./util/Util.h"

using namespace std;

int main() {
    SqList sqList;
    initSqList(sqList, 10, 100);
    printSqList(sqList);
    clearSqList(sqList);
    printSqList(sqList);
    return 0;
}