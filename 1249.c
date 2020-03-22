#include <stdio.h>
#include <queue>
#define gc() getchar_unlocked()
using namespace std;
char map[100][100];
int v[100][100];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
struct tank{
    int y;
    int x;
    int cost;
};
bool operator<(tank a, tank b){
    return a.cost > b.cost;
}
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
int main(void){
    register int T = fRI(),  tc = 0, i, j, N;
    tank a;
    while(T--){
        N = fRI();
        for(i = 0; i < N; ++i)
            scanf("%s",map[i]);
        priority_queue<tank> pq;
        for(i = 0; i < N; ++i)
            for(j = 0; j < N; ++j)
                v[i][j] = 987654321;
        a.x = 0;
        a.y = 0;
        a.cost = (map[0][0]&0b1111);
        v[0][0] = (map[0][0]&0b1111);
        pq.push(a);
        while(!pq.empty()){
            a = pq.top();
            if(a.y==N-1&&a.x==N-1){
                printf("#%d %d\n",++tc,a.cost);
                break;
            }
            pq.pop();
            for(i = 0; i < 4; ++i){
                if(0<=a.y+dy[i]&&a.y+dy[i]<N && 0<=a.x+dx[i]&&a.x+dx[i]<N){
                    if(v[a.y+dy[i]][a.x+dx[i]]> a.cost+(map[a.y+dy[i]][a.x+dx[i]]&0b1111)) {
                        v[a.y+dy[i]][a.x+dx[i]] = a.cost+(map[a.y+dy[i]][a.x+dx[i]]&0b1111);
                        tank b = a;
                        b.y += dy[i];
                        b.x += dx[i];
                        b.cost += (map[b.y][b.x] & 0b1111);
                        pq.push(b);
                    }
                }
            }
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
