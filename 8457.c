#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int answer = 0;
int fRI() {
	int N = gc(), ret = 0;
	for (; N < 48 || N>57; N = gc());
	do {
		ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
	} while ('0' <= N && N <= '9');
	return ret;
}
void fWA(int tc) {
	int r = 0, c = 0;
	pc('#');
	while (!(tc % 10)) { c++; tc /= 10; }
	while (tc) { r = (r << 3) + (r << 1) + tc % 10; tc /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(48); pc(' ');
	c = 0;
	if (!answer) { pc('0'); pc('\n'); return; }
	while (!(answer % 10)) { c++; answer /= 10; }
	while (answer) { r = (r << 3) + (r << 1) + answer % 10; answer /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(48); pc('\n');
}
int main(int argc, char** argv){
	//11:00
	register int test_case = 1, T, N, B, E, num, l;
	T = fRI();
	for (; test_case <= T; ){
		N = fRI(); B = fRI(); E = fRI();
		for (int i = 0; i<N; i++) {
			num = fRI();
			l = (B - E) / num * num;
			while (l <= B + E) {
				if (B - E <= l) {
					++answer;
					break;
				}
				l += num;
			}
		}
		fWA(test_case++);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
