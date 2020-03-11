#include <stdio.h>
#include <stdlib.h>

#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)

int A[20] = {0}, K, answer = 0, N;
inline int fRI(){
    int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3)+(r<<1)+(N&0b1111); N = gc();
    }while(0x30<=N&&N<=0x3A);
    return r;
}

inline void fWI(int tc) {
    int r = 0, c = 0;
    pc('#');
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = (r<<3)+(r<<1)+tc%10; tc /= 10; }
    while (r) { pc(r % 10 + 48); r /= 10; }
    while (c--) pc(0x30); pc(32);
    c = 0;
    if(!answer) {pc(48); pc(0x0A); return ;}
    while (!(answer % 10)) { c++; answer /= 10; }
    while (answer) { r = (r<<3)+(r<<1)+answer%10; answer /= 10; }
    while (r) { pc(r % 10 + 48); r /= 10; }
    while (c--) pc(0x30); pc(0x0A);
    return;
}
inline void DFS(int cur,int start){
    if(cur^K){
        for(int i = start; i < N; i++){
            if(cur+A[i]<=K) DFS(cur+A[i],i+1);
            else return ;
        }
    }
    else answer++;
}
inline int compare(const void *A, const void *B){
    return *(int*) A > *(int*) B ? 1 : -1;
}
int main(int argc, char** argv){
    register int tc = 1, T = fRI();
    for(;tc<=T;){
        N = fRI(); K = fRI();
        for(register int i = 0 ; i < N; i++)
            A[i] = fRI();
        qsort(A,N,sizeof(int),compare);
        DFS(0,0);
        fWI(tc++);
    }
}
