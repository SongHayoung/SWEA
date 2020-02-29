#include <stdio.h>
#include <memory.h>
#define MOD 1000000007
int N,M;
int choose[100];
long answer = 0;
long pactorial[101];
long DP[100][100][2];
long pow(long x,int n){
    long ret = 1;
    while(n){
        if(n&1)
            ret = (ret*x)%MOD;
        x = (x*x)%MOD;
        n>>=1;
    }
    return ret;
}
void DFS(int depth, int need){
    if(!((N-depth)^need)) answer = (answer + pactorial[need])%MOD;
    else if(!(need)) answer = (answer + pow(M,N-depth))%MOD;
    else {
        for (int i = 0; i < M; i++) {
            if (choose[i]) {
                if (DP[depth][need][0] == -1) {
                    DP[depth][need][0] = answer; choose[i] = 0;
                    DFS(depth + 1, need - 1);
                    DP[depth][need][0] = (answer - DP[depth][need][0] + MOD) % MOD; choose[i] = 1;
                }
                else answer = (answer + DP[depth][need][0]) % MOD;
            }
            else {
                if (DP[depth][need][1] == -1) {
                    DP[depth][need][1] = answer;
                    DFS(depth + 1, need);
                    DP[depth][need][1] = (answer - DP[depth][need][1] + MOD) % MOD;
                }
                else answer = (answer + DP[depth][need][1]) % MOD;
            }
        }
    }
}

int main(int argc, char** argv) {
    int T, tc;
    memset(choose, 1, sizeof(choose));
    choose[0] = 0;
    scanf("%d", &T);
    pactorial[1] = 1;
    for (int i = 2; i <= 100; i++)
        pactorial[i] = (pactorial[i - 1] * i) % MOD;
    for(tc = 1; tc<=T;tc++) {
        answer = 0;
        scanf("%d %d", &M, &N);
        if(M==N)
            printf("#%d %d\n",tc,pactorial[M]);
        else {
            memset(DP,-1,sizeof(DP));
            DFS(1, M-1 );
            printf("#%d %d\n", tc,(answer*M)%MOD);
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
