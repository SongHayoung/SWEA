#include <stdio.h>
int main(int argc, char** argv)
{
    //11:00
    int test_case;
    int T, N, B, E, num, c1, c2;
    int answer;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d %d %d",&N, &B, &E);
        answer = 0;
        c2 = B+E;
        for(int i=0;i<N;i++){
            c1 = B-E;
            scanf("%d",&num);
            for(;c1<=c2;c1++){
                if(c1%num==0) {
                    ++answer;
                    break;
                }
            }
        }
        printf("#%d %d\n",test_case,answer);
        
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
