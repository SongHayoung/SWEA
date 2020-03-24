#include <stdio.h>
#define gc() getchar_unlocked()
long long fRLL(){
    long long N=gc(),ret = 0;
    for(;N<48||N>57;N=gc());
    do{
        ret = (ret<<3) + (ret<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return ret;
}
int main(void){
    register long long T = fRLL(), N, tc = 0;
    while(T--){
        N = fRLL();
        int flag = 0;
        while(N>1){
            if(!(N&1)) N >>=1;
            else if(!((++N)&1)) {flag = 1; break;}
            else N *= 3;
        }
        printf("#%d ",++tc);
        flag ? printf("NO\n") : printf("YES\n");
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
