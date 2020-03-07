#include <cstdio>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b,c) ((a)+(b)+(c))
using namespace std;

inline int fRI(){
    int N=gc(), ret = 0;
    for(;N<'0'||N>'9';N=gc());
    do{
        ret = ADD3((ret<<3),(ret<<1),(N&0b1111)); N = gc();
    }while('0'<=N&&N<='9');
    return ret-1;
}
inline void fWA(int tc) {
    int r = 0, c = 0;
    pc(0x23);
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = ADD3((r << 3), (r << 1), tc % 10); tc /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30); pc(0x20);
}

int main(int argc, char **argv) {
    register int tc = 1, len, idx;
    char buf[100];
    for (; tc <= 10;) {
        len = fRI(); idx = 1;
        buf[0] = gc();
        while(len--){
            buf[idx] = gc();
            if(!(buf[idx]^buf[idx-1])) idx -=2;
            idx++;
        }
        fWA(tc++);
        len = 0;
        while(len^idx) pc(buf[len++]);
        pc(0x0A);
    }
}
