/*
 * @Author       : Ryan Zhang
 * @Date         : 2021-01-16 10:35:55
 * @LastEditTime : 2021-01-16 12:20:11
 * @Descripttion : 
 */
#include <cstdio> 

/**
 * B1001.害死人不偿命的3n+1猜想
 */
int main1() {
    int n, step = 0;
    scanf("%d", &n);
    while (n != 1) {
        if (n % 2 == 0) n /= 2;
        else n = (3 * n + 1) / 2;
        step++;
    }
    printf("%d\n", step);
    return 0;
}

/**
 * B1011.A+B和C
 */
int main2() {
    int T, tcase = 1;
    scanf("%d", &T);
    while (T--) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        if (a + b > c) {
            printf("case #%d : true\n", tcase++);
        } else {
            printf("case #%d : false\n", tcase++);
        }
    }
    return 0;
}

/**
 * B1016.部分A+B
 */
int main3() {
    long long a, b, da, db;
    scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
    long long pa = 0, pb = 0;
    while (a) {
        if (a % 10 == da) {
            pa = pa * 10 + da;
            a /= 10;
        }
    }
    while (b) {
        if (b % 10 == db) {
            pb = pb * 10 + db;
            b /= 10;
        }
    }
    printf("%lld", pa + pb);
    return 0;
}

/**
 * B1026.程序运行时间
 */
int main4() {
    int c1, c2; 
    scanf("%d%d", &c1, &c2);
    int ans = c2 - c1;
    if (ans % 100 >= 50) {
        ans = ans / 100 + 1;
    } else {
        ans = ans / 100;
    }
    printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
    return 0;
}

/**
 * B1046.划拳
 */
int main4() {
    int n, failA = 0, failB = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a1, a2, b1, b2;
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        if (a1 + b1 == a2 and a1 + b1 != b2) {
            failB++;
        } else if (a1 + b1 == b2 and a1 + b1 != a1) {
            failA++;
        }
    }
    printf("%d %d\n", failA, failB);
}