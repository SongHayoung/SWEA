#include <stdio.h>
#define gc() getchar_unlocked()
int fastREADINT(){
    int N = gc(), ret = 0, flag = 1;
    for(;N<'0'||N>'9';N=gc())
        if(N=='-'){
            flag=-1;    N=gc(); break;
        }
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    return ret*flag;
}
int gcd(int N, int K){
    int ret = 1;
    for(int i=N;i>=1;i--){
        if(K%i==0){
            ret *= i;
            K /= i;
        }
    }
    return ret;
}
int main(int argc, char** argv){
    int tc, T, N, K;
    T=fastREADINT();
    for(tc=1;tc<=T;tc++){
        N=fastREADINT();
        K=fastREADINT();
        if(N>=K)
            printf("#%d %d\n",tc,K);
        else
            printf("#%d %d\n",tc,gcd(N,K));
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
