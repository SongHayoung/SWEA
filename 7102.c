#include <stdio.h>
//5:00
int main(int argc, char** argv)
{
    int test_case;
    int T, N, M, max, i;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d",&N, &M);
        printf("#%d ",test_case);
        max = N>M ? N+1 : M+1;
        for(i=N > M ? M+1 : N+1 ;i<= max ;i++){
            printf("%d ",i);
        }
        printf("\n");

    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
