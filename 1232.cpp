#include <stdio.h>
#define gc() getchar_unlocked()
int v[1001][3], N;
int fRI() {
    int N = gc(), ret = 0;
    if (N == '-') return -1;
    if (N == '+') return -2;
    if (N == '*') return -3;
    if (N == '/') return -4;
    do {
        ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
    } while (48 <= N);
    return ret;
}
int inorderCC(int n) {
    switch (v[n][0]) {
        case -1: return inorderCC(v[n][1]) - inorderCC(v[n][2]);
        case -2: return inorderCC(v[n][1]) + inorderCC(v[n][2]);
        case -3: return inorderCC(v[n][1]) * inorderCC(v[n][2]);
        case -4: return inorderCC(v[n][1]) / inorderCC(v[n][2]);
        default: return v[n][0];
    }
}
int main(void) {
    int T = 1, tc = 0, i;
    while (T--) {
        N = fRI();
        for (i = 1; i <= N; ++i) {
            fRI();
            v[i][0] = fRI();
            if (v[i][0]<0) v[i][1] = fRI(), v[i][2] = fRI();
        }
        printf("#%d %d\n", ++tc, inorderCC(1));
    }
    return 0;
}
