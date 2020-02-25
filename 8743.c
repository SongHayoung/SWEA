#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int flag, ret, N;
long R, B;
void fastWriteANSWER(int tc){
    pc('#');    flag = 0;  ret = tc;
    while ((ret % 10) == 0) { flag++; ret /= 10; }
    ret = 0;
    while (tc != 0) { ret = (ret << 3) + (ret << 1) + tc % 10; tc /= 10; }
    while (ret != 0) { pc(ret % 10 + '0'); ret /= 10; }
    while (flag--) pc('0');
    pc(' ');
    N = gc(), R = B = 0;
    for(;'0'<=N&&N<='9';N=gc())
        R = (R<<3) + (R<<1) + (N & 0b1111);
    N = gc();
    for(;'0'<=N&&N<='9';N=gc())
        B = (B<<3) + (B<<1) + (N & 0b1111);
    switch(R-B){
        case -1:
        case 0:
        case 1:
            pc('D');    pc('H');
            break;
        default:
            pc('K');    pc('J');
            break;
    }
    pc('\n');
    return ;
}
int fastReadINT() {
    ret = 0, N = gc();
    do {
        ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
    } while ('0' <= N && N <= '9');
    return ret;
}
int main(int argc, char** argv){
    register int tc;
    int T = fastReadINT();
    for(tc = 1; tc <= T; tc++)
        fastWriteANSWER(tc);
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
