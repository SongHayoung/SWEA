#include <stdio.h>
#define gc() getchar_unlocked()
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int main(void){
    register int T = fRI(),  tc = 0, N, X, ans, i, j, k, use;
    int map[20][20];
    while(T--){
        N = fRI(), X = fRI();
        ans = N<<1;
        for(i = 0; i < N; ++i){
            for(j = 0; j < N; ++j)
                map[i][j] = fRI();
            use = -1;
            for(j = 0; j < N-1; ++j){
                if(map[i][j]>map[i][j+1]){
                    if(map[i][j] != map[i][j+1]+1) {--ans; break;}
                    if(j+X>=N) {--ans; break;}
                    for(k = j+2; k <= j+X; ++k){
                        if(map[i][j+1]!=map[i][k]) {--ans; break;}
                        use = k;
                    }
                    if(use != j+X) break;
                    j = use - 1;
                }
                else if(map[i][j]<map[i][j+1]){
                    if(map[i][j]+1!=map[i][j+1]) {--ans; break;}
                    if(j-X+1<0||j-X<use) {--ans; break;}
                    for(k = j-1; k > j-X; --k){
                        if(map[i][j]!=map[i][k]) {--ans; break;}
                        use = k;
                    }
                    if(use != j-X+1) break;
                }
            }
        }
        for(j = 0; j < N; ++j){
            use = -1;
            for(i = 0; i < N-1; ++i){
                if(map[i][j]>map[i+1][j]){
                    if(map[i][j] != map[i+1][j]+1) {--ans; break;}
                    if(i+X>=N) {--ans; break;}
                    for(k = i+2; k <= i+X; ++k){
                        if(map[i+1][j] != map[k][j]) {--ans; break;}
                        use = k;
                    }
                    if(use != i+X) break;
                    i = use-1;
                }
                else if(map[i][j]<map[i+1][j]){
                    if(map[i][j]+1 != map[i+1][j]) {--ans; break;}
                    if(i-X+1<0||i-X<use) {--ans; break;}
                    for(k = i-1; k > i-X; --k){
                        if(map[i][j] != map[k][j]) {--ans; break;}
                        use = k;
                    }
                    if(use != i-X+1) break;
                }
            }
        }
        printf("#%d %d\n",++tc,ans);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
