//#pragma GCC optimize ("O3")
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
#include <stdio.h>
__int128 fRINT128(){
    register __int128 ret = 0, N = gc();
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while('0'<=N&&N<='9');
    return ret;
}
void fWINT128(int tc, __int128 n){
    pc('#');
    switch(tc){
        case 1: pc('1'); break;
        case 2: pc('2'); break;
        case 3: pc('3'); break;
        case 4: pc('4'); break;
        case 5: pc('5'); break;
        case 6: pc('6'); break;
        case 7: pc('7'); break;
        case 8: pc('8'); break;
        case 9: pc('9'); break;
        case 10: pc('1'); pc('0'); break;
        default: pc('1'); pc('1'); break;
    }
    pc(' ');
    char buf[30];
    register int count = 0,len = 0;
    while(!(n%10))  {count++; n/=10;}
    while(n) {buf[len++] = (n%10)|0b110000; n/=10;}
    while(len)  pc(buf[--len]);
    while(count--) pc('0');
    pc('\n');
}

void fastPow(int tc){
    register int N = fRINT128(),p;
    register __int128 ret = 0,n,r;
    while(N--) {
        n = fRINT128(),r=1;
        p = n % 10;
        n /= 10;
        while (p) {
            if (p & 1)
                r *= n;
            n *= n;
            p >>= 1;
        }
        ret += r;
    }
    fWINT128(tc,ret);
}
int main(int argc, char** argv) {
    register int tc = 1,T;
    T=fRINT128();
    for(;tc<=T;) fastPow(tc++);
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
