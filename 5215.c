//#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>
int had[1<<20+1], N, L, answer=0, cals[20], happys[20];
int readINT() {
	int N = gc(), ret = 0;
	do {
		ret = (ret << 3) + (ret << 1) + (N & 0b1111);    N = gc();
	} while ('0' <= N);
	return ret;
}
void writeANSWER(int n) {
	int rev = 0, count = 0;
	pc(0x23);
	while (!(n % 10)) { count++; n /= 10; } //obtain the count of the number of 0s
	while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  //store reverse of N in rev
	while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
	while (count--) pc(0x30);
	count = 0; pc(0x20);
	while (!(answer % 10)) { count++; answer /= 10; }
	while (answer) { rev = (rev << 3) + (rev << 1) + answer % 10; answer /= 10; }  //store reverse of N in rev
	while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
	while (count--) pc(0x30);
	pc(0x0A);
	return;
}
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
		simulation(0, 0, 0);
		writeANSWER(tc);
	}
}

/*DP Solution
//#pragma GCC optimize ("O3")
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#include <stdio.h>
#include <memory.h>

int DP[10001], N, L, answer = 0, cals[20], happiness[20];

int readINT() {
int N = gc(), ret = 0;
do {
ret = (ret << 3) + (ret << 1) + (N & 0b1111);    N = gc();
} while (48 <= N);
return ret;
}
void writeANSWER(int n) {
int rev = 0, count = 0;
pc(0x23);
while (!(n % 10)) { count++; n /= 10; } //obtain the count of the number of 0s
while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  //store reverse of N in rev
while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
while (count--) pc(0x30);
count = 0; pc(0x20);
while (!(DP[L] % 10)) { count++; DP[L] /= 10; }
while (DP[L]) { rev = (rev << 3) + (rev << 1) + DP[L] % 10; DP[L] /= 10; }  //store reverse of N in rev
while (rev) { pc(rev % 10 | 0b110000); rev /= 10; }
while (count--) pc(0x30);
pc(0x0A);
return;
}
int main(int argc, char** argv) {
register int tc = 1, T = readINT();
for (; tc <= T; tc++) {
N = readINT(), L = readINT();
memset(DP, 0, sizeof(DP));
for (int i = 0; i < N; i++) { happiness[i] = readINT(); cals[i] = readINT(); }
for (int i = 0; i < N; i++) {
for (int j = L; j >= cals[i]; j--)
DP[j] = DP[j] > happiness[i] + DP[j - cals[i]] ? DP[j] : happiness[i] + DP[j - cals[i]];
}
writeANSWER(tc);
}
}
*/
