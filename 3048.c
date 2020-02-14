#include <stdio.h>
int main(int argc, char** argv)
{
    register int test_case;
    int T;
    long N;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case){
        scanf("%ld",&N);
        printf("#%d %ld %ld %ld\n",test_case ,N*(N+1)>>1 ,N*N,(N+1)*N);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
