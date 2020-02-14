#include <stdio.h>
#include <memory.h>
//5:00
int main(int argc, char** argv)
{
    int test_case;
    int arr[401];
    int T, N, M;
    int max;
    setbuf(stdout, NULL);
    scanf("%d", &T);
    for (test_case = 1; test_case <= T; ++test_case)
    {
        memset(arr,0,sizeof(arr));
        max = 0;
        scanf("%d %d",&N, &M);
        for(int i=1;i<=N;i++)
            for(int j=1;j<=M;j++) {
                arr[i + j]++;
                max = max > arr[i+j] ? max : arr[i+j];
            }
        printf("#%d ",test_case);
        for(int i=1;i<=400;i++){
            if(arr[i]==max)
                printf("%d ",i);
        }
        printf("\n");
        
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
