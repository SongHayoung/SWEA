//#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>
#include <queue>
using namespace std;
struct curser {
	int x;
	int y;
	int dir;
	int mem;
	curser(int _x, int _y, int _d, int _m) : x(_x), y(_y), dir(_d), mem(_m) {}
};

int readINT() {
	int N = gc(), ret = 0;
	for (; N<'0' || N>'9'; N = gc());
	do {
		ret = (ret << 3) + (ret << 1) + (N&0b1111);    N = gc();
	} while ('0' <= N );
	return ret;
}
void writeInt(int n) {
	int rev = 0, count = 0;
	pc(0x23);
	while (!(n % 10)) { count++; n /= 10; } //obtain the count of the number of 0s
	while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  //store reverse of N in rev
	while (rev) { pc(rev % 10 |0b110000); rev /= 10; }
	while (count--) pc(0x30);
	pc(0x20);
	return;
}
char cmd[20][21];
int R, C;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int INFO[20][20][4][16];
queue<curser> q;
void simulation() {
	memset(INFO, 0, sizeof(INFO));
	INFO[0][0][1][0] = 1;
	if (!q.empty()) q = queue<curser>();
	q.emplace(0, 0, 1, 0);
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, dir = q.front().dir, mem = q.front().mem;
		q.pop();
		switch (cmd[y][x]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9': mem = cmd[y][x] & 0b1111; break;
		case '-': mem = mem ? --mem : 15; break;
		case '+': mem = !(mem ^ 15) ? 0 : ++mem; break;
		case '_': dir = mem ? 3 : 1; break;
		case '|': dir = mem ? 0 : 2; break;
		case '.': break;
		case '@': pc('Y'); pc('E'); pc('S'); pc(0x0A); return;
		case '>': dir = 1; break;
		case '<': dir = 3; break;
		case 'v': dir = 2; break;
		case '^': dir = 0; break;
		default:
			for (int i = 0; i < 4; i++) {
				int nx = !(x + dx[i] ^ -1) ? C - 1 : !(x + dx[i] ^ C) ? 0 : x + dx[i];
				int ny = !(y + dy[i] ^ -1) ? R - 1 : !(y + dy[i] ^ R) ? 0 : y + dy[i];
				if (!(INFO[ny][nx][i][mem]++)) q.emplace(nx, ny, i, mem);
			}break;
		}
		x = !(x + dx[dir] ^ -1) ? C - 1 : !(x + dx[dir] ^ C) ? 0 : x + dx[dir];
		y = !(y + dy[dir] ^ -1) ? R - 1 : !(y + dy[dir] ^ R) ? 0 : y + dy[dir];
		if (!(INFO[y][x][dir][mem]++)) q.emplace(x, y, dir, mem);
	}
	pc('N'); pc('O'); pc(0x0A);
	return ;
}
int main(int argc, char** argv) {
	int tc, T = readINT();
	for (tc = 1; tc <= T; tc++) {
		R = readINT(), C = readINT();
		writeInt(tc);
		for (int i = 0; i < R; i++) scanf("%s", cmd[i]);
		simulation();
	}
}
