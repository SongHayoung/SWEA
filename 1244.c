//#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>

char buf[7], _buf[7];
int used[1000000][10];
int N, len;
void swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}
int readINT() {
	int N = gc(), ret = 0;
	for (; N<48 || N>57; N = gc());
	do {
		ret = (ret << 3) + (ret << 1) + (N&0b1111);    N = gc();
	} while (48 <= N );
	return ret;
}
void writeANSWER(int n) {
	int rev = 0, count = 0;
	pc(0x23);
	while (!(n % 10)) { count++; n /= 10; } //obtain the count of the number of 0s
	while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  //store reverse of N in rev
	while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
	while (count--) pc(0x30);
	pc(0x20);
	for (int i = 0; i < len - 1; i++) pc(buf[i]);
	pc(0x0A);
	return;
}
void DFS(int depth, char _buf[7]) {
	if (!(depth^N)) {
		for (int i = 0; i < len; i++) {
			if (buf[i]>_buf[i]) return;
			else if (buf[i]<_buf[i]) {
				memcpy(buf, _buf, sizeof(buf));
				return;
			}
		}
		return;
	}
	int is_used = 0;
	for (int i = 0; i < len - 1; i++) is_used = (is_used << 3) + (is_used << 1) + (_buf[i] & 0b1111);
	if (used[is_used][depth]) return;
	used[is_used][depth] = 1;
	for (int i = 0; i<len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			char n_buf[7];
			memcpy(n_buf, _buf, sizeof(n_buf));
			swap(n_buf[i], n_buf[j]);
			DFS(depth + 1, n_buf);
		}
	}
}
int main(int argc, char** argv) {
	register int tc=1, T = readINT();
	for (; tc <= T;) {
		len = 0;
		do {
			buf[len++] = gc();
		} while (48 <= buf[len - 1] && buf[len - 1] <= 57);
		N = readINT();
		memcpy(_buf, buf, sizeof(_buf));
		memset(used, 0, sizeof(used));
		DFS(0, _buf);
		writeANSWER(tc++);
	}
}
