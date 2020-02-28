#include <stdio.h>
#define pc(x) putchar(x)
#define gc() getchar()
int rev, N;
char buf[0x1011] = { ' ', };
int readINT() {
	N = gc(), rev = 0x0;
	do {
		rev = (rev << 3) + (rev << 1) + (N & 0b1111);    N = gc();
	} while ('0' <= N && N <= '9');
	return rev;
}
void writeInt(int n, int r) {
	rev = 0x01;
	do {buf[rev++] = n % 10 + 48; }while(n /= 10); //store reverse of N in rev
	while (r--) {
		N = rev;
		while (N) pc(buf[--N]);
	}
}
int main(int argc, char** argv) {
	register int T, N, A, B, checked, time, tc, get = 0x0;
	T = readINT();
	int letter[101], letters[1001] = { 0x0, };
	for (tc = 0x1; tc <= T; tc++) {
		N = readINT(); A = readINT(); B = readINT();
		pc('#'); writeInt(tc, checked = 0x1);
		for (time = 0x1; time <= N; time++) 
			letters[letter[time] = readINT()] ^= 1;
		for (time = 0x1; time <= letter[N]; time++) {
			if (letters[time]) { get++; letters[time] ^= 1; }
			if (!(get^A) || !((time - letter[checked]) ^ B)) {
				writeInt(time, (get + 0x1) >> 1);
				checked += ((get + 1) >> 1);
				get >>= 1;
			}
		}
		while (get) {
			if (!(time - letter[checked] ^ B)) {
				writeInt(time, (get + 0x1) >> 1);
				checked += (get + 0x1) >> 1;
				get >>= 1;
			}
			time++;
		}
		pc('\n');
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
