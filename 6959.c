#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define reg register
int fRI() {
	reg int N = gc(), r = 0;
	for (;48 > N || N > 57; N = gc());
	do {
		r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
	} while (48 <= N);
	return r;
}
void fWI(int tc) {
	reg int r = 0, c = 0;
	pc(0x23);
	while (!(tc % 10)) { c++; tc /= 10; }
	while (tc) { r = (r << 3) + (r << 1) + (tc % 10); tc /= 10; }
	while (r) { pc(r % 10 | 0b110000); r /= 10; }
	while (c--) pc(0x30); pc(32);
}
int main(void) {
	reg int tc = 1, T = fRI(), c, s, input;
	while (T--) {
		c = s = 0;
		while (input = gc(), 48 <= input) {
			s = (s << 3) + (s << 1) + (input & 0b1111);
			while (s >= 10) {
				s = s % 10 + s / 10;
				c ^= 1;
			}
		}
		fWI(tc++);
		c & 1 ? pc(0x41) : pc(0x42);
		pc(0x0A);
	}
}
