//#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
int readINT() {
	int N = gc(), ret = 0;
	do {
		ret = (ret << 3) + (ret << 1) + (N & 0b1111);    N = gc();
	} while ('0' <= N);
	return ret;
}
void writeANSWER(int tc, long n) {
	long rev = 0, count = 0;
	pc('#');
	while (!(tc % 10)) { count++; tc /= 10; } 
	while (tc) { rev = (rev << 3) + (rev << 1) + tc % 10; tc /= 10; } 
	while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
	while (count--) pc('0');
	count = 0;	pc(' ');
	while (!(n % 10)) { count++; n /= 10; } 
	while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  
	while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
	while (count--) pc('0');
	pc('\n');
	return;
}
int compare(const void *a, const void *b) {
	return *(int*)a > *(int*)b ? 1 : -1;
}
int clothes[100000], N;
long answer;
int main(int argc, char** argv) {
	int tc, T = readINT();
	for (tc = 1; tc <= T; tc++) {
		N = readINT();
		answer = 0;
		for (int i = 0; i < N; i++) clothes[i] = readINT();
		qsort(clothes, N, sizeof(int), compare);
		for (int i = N - 1; i >= 0; i--) if ((N - i) % 3) answer += clothes[i];
		writeANSWER(tc, answer);
	}
}
