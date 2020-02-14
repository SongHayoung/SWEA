#include <stdio.h>
#include <memory.h>

int main(int argc, char** argv)
{
    register int test_case;
    int T, N, K, i ,j;
    int V[100], C[100];
    int DP[1001];
    setbuf(stdout, NULL);
    scanf("%d",&T);
    for (test_case = 1; test_case <= T; ++test_case){
        scanf("%d %d",&N,&K);
        for(int i=0;i<N;i++)
            scanf("%d %d",&V[i],&C[i]);
        memset(DP,0,sizeof(DP));
        for(i=0;i<N;i++)
            for(j=K;j>=V[i];j--)
                DP[j] = DP[j-V[i]]+C[i] > DP[j] ? DP[j-V[i]] + C[i] : DP[j];
        printf("#%d %d\n",test_case,DP[K]);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
