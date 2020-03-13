#include <stdio.h>
#include <stdlib.h>
#define gc() getchar_unlocked()
int cus[101];
int fRI(){
    register int N = gc(), ret = 0;
    for(;N<'0'||N>'9';N=gc()) ;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    return ret;
}
int compare(const void * A, const void * B){
    return *(int*)A > *(int*) B ? 1 : -1;
}
int main(int argc, char** argv){
    register int tc = 1, T = fRI(), N, M, K, i, has, idx, flag;
    while(T--){
        N = fRI(); M = fRI(); K = fRI();
        for(i = 0; i < N; i++)
            cus[i] = fRI();
        qsort(cus,N,sizeof(int),compare);
        has = idx = flag = 0;
        printf("#%d ", tc++);
        if(!cus[0]) printf("Impossible\n");
        else {
            for (i = 1; i <= cus[N - 1]; i++) {
                if (!(i % M)) has += K;
                while (!(cus[idx]^i)) {
                    has ? has-- : flag = 1;
                    idx++;
                }
                if (flag)
                    break;
            }
            flag ?  printf("Impossible\n") : printf("Possible\n");
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
