#include <stdio.h>
using namespace std;
int main(int argc, char** argv)
{
    int test_case;
    int T;
    scanf("%d",&T);
    long long num;
    for(test_case = 1; test_case <= T; ++test_case){
        scanf("%lld",&num);
        printf("#%d %lld\n",test_case,(num/2)*(num/2));
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
