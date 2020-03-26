#include <stdio.h>
#include <memory.h>
int v[10001];
int input;
int ans, N;
int main(void) {
	int tc = 0, T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		ans = 0;
		memset(v, 0, sizeof(v));
		v[0] = 1;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &input);
			for (int j = 10000; j >= 0; --j) {
				if (v[j]) v[j + input] = 1;
			}
		}
		for (int i = 0; i <= 10000; ++i)
			if (v[i]) ++ans;
		printf("#%d %d\n", ++tc, ans);
	}

}
