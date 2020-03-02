#include <stdio.h>
#include <stdlib.h>
#define sINFO struct INFO
#define pc(x) putchar_unlocked(x)
#define gc() getchar_unlocked()
sINFO{
	int from;
	int to;
	//INFO(int _f, int _t) : from(_f), to(_t) {}
};

int comp(const void *A, const void *B) {
	sINFO *ptrA = (sINFO *)A;
	sINFO *ptrB = (sINFO *)B;
	if (ptrA->from == ptrB->from)
		return ptrA->to < ptrB->to ? -1 : 1;
	return ptrA->from < ptrB->from ? -1 : 1;
}

int fRI() {
	int ret = 0, N = gc();
	for (; 48 > N || N > 57; N = gc())
		ret ^= 0;
	do {
		ret = (ret << 3) + (ret << 1) + (N & 0b1111);
		N = gc();
	} while (48 <= N);
	return ret;
}
int answer = 0;

void fWA(int tc) {
	pc(0x23);
	int r = 0, c = 0;
	while (!(tc % 10)) { c++; tc /= 10; }
	while (tc) { r = (r << 3) + (r << 1) + tc % 10; tc /= 10; }
	while (r) { pc(r % 10 + 48); r /= 10; }
	while (c--) pc(0x30);    pc(0x20);
	c = 0;
	while (!(answer % 10)) { c++; answer /= 10; }
	while (answer) { r = (r << 3) + (r << 1) + answer % 10; answer /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10;
}
	while (c--) pc(0x30);     pc(0x0A);
	return;
}
int main(int argc, char** argv) {
	register int N, f, t, idx = 0, tc, T, i;
	sINFO info[200];
	T = fRI();
	for (tc = 1; tc <= T; tc++) {
		answer = 0;
		N = fRI();
		for (; idx < N; idx++) {
			f = fRI(); t = fRI();
			f = (f + 1) >> 1;
			t = (t + 1) >> 1;
			info[idx].from = f > t ? t : f;
			info[idx].to = f > t ? f : t;
		}
		qsort(info, N, sizeof(sINFO), comp);
		while (idx) {
			f = 0;
			for (i = 0; i < N; i++)
				if (info[i].from > f) {
					f = info[i].to;
					info[i].from = -1;
					--idx;
				}
			++answer;
		}
		fWA(tc);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
