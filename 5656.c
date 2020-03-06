#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define inrange(a, x, b)  ((((a)<=(x))&&((x)<(b))) ? (1) : (0))
#define SWAP(a, b) a^=b; b^=a; a^=b;
#define MIN(a,b) ((a)>(b))?(b):(a)
#define ADD3(a,b,c) ((a)+(b)+(c))
#define ADD2(a,b) ((a)+(b))
#define MAXN 99
int H, W, N, answer, qy, qx, qrange, swap_y,nx, ny,from,end;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int q[20][3];
int fRI(){
    int N=gc(), ret = 0;
    for(;N<'0'||N>'9';N=gc());
    do{
        ret = ADD3((ret<<3),(ret<<1),(N&0b1111)); N = gc();
    }while('0'<=N);
    return ret;
}
void fWA(int tc) {
    int r = 0, c = 0;
    pc(0x23);
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = ADD3((r << 3), (r << 1), tc % 10); tc /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30); pc(0x20);
    c = 0;
    if (!answer) { pc(0x30); pc(0x0A); return; }
    while (!(answer % 10)) { c++; answer /= 10; }
    while (answer) { r = ADD3((r << 3), (r << 1), answer % 10); answer /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30); pc(0x0A);
}
int accumulate(int *col){
    register int ret = 0;
    for(register int i = 0; i < W; i++)
        ret += col[i];
    return ret;
}
void DFS(int _N, int map[15][12], int cols[15]) {
    answer = MIN(answer, accumulate(cols));
    if(!_N||!answer) return;
    int _map[15][12], _cols[15];
    for (register int x = 0; x < W; x++) {
        if(!cols[x]) continue;
        for (register int y = 0; y < H; y++) {
            if (map[y][x]) {
                //for(register int i = 0; i < H; i++)
                //memcpy(_map[i], map[i], sizeof(int)*W);
                memcpy(_map,map,sizeof(_map));
                memcpy(_cols, cols, sizeof(int)*W);
                if(!(_map[y][x]^1)){
                    _map[y][x]=0;
                    _cols[x]--;
                    DFS(_N-1,_map,_cols);
                    break;
                }
                q[0][0] = x;
                q[0][1] = y;
                q[0][2] = _map[y][x]-1;
                from = _map[y][x] = 0; end = 1;
                _cols[x]--;
                while (from^end) {
                    qy = q[from][1];
                    qx = q[from][0];
                    qrange = q[from++][2];
                    for (register int i = 0; i < 4; i++) {
                        for (register int j = 1; j <= qrange; j++) {
                            nx = ADD2(qx ,dx[i] * j);
                            ny = ADD2(qy ,dy[i] * j);
                            if(!(inrange(0,nx,W)&&inrange(0,ny,H)))
                                break;
                            if (_map[ny][nx]) {
                                if(_map[ny][nx]>1){
                                    q[end][0] = nx;
                                    q[end][1] = ny;
                                    q[end++][2] = _map[ny][nx]-1;
                                }
                                _map[ny][nx] = 0;
                                _cols[nx]--;
                            }
                        }
                    }
                }
                for (register int _x = 0; _x < W; _x++) {
                    if(!_cols[_x]) continue;
                    for (register int _y = H - 2; _y >= 0; _y--) {
                        if (_map[_y][_x]) {
                            swap_y = _y;
                            while (swap_y <= H - 2 && !_map[swap_y + 1][_x]) {
                                SWAP(_map[swap_y + 1][_x], _map[swap_y][_x])
                                swap_y++;
                            }
                        }
                    }
                }
                DFS(_N - 1, _map, _cols);
                if(!answer) return;
                break;
            }
        }
    }
}

int main(int argc, char **argv) {
    register int tc = 1, T = fRI();
    int map[15][12], cols[12];
    for (; tc <= T;) {
        N = fRI(); W = fRI(); H = fRI();
        memset(cols, 0, sizeof(int)*W);
        answer = MAXN;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                map[i][j] = fRI();
                if (map[i][j]) cols[j]++;
            }
        DFS(N, map, cols);
        fWA(tc++);
    }
}
