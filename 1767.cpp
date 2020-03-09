#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define FFF(a,b) ((a<<3)+(a<<1)+(b));
#define AMAX 987654321;
#define REP(i,a,b) for(i = a; i < b; i++)
#define INSCOPE(a,b,N) ((((0)<=(a))&&((a)<(N)))&&(((0)<=(b))&&((b)<(N)))) ? (1) : (0)
#define ISSIDE(a,b,N) ((!(a))||(!(b))||(!((a)^(N)))||(!((b)^(N)))) ? (1) : (0)
#define NP(a,b,c,d) if((((a)-(b)+(c))<(d)))
#define reg register
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int numOfcore, numOfused, answer, N;
int corey[12], corex[12];
int fRI() {
	int N = gc(), r = 0;
	for (; '0' > N || N > '9'; N = gc());
	do {
		r = FFF(r, N & 0b1111); N = gc();
	} while ('0' <= N);
	return r;
}
void fWI(int tc) {
	int r = 0, c = 0;
	pc('#');
	while (!(tc % 10)) { c++; tc /= 10;}
	while (tc) { r = FFF(r, tc % 10); tc /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(0x30); pc(32);
	c = 0;
	while (!(answer % 10)) { c++; answer /= 10; }
	while (answer) { r = FFF(r, answer % 10); answer /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(0x30); pc('\n');
}
void DFS(int cur, int used, int map[12][12], int wires) {
	if (!(cur^numOfcore)) {
		if (!(numOfused^used)) 	answer = answer < wires ? answer : wires;
		else if (numOfused < used) {
			used ^= numOfused;	numOfused ^= used;
			wires ^= answer;	answer ^= wires;
		}
		return;
	}
	NP(numOfcore,cur,used,numOfused) return;
	reg int x = corex[cur], y = corey[cur], _wires, ny, nx, flag, i;
	int _map[12][12];
	REP(i,0,4){
		_wires = wires;
		ny = y + dy[i];
		nx = x + dx[i];
		flag = 1;
		memcpy(_map, map, sizeof(_map));
		_map[y][x] = 2;
		while (INSCOPE(nx,ny,N)) {
			if (_map[ny][nx]) {
				flag = 0;
				DFS(cur + 1, used, map, wires);
				break;
			}
			_map[ny][nx] = 2;
			_wires++;
			ny += dy[i];
			nx += dx[i];
		}
		if(flag) DFS(cur + 1, used + flag, _map, _wires);
		NP(numOfcore, cur, used, numOfused) return;
	}
} 
int main(void) {
	reg int tc = 1, T = fRI() , i, j;
	int map[12][12];
	while (T--) {
		N = fRI();
		numOfused = numOfcore = 0; answer = AMAX;
		REP(i,0,N)
			REP(j,0,N){
				map[i][j] = fRI();
				if (map[i][j]) {
					if (ISSIDE(i,j,N-1))	map[i][j] = 2;
					else {
						corey[numOfcore] = i;
						corex[numOfcore++] = j;
					}
				}
			}
		DFS(0, 0, map, 0);
		fWI(tc++);
	}
}
