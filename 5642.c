#include <stdio.h>
int main(int argc, char** argv)
{
    register int test_case, i, answer, cmp;
    int T,N,num; 
    scanf("%d",&T);
    for (test_case = 1; test_case <= T; test_case++){
        scanf("%d",&N);
        answer = 0;
        cmp = 0;
        for(i=1;i<=N;i++) {
            scanf("%d", &num);
            if(cmp + num>=0) {
                cmp += num;
                answer = answer > cmp ? answer : cmp;
            }
            else
                cmp = 0;
        }
        printf("#%d %d\n",test_case,answer);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
