#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b) ((a<<3)+(a<<1)+(b))
#define ADD4(a,b,c,d) ((a)+(b)*(c)+(d))
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

void fWL(long long tc) {
    if(!tc) {pc(0x30); return;}
    long long r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = ADD3(r,tc%10); tc /= 10; }
    while (r) { pc(r % 10 + 48); r /= 10; }
    while (c--) pc(0x30);
    return;
}
int compare(const void* A, const void* B){
    return *(long long*)A > *(long long*)B ? -1 : 1;
}
long long getData(char _buf[7], int N){
    long long ret = 0, pow = 1;
    while(N--){
        switch(_buf[N]){
            case 'A' : ret = pow*10 + ret; break;
            case 'B' : ret = pow*11 + ret; break;
            case 'C' : ret = pow*12 + ret; break;
            case 'D' : ret = pow*13 + ret; break;
            case 'E' : ret = pow*14 + ret; break;
            case 'F' : ret = pow*15 + ret; break;
            default  : ret = pow*(_buf[N]&0b1111) + ret; break;
        }
        pow *= 16;
    }
    return ret;
}
int main(void){
    register int tc = 1, T=fRI(), N, K, datalen, _K, i, j, k;
    long long DATA[28];
    char _buf[7];
    while(T--){
        N=fRI(); K=fRI();
        REP(i,0,N) buf[i] = gc();
        REP(i,0,N>>2) buf[N+i] = buf[i];
        datalen = 0;
        REP(i,0,N>>2)
        REP(j,0,4){
            REP(k,0,N>>2) _buf[k] = buf[ADD4(i,j,N>>2,k)];
            DATA[datalen++] = getData(_buf,N>>2);
        }
        qsort(DATA,datalen,sizeof(long long),compare);
        pc(0x23); fWL(tc++); pc(0x20);
        if(!(K^1)) fWL(DATA[0]);
        else{
            _K = 2;
            REP(i,1,datalen){
                if(!(_K^K)) {fWL(DATA[i]); break;}
                if(DATA[i]^DATA[i-1]) _K++;
            }
        }pc('\n');
    }
    return 0;
}
