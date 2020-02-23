#include <stdio.h>
#include <memory.h>
#define MAXN 32767
int DP[MAXN+1];
int main(int argc, char** argv){
    register int i, j, k, l;
    int test_case;
    int T, N;
    scanf("%d",&T);
    memset(DP,0,sizeof(DP));
    for(i=1;i<=181; i++){
        for(j = 0; j<=i && (MAXN-i*i) >= j*j; j++)
            for(k = 0; k<=j && (MAXN-i*i-j*j) >= k*k; k++)
                for(l = 0; l <= k && (MAXN-i*i-j*j-k*k) >= l*l; l++)
                    DP[i*i+j*j+k*k+l*l]++;
    }
    for(test_case = 1; test_case <= T; ++test_case){
        scanf("%d",&N);
        printf("#%d %d\n",test_case,DP[N]);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
