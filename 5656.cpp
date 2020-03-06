#include <iostream>
#include <memory.h>
#include <numeric>
#include <queue>
#define gc() getchar_unlocked()
#define inrange(a, x, b)  ((((a)<=(x))&&((x)<(b))) ? (1) : (0))
#define SWAP(a, b) a^=b; b^=a; a^=b;
#define MIN(a,b) ((a)>(b))?(b):(a)
#define ADD3(a,b,c) ((a)+(b)+(c))
#define ADD2(a,b) ((a)+(b))

using namespace std;

class INFO {
public:
    int y;
    int x;
    int range;
    INFO(int _x, int _y, int _r) : range(_r), y(_y), x(_x) {}
};

int H, W, N, answer, qy, qx, qrange, swap_y,nx, ny;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<INFO> q;
inline int fRI(){
    int N=gc(), ret = 0;
    for(;N<'0'||N>'9';N=gc());
    do{
        ret = ADD3((ret<<3),(ret<<1),(N&0b1111)); N = gc();
    }while('0'<=N&&N<='9');
    return ret;
}
void DFS(int _N, int map[15][12], int cols[15]) {
    answer = MIN(answer, accumulate(cols, cols + W, 0));
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
                q.emplace(x, y, _map[y][x] - 1);
                _map[y][x] = 0;
                _cols[x]--;
                while (!q.empty()) {
                    qy = q.front().y;
                    qx = q.front().x;
                    qrange = q.front().range;
                    q.pop();
                    for (register int i = 1; i <= qrange; i++) {
                        for (register int j = 0; j < 4; j++) {
                            nx = ADD2(qx ,dx[j] * i);
                            ny = ADD2(qy ,dy[j] * i);
                            if (inrange(0,nx,W) && inrange(0,ny,H) && _map[ny][nx]) {
                                if(_map[ny][nx]>1) q.emplace(nx, ny, _map[ny][nx] - 1);
                                _map[ny][nx] = 0;
                                _cols[nx]--;
                            }
                        }
                    }
                }
                for (register int _x = 0; _x < W; _x++) {
                    //if(!_cols[_x]) continue;
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
                break;
            }
        }
    }
}

int main(int argc, char **argv) {
    register int tc = 1, T = fRI();
    int map[15][12], cols[12];
    for (; tc <= T; tc++) {
        N = fRI(); W = fRI(); H = fRI();
        memset(cols, 0, sizeof(int)*W);
        answer = 987654321;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++) {
                map[i][j] = fRI();
                if (map[i][j]) cols[j]++;
            }
        DFS(N, map, cols);
        printf("#%d %d\n", tc, answer);
    }
}
