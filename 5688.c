#include <stdio.h>

int main(int argc, char** argv)
{
    register int test_case;
    register long long answer;
    int T;
    long long N;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case){
        scanf("%ld",&N);
        for(answer = 1; answer <= N; answer++){
            if(answer*answer*answer == N){
                printf("#%d %ld\n",test_case ,answer);
                break;
            }
            else if(answer*answer*answer > N) {
                printf("#%d -1\n", test_case);
                break;
            }
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
