#include <stdio.h>
#include <stdlib.h>
#define sINFO struct INFO
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
sINFO{
    int from;
    int to;
    //INFO(int _f, int _t) : from(_f), to(_t) {}
};

int comp(const void *A, const void *B) {
    sINFO *ptrA = (sINFO *) A;
    sINFO *ptrB = (sINFO *) B;
    if (ptrA->from == ptrB->from)
        return ptrA->to < ptrB->to ? -1 : 1;
    return ptrA->from < ptrB->from ? -1 : 1;
}

int fRI(){
    int ret = 0, N = gc();
    for(;'0'>N||N>'9';N=gc())
        ret^=0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);
        N=gc();
    }while('0'<=N&&N<='9');
    return ret;
}

void fWA(int tc, int ans){
    pc('#');
    int ret = 0, count = 0, N = tc;
    while(!(N%10))  {count++; N/=10;}
    while(N)    {ret = (ret<<3) + (ret<<1) + N%10; N/=10;}
    while(ret)  {pc(ret % 10 + '0'); ret/=10;}
    while(count--) pc('0');     pc(' ');
    N = ans; count = 0;
    while(!(N%10))  {count++; N/=10;}
    while(N)    {ret = (ret<<3) + (ret<<1) + N%10; N/=10;}
    while(ret)  {pc(ret % 10 + '0'); ret/=10;}
    while(count--) pc('0');     pc('\n');
    return ;
}
int main(int argc, char** argv){
    register int N,f,t,answer,idx,tc, T;
    sINFO info[200];
    T=fRI();
    for(tc=1;tc<=T;tc++) {
        answer = 0;
        N=fRI();
        for (idx = 0; idx < N; idx++) {
            f=fRI(); t=fRI();
            f = (f+1)>>1;
            t = (t+1)>>1;
            info[idx].from = f>t?t:f;
            info[idx].to = f>t?f:t;
        }
        qsort(info,N,sizeof(sINFO),comp);
        while(idx){
            f = 0;
            for(int i = 0; i < N; i++)
                if(info[i].from>f){
                    f = info[i].to;
                    info[i].from = -1;
                    --idx;
                }
            ++answer;
        }
        fWA(tc,answer);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
