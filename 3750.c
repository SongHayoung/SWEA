#include <stdio.h>

int main(int argc, char** argv)
{
    register int test_case, answer;
    int T;
    char c;
    scanf("%d",&T);
    getchar();
    for (test_case = 1; test_case <= T; ++test_case){
        c = '0';
        answer = 0;
        while('0'<=c&&c<='9') {
            answer += c - 48;
            answer = answer >= 10 ? answer / 10 + answer % 10 : answer;
            c = getchar();
        }
        printf("#%d %d\n",test_case,answer);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
