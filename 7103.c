#include <stdio.h>
#define MAXN 32767
int DP[MAXN+1];
int scan_d() {
    int ip=getchar_unlocked(),ret=0,flag=1;
    for(;ip<'0'||ip>'9';ip=getchar_unlocked())
        if(ip=='-'){
            flag=-1;
            ip=getchar_unlocked();
            break;
        }
    for(;ip>='0'&&ip<='9';ip=getchar_unlocked())
        ret=ret*10+ip-'0';
    return flag*ret;
}
int main(int argc, char** argv){
    register int i, j, k, l,plus,minus;
    for(i=1;i<=181; i++){
        minus = MAXN-i*i;
        for(j = 0; j<=i && minus >= j*j; j++)
            for(k = 0; k<=j && (minus-j*j)>= k*k; k++) {
                plus = j*j + k*k;
                for (l = 0; l <= k && (minus - plus) >= l * l; l++)
                    DP[i * i + plus + l * l]++;
            }
    }
    k = scan_d();
    for(i = 1; i <= k; ++i){
        j = scan_d();
        printf("#%d %d\n",i,DP[j]);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
