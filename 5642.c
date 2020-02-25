#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
int ret, flag, n;
int fastReadINT() {
	ret = 0, flag = 1, n = gc();
	for (; '0'>n || n>'9'; n = gc()) {
		if (n == '-') {
			flag = -1; n = gc(); break;
		}
	}
	do {
		ret = (ret << 3) + (ret << 1) + (n & 0b1111); n = gc();
	} while ('0' <= n && n <= '9');
	return ret * flag;
}
void fastWriteANSWER(int tc, int N) {
	pc('#');	flag = 0;  ret = n = tc;
	while ((ret % 10) == 0) { flag++; ret /= 10; }
	ret = 0;
	while (tc != 0) { ret = (ret << 3) + (ret << 1) + tc % 10; tc /= 10; }
	while (ret != 0) { pc(ret % 10 + '0'); ret /= 10; }
	while (flag--) pc('0');
	pc(' ');
	if (N == 0) { pc('0'); pc('\n'); return; }
	if (N<0) { N = -N; pc('-'); }
	flag = 0, ret = n = N;
	while ((ret % 10) == 0) { flag++; ret /= 10; }
	ret = 0;
	while (N != 0) { ret = (ret << 3) + (ret << 1) + N % 10; N /= 10; }
	while (ret != 0) { pc(ret % 10 + '0'); ret /= 10; }
	while (flag--) pc('0');
	pc('\n');
}
int main(int argc, char** argv)
{
	register int test_case, answer, cmp, N, T, num;
	T = fastReadINT();
	for (test_case = 1; test_case <= T; test_case++) {
		N = fastReadINT();
		cmp = answer = fastReadINT();
        --N;
		while(N--) {
			num = fastReadINT();
			if (cmp + num >= 0) {
				cmp += num;
				answer = answer > cmp ? answer : cmp;
			}
			else if (cmp < num) {
				cmp = num;
				answer = answer > cmp ? answer : cmp;
			}
			else
				cmp = 0;
		}
		fastWriteANSWER(test_case,answer);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
