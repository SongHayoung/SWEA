#include <stdio.h>
#include <memory.h>
 
int main(int argc, char** argv)
{
    register int test_case, j;
    int T, N, K, V, C;
    int DP[1001];
    setbuf(stdout, NULL);
    scanf("%d",&T);
    for (test_case = 1; test_case <= T; ++test_case){
        scanf("%d %d",&N,&K);
        memset(DP,0,sizeof(DP));
        while(N--){
            scanf("%d %d",&V,&C);
            for(j = K; j>=V; j--)
                DP[j] = DP[j-V]+C > DP[j] ? DP[j-V] + C : DP[j];
        }
        printf("#%d %d\n",test_case,DP[K]);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
