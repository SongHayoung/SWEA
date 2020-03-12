#include <stdio.h>
#include <memory.h>
#include <queue>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define reg register
using namespace std;
int N, M, K;
class Cell{
public:
    int x;
    int y;
    int time;
    int time_left;
    Cell(int _y, int _x, int _t) : y(_y), x(_x), time(_t), time_left(_t) { }
    Cell(int _y, int _x, int _t, int _tl) : y(_y), x(_x), time(_t), time_left(_tl) { }
};
int grid[450][450][2];
bool cells[450][450];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
queue<Cell> q;
int fRI() {
    reg int N = gc(), r = 0;
    for (;48 > N || N > 57; N = gc());
    do {
        r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
    } while (48 <= N);
    return r;
}
void fWI(int tc) {
    if(!tc) {pc(48); return;}
    reg int r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = (r << 3) + (r << 1) + (tc % 10); tc /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30);
}
int main(int argc, char** argv){
    reg int T = fRI(), tc = 1, cur_time, size, j, cx, cy, nx, ny, ct, cl, answer, k;
    while(T--){
        memset(grid,0,sizeof(grid));
        memset(cells,false,sizeof(cells));
        answer = 0;
        N = fRI(); M = fRI(); K = fRI();
        for(reg int i = 200; i < 200+N; i++)
            for(reg int j = 200; j < 200 + M; j++) {
                grid[i][j][1] = (fRI()<<1);
                if(grid[i][j][1]){
                    grid[i][j][0] = 999999;
                    q.emplace(i,j,grid[i][j][1]);
                }
            }
        for(cur_time = 1; cur_time <= K; cur_time++){
            size = q.size();
            for(j = 0; j < size; j++){
                cx = q.front().x;
                cy = q.front().y;
                ct = q.front().time;
                cl = q.front().time_left-1;
                q.pop();
                if(grid[cy][cx][1]!=ct) continue;
                if(!(ct^((cl+1)<<1))){
                    for(k = 0; k < 4; k++){
                        nx = cx+dx[k];
                        ny = cy+dy[k];
                        if((!grid[ny][nx][0]||!(grid[ny][nx][0]^cur_time))&&grid[ny][nx][1]<ct){
                            grid[ny][nx][0] = cur_time;
                            grid[ny][nx][1] = ct;
                            q.emplace(ny,nx,ct,ct);
                        }
                    }
                }
                if(cl)
                    q.emplace(cy,cx,ct,cl);
            }
        }
        while(!q.empty()){
            if(!cells[q.front().y][q.front().x]) {cells[q.front().y][q.front().x] = true; answer++; }
            q.pop();
        }
        pc('#');fWI(tc++);pc(' ');fWI(answer);pc('\n');
    }
}
