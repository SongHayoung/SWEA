#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int N;
int table[16][16];
int dp[1<<16];
int ans = 987654321;
int fRI() {
    int N = gc(), ret = 0;
    for (; N < 48 || N>57; N = gc());
    do {
        ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
    } while ('0' <= N && N <= '9');
    return ret;
}
int getvalue(int choose){
    int ret = 0;
    for(int i = 0; i < N; ++i)
        for(int j = 0;j < N; ++j)
            if((choose&(1<<i)) && (choose&(1<<j))) {ret += table[i][j];}
    return ret;
}
int abs(int n){
    return n > 0 ? n : -n;
}
void DFS(int choose, int cnt, int cur){
    if(cnt==(N>>1)){
        if(dp[choose]) return;
        dp[choose] = dp[((1<<N)-1)^choose] = 1;
        int val = abs(getvalue(choose)-getvalue(((1<<N)-1)^choose));
        ans = ans > val ? val : ans;
        return;
    }
    if(cur==N) return;
    DFS(choose+(1<<cur),cnt+1,cur+1);
    DFS(choose,cnt,cur+1);
}
int main(int argc, char** argv){
    int tc = 1, T = fRI();
    while(T--){
        memset(dp,0,sizeof(int)*(1<<N));
        N = fRI();
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
                table[i][j] = fRI();
        ans = 987654321;
        DFS(0,0,0);
        printf("#%d %d\n",tc++,ans);
    }
}
