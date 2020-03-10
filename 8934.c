#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a, b) ((a<<3)+(a<<1)+(b))
#define MIN(a,b) ((a)>(b)) ? (b) : (a)
#define NO putchar_unlocked('N'),putchar_unlocked('O'),putchar_unlocked('\n');
#define YES putchar_unlocked('Y'),putchar_unlocked('E'),putchar_unlocked('S'),putchar_unlocked('\n');
#define IP(a,b,c,m) (((a)>=((m)+(2)))||((b)>=((m)+(2)))||((c)>=((m)+(2)))) ? (1) : (0)

int fRI() {
    int N = gc(), r = 0;
    for (; 0x30 > N || N > 0x3A; N = gc());
    do {
        r = ADD3(r, N & 0b1111); N = gc();
    } while (0x30 <= N && N <= 0x3A);
    return r;
}

void fWI(int tc) {
    int r = 0, c = 0;
    pc('#');
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) {r = ADD3(r, tc % 10); tc /= 10; }
    while (r) {pc(r % 10 +48); r /= 10;}
    while (c--) pc(0x30); pc(' ');
    return;
}

int main(void) {
    register int tc = 1, T = fRI(), m;
    int buf[3];
    while (T--) {
        memset(buf,0,sizeof(buf));
        while(m=gc(),'a'<=m) buf[m-'a']++;
        fWI(tc++);
        m = MIN(MIN(buf[0],buf[1]),buf[2]);
        if(IP(buf[0],buf[1],buf[2],m)) NO
            else YES
                }
    return 0;
}
