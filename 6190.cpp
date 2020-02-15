#include <stdio.h>
inline bool is_Danjo(int num){
    while(num){
        if(num%10<(num/10)%10)
            return false;
        num/=10;
    }
    return true;
}
int main(int argc, char** argv)
{
    register int test_case, i, j, answer;
    int nums[1000];
    int T,N;
    scanf("%d",&T);
    for (test_case = 1; test_case <= T; test_case++){
        scanf("%d",&N);
        answer = -1;
        for(i=0;i<N;i++)
            scanf("%d",&nums[i]);
        
        for(i = 0; i<N-1; i++)
            for(j = i+1; j<N; j++) {
                if(answer > nums[i] * nums[j])
                    continue;
                answer = is_Danjo(nums[i]*nums[j]) ? nums[i]*nums[j] : answer;
            }
        printf("#%d %d\n",test_case,answer);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
