#include <stdio.h>
#define pc(x) putchar(x)
#define gc() getchar()
int rev, count, N, _count;
int readINT() {
	N = gc(), rev = 0;
	do {
		rev = (rev << 3) + (rev << 1) + (N & 0b1111);    N = gc();
	} while ('0' <= N && N <= '9');
	return rev;
}
void writeInt(int n, int r) {
	rev = count = 0;
	while (!(n % 10)) { count++; n /= 10; } //obtain the count of the number of 0s
	while (n) { rev = (rev << 3) + (rev << 1) + n % 10; n /= 10; }  //store reverse of N in rev
	while(r--){
		N = rev; _count = count;
		while (N) { pc(N % 10 + '0'); N /= 10; }
		while (_count--) pc('0');
		pc(' ');
	}
}
int main(int argc, char** argv) {
	register int T, N, A, B, checked, time, tc, get = 0;
	T = readINT();
	int letter[101], letters[1001] = { 0, };
	for (tc = 1; tc <= T; tc++) {
		N = readINT(); A = readINT(); B = readINT();
		pc('#'); writeInt(tc, 1);
		for (time = 1; time <= N; time++) {
			letter[time] = readINT();
			letters[letter[time]] ^= 1;
		}
		checked = 1;
		for (time = 1; time <= letter[N]; time++) {
			if (letters[time]) { get++; letters[time] ^= 1; }
			if (!(get^A) || !((time - letter[checked]) ^ B)) {
				writeInt(time, (get + 1) >> 1);
				checked += ((get + 1) >> 1);
				get >>= 1;
			}
		}
		while (get) {
			if (!(time - letter[checked] ^ B)) {
				writeInt(time, (get + 1) >> 1);
				checked += (get + 1) >> 1;
				get >>= 1;
			}
			time++;
		}
		pc('\n');
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
