#include <stdio.h>
int main(int argc, char** argv)
{
    int test_case, T;
    long long n;
    scanf("%d",&T);
    for(test_case = 1; test_case <= T; ++test_case){
        scanf("%ld",&n);
        printf("#%d %ld %ld\n",test_case,(n-1)*(n-1)<<1^1,(n*n<<1)-1);
    }
    return 0;
}
