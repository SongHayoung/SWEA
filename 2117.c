#include <stdio.h>
#define gc() getchar_unlocked()
#define COST(a) (((a)*(a))+((a-1)*(a-1)))
#define MAX(a,b) ((a)>(b)) ? (a) : (b)
int map[21][21];
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int main(void){
    register int test_case = 1, T = fRI(), N, M,answer, K, i, j,c, iu, id, _j, a, width;
    for (; test_case <= T; ++test_case){
        N = fRI(); M = fRI();
        a = answer = 0;
        for(i = 0; i<N;i++)
            for(j = 0; j<N; j++) {
                map[i][j] = fRI();
                if(map[i][j]) a++;
            }
        
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++){
                if(!(a^answer)) break;
                for(K = (MAX(MAX(i,j),MAX(N-i,N-j)))<<1;K>=1;K--){
                    c = 0;
                    iu = id = i;
                    for(_j = j-K+1<0 ? 0 : j-K+1; _j<N&&_j<=j+K-1; _j++)
                        if (map[i][_j]) c++;
                    for(width = (K<<1)-3; width>=1; width-=2){
                        iu--;
                        id++;
                        if(iu>=0&&id<=N) {
                            for(_j = j-(width>>1) < 0 ? 0 : j-(width>>1); _j<N&&_j<=j+(width>>1);_j++) {
                                if (map[iu][_j]) c++;
                                if (map[id][_j]) c++;
                            }
                        }
                        else if(iu>=0){
                            for(_j = j-(width>>1) < 0 ? 0 : j-(width>>1); _j<N&&_j<=j+(width>>1);_j++)
                                if(map[iu][_j]) c++;
                        }
                        else if(id<=N){
                            for(_j = j-(width>>1) < 0 ? 0 : j-(width>>1); _j<N&&_j<=j+(width>>1);_j++)
                                if(map[id][_j]) c++;
                        }
                        else
                            break;
                    }
                    if(c<answer)break;
                    if(c*M>=COST(K)){
                        answer = answer > c ? answer : c;
                        break;
                    }
                }
            }
        
        printf("#%d %d\n",test_case,answer);
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
