#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ll long long
int N;
ll factorial[17];
int aft[17][17], u[17], bef[17], dp[1 << 17];
int fRI() {
	register int N = gc(), ret = 0;
	for (; N < 48 || N>57; N = gc());
	do {
		ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
	} while ('0' <= N);
	return ret;
}
void fWA(int tc, ll a) {
	ll r = 0, c = 0;
	pc('#');
	while (!(tc % 10)) { c++; tc /= 10; }
	while (tc) { r = (r << 3) + (r << 1) + tc % 10; tc /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(48); pc(' ');
	c = 0;
	while (!(a % 10)) { c++; a /= 10; }
	while (a) { r = (r << 3) + (r << 1) + a % 10; a /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(48); pc('\n');
}
ll dfs(int s) {
	if (!s) return 1;
	if (dp[s]) return dp[s];
	for (register int i = 1; i <= N; i++) {
		if (bef[i]) continue;
		bef[i]--;
		for (register int j = 1; j <= N; j++)
			if(aft[i][j]) bef[j]--;
		dp[s] += dfs(s ^ (1 << (i - 1)));
		for (register int j = 1; j <= N; j++)
			if (aft[i][j]) bef[j]++;
		bef[i]++;
	}
	return dp[s];
}
void mset(int s) {
	if (!dp[s]) return;
	dp[s] = 0;
	for (register int i = 1; i <= N; i++)
		if (s&(1 << (i - 1))) mset(s ^ (1 << (i - 1)));
}
int main(int argc, char** argv) {
	register int tc = 1, T = fRI(), M, x, y, i;
	factorial[1] = factorial[0] = 1;
	for (i = 2; i <= 16; i++)
		factorial[i] = factorial[i - 1] * i;
	while (T--) {
		N = fRI(), M = fRI();
		for (i = 0; i < M; i++) {
			x = fRI(), y = fRI();
			aft[x][y] ^=1;
			u[x] = u[y] = 1;
			++bef[y];
		}
		x = y = 0;
		for (i = 1; i <= N; i++)
			u[i] ? (++x, y ^= 1 << (i - 1)) : (bef[i]--);
		fWA(tc++, factorial[N] / factorial[x] * dfs(y));
		if (T) {mset(y); memset(aft, 0, sizeof(int)*(17)*(N+1)); memset(u, 0, sizeof(int)*(N+1)); memset(bef, 0, sizeof(int)*(N+1)); }
	}
}
