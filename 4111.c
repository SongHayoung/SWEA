#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int comp(const void *a, const void *b) {
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia-*ib;
}
int fRI(){
    int ret = 0, N = gc(),flag = 1;
    for(;'0'>N||N>'9';N = gc())
        if(N=='-'){
            flag = -1; N = gc(); break;
        }
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while('0'<=N&&N<='9');
    return ret * flag;
}
void fWI(int N){
    int r = 0, c = 0;
    while(!(N%10))  {c++; N/=10;}
    while(N)        {r = (r<<3) + (r<<1) + N%10; N/=10;}
    while(r)        {pc(r%10 + 48); r/=10;}
    while(c--)      {pc(48);}
    return ;
}
int main(int argc, char** argv){
    int N,tc,T,K,cameras[10000],dis[9999],len,answer;
    register int i;
    T=fRI();
    for(tc=1;tc<=T;tc++) {
        answer = len = 0;
        N = fRI(); K = fRI();
        for(i=0;i<N;i++)
            cameras[i] = fRI();
        pc(35);    fWI(tc);    pc(32);
        if(N<=K){
            pc(48); pc(10);
            continue;
        }
        qsort(cameras,N,sizeof(int),comp);
        for(i =1;i<N;i++)
            if(cameras[i]!=cameras[i-1])
                dis[len++] = cameras[i] - cameras[i - 1];
        qsort(dis,len,sizeof(int),comp);
        for(i = 0; i < len-K+1; i++)
            answer += dis[i];
        fWI(answer);   pc(10);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
