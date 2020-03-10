#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b) ((a<<3)+(a<<1)+(b))
#define REP(i,a,b) for(i = a; i < b; i++)
char buf[35];
int fRI(){
    int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = ADD3(r,N&0b1111); N = gc();
    }while(0x30<=N&&N<=0x3A);
    return r;
}

void fWL(long tc) {
    if(!tc) {pc(0x30); return;}
    long r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = ADD3(r,tc%10); tc /= 10; }
    while (r) { pc(r % 10 + 48); r /= 10; }
    while (c--) pc(0x30);
    return;
}
int compare(const void* A, const void* B){
    return *(long*)A > *(long*)B ? -1 : 1;
}
long getData(char *_buf, int N){
    long ret = 0, pow = 1;
    while(N--){
        switch(*(_buf+N)){
            case 'A' : ret = pow*10 + ret; break;
            case 'B' : ret = pow*11 + ret; break;
            case 'C' : ret = pow*12 + ret; break;
            case 'D' : ret = pow*13 + ret; break;
            case 'E' : ret = pow*14 + ret; break;
            case 'F' : ret = pow*15 + ret; break;
            default  : ret = pow*(*(_buf+N)&0b1111) + ret; break;
        }
        pow *= 16;
    }
    return ret;
}
int main(void){
    register int tc = 1, T=fRI(), N, K, datalen, i;
    long DATA[28];
    while(T--){
        N=fRI(); K=fRI(); datalen = 0;
        REP(i,0,N) buf[i] = gc();
        REP(i,0,N>>2) buf[N+i] = buf[i];
        REP(i,0,N)  DATA[datalen++] = getData((buf+i),N>>2);
        qsort(DATA,datalen,sizeof(long),compare);
        pc(0x23); fWL(tc++); pc(0x20);
        if(!(K^1)) fWL(DATA[0]);
        else{
            N = 2;
            REP(i,1,datalen){
                if(!(N^K)) {fWL(DATA[i]); break;}
                if(DATA[i]^DATA[i-1]) N++;
            }
        }pc('\n');
    }
    return 0;
}
