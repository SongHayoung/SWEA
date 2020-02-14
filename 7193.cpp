#include <stdio.h>
int main(int argc, char** argv)
{
    int test_case;
    int T, N;
    long answer;
    char c;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d",&N);
        getchar();
        c='0';
        switch (N) {
            case 2:
                while('0'<=c&&c<='9'){
                    c = getchar();
                }
                printf("#%d 0\n",test_case);
                break;
            default:
                answer = 0;
                do{
                    answer += c-48;
                    c = getchar();
                }while('0'<=c&&c<='9');
                printf("#%d %d\n",test_case,answer%(N-1));
                break;
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
