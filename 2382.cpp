#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
int map[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
struct bug {
    int x;
    int y;
    int dir;
    int bugs;
    int num;
};
bug b[1001];
priority_queue<bug> pq;
bool operator<(bug A, bug B) {
    if (A.y > B.y) return true;
    if (A.y < B.y) return false;
    if (A.x > B.x) return true;
    if (A.x < B.x) return false;
    return A.bugs < B.bugs ? true : false;
}
int main(void) {
    int T, tc = 0, N, M, K, x, y;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &N, &M, &K);
        memset(map,0,sizeof(map));
        for (int i = 1; i <= K; ++i) {
            scanf("%d %d %d %d", &b[i].y, &b[i].x, &b[i].bugs, &b[i].dir);
            map[b[i].y][b[i].x] = b[i].num = i;
            switch (b[i].dir) {
                case 1: b[i].dir = 0; break;
                case 4: b[i].dir = 1; break;
                default: break;
            }
        }
        for (int time = 0; time < M; ++time) {
            for (int bugs = 1; bugs <= K; bugs++) {
                if (!b[bugs].num) continue;
                if (map[b[bugs].y][b[bugs].x] == b[bugs].num) map[b[bugs].y][b[bugs].x] = 0;
                b[bugs].x += dx[b[bugs].dir];
                b[bugs].y += dy[b[bugs].dir];
                if (b[bugs].x == 0 || b[bugs].y == 0 || b[bugs].x == N - 1 || b[bugs].y == N - 1)
                    b[bugs].bugs >>= 1, b[bugs].dir = (b[bugs].dir + 2) % 4;
                if (map[b[bugs].y][b[bugs].x] == 0 || map[b[bugs].y][b[bugs].x] > b[bugs].num) map[b[bugs].y][b[bugs].x] = b[bugs].num;
                else if (map[b[bugs].y][b[bugs].x] < b[bugs].num && 0 < map[b[bugs].y][b[bugs].x]) {
                    pq.push(b[map[b[bugs].y][b[bugs].x]]);
                    pq.push(b[bugs]);
                    map[b[bugs].y][b[bugs].x] = -1;
                }
                else if (map[b[bugs].y][b[bugs].x] == -1)
                    pq.push(b[bugs]);
            }
            while (!pq.empty()) {
                x = pq.top().x;
                y = pq.top().y;
                int num = pq.top().num;
                pq.pop();
                map[y][x] = num;
                while (!pq.empty()&&pq.top().x == x && pq.top().y == y) {
                    b[pq.top().num].num=0;
                    b[num].bugs += pq.top().bugs;
                    pq.pop();
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= K; ++i)
            if (b[i].num) ans += b[i].bugs;
        printf("#%d %d\n", ++tc, ans);
    }
    return 0;
}
