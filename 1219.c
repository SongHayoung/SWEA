#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int fRI() {
	int ret = 0, N = gc();
	for (; 0x30>N || N>0x3A; N = gc());
	for (; 0x30 <= N && N <= 0x3A; N = gc()) ret = (ret << 3) + (ret << 1) + (N & 0b1111);
	return ret;
}
int m[100][2];
int v[100];
int ans;
void DFS(int cur) {
	if (cur == 99) { ans = 1; return; }
	if (v[cur]||ans) return;
	v[cur] = 1;
	if (m[cur][0] != -1) DFS(m[cur][0]);
	if (m[cur][1] != -1) DFS(m[cur][1]);
}
int main(int argc, char** argv){
	register int T = 11, tc, N, f, e, i;
	while (--T) {
		tc = fRI(); N = fRI();
		memset(m, -1, sizeof(m));
		memset(v, 0, sizeof(v));
		ans = 0;
		for (i = 0; i < N; ++i) {
			f = fRI(); e = fRI();
			m[f][0] == -1 ? m[f][0] = e : m[f][1] = e;
		}
		DFS(0);
		printf("#%d %d\n",tc, ans);
	}
}
