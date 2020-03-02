//#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>
int readINT() {
	int N = gc(), ret = 0;
	do {
		ret = (ret << 3) + (ret << 1) + (N &0b1111);    N = gc();
	} while ('0' <= N);
	return ret;
}
void writeInt(int n) {
	int rev = 0, count = 0;
	while (!(n % 10)) { count++; n /= 10; } //obtain the count of the number of 0s
	while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  //store reverse of N in rev
	while (rev) { pc(rev % 10|0b110000); rev /= 10; }
	while (count--) pc('0');
	return;
}
int had[1048577], N, L, answer, cals[20], happys[20];
void simulation(int cal, int picked, int happiness) {
	if (had[picked]) return;
	had[picked] = cal;
	answer = answer > happiness ? answer : happiness;
	for (int i = 0; i < N; i++) {
		if (picked&(1 << i)) continue;
		if (cal + cals[i] < L)		simulation(cal + cals[i], picked + (1 << i), happiness + happys[i]);
	}
}
int main(int argc, char** argv) {
	int tc, T = readINT();
	for (tc = 1; tc <= T; tc++) {
		N = readINT(), L = readINT();
		answer = 0;
		memset(had, 0, sizeof(had));
		for (int i = 0; i < N; i++) { happys[i] = readINT(); cals[i] = readINT(); }
		pc('#');  writeInt(tc); pc(' ');
		simulation(0, 0, 0);
		writeInt(answer);
		pc('\n');
	}
}
