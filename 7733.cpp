#include <stdio.h>
#include <memory.h>
#include <queue>

#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a, b) ((a<<3)+(a<<1)+(b))
#define REP(i, a, b) for(i = a; i < b; i++)
#define INRANGE(a,b,N) (((0)<=(a))&&((a)<(N))&&((0)<=(b))&&((b)<(N))) ? (1) : (0)
using namespace std;
int answer, N, day, block, nx, ny, cx, cy;
bool v[101], visit[100][100];
int freg[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int, int>> q;

int fRI() {
    int N = gc(), r = 0;
    for (; 0x30 > N || N > 0x3A; N = gc());
    do {
        r = ADD3(r, N & 0b1111);
        N = gc();
    } while (0x30 <= N && N <= 0x3A);
    return r;
}

void fWI(int tc) {
    int r = 0, c = 0;
    while (!(tc % 10)) {
        c++;
        tc /= 10;
    }
    while (tc) {
        r = ADD3(r, tc % 10);
        tc /= 10;
    }
    while (r) {
        pc(r % 10 + 48);
        r /= 10;
    }
    while (c--) pc(0x30);
    return;
}

void simulation() {
    register int i, j, k;
    REP(day, 1, 100) {
        if (!v[day]) continue;
        v[day] = false;
        block = 0;
        memset(visit, false, sizeof(visit));
        REP(i, 0, N)REP(j, 0, N) {
            if (freg[i][j] >= day && !visit[i][j]) {
                q.emplace(i, j);
                visit[i][j] = true;
                block++;
                while (!q.empty()) {
                    cx = q.front().second;
                    cy = q.front().first;
                    q.pop();
                    REP(k, 0, 4) {
                        nx = cx + dx[k];
                        ny = cy + dy[k];
                        if (INRANGE(nx,ny,N)) {
                            if (!visit[ny][nx] && freg[ny][nx] >= day) {
                                q.emplace(ny, nx);
                                visit[ny][nx] = true;
                            }
                        }
                    }
                }
            }
        }
        answer = block > answer ? block : answer;
    }
}

int main(void) {
    register int tc = 1, T = fRI(), i, j;
    memset(freg, 0, sizeof(freg));
    memset(v, 0, sizeof(v));
    while (T--) {
        N = fRI();
        answer = 1;
        REP(i, 0, N)REP(j, 0, N) {
            freg[i][j] = fRI();
            v[freg[i][j]] = true;
        }
        simulation();
        pc('#');fWI(tc++);pc(' ');fWI(answer);pc('\n');
    }
    return 0;
}
