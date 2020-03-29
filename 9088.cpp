#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int T, tc = 0,N,K,n,ans,cur;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &K);
		vector<long long> v;
		v.reserve(N);
		int f , e;
		for (int i = 0; i < N; ++i) {
			scanf("%d", &n);
			v.push_back(n);
		}
		sort(v.begin(), v.end());
		f = e = ans = cur = 0;
		for(; e < N; ++e){
			if (v[e] - v[f] <= K) {
				++cur;
				ans = ans > cur ? ans : cur;
			}
			else {
				while (v[e] - v[f] > K && f < N)
					--cur, ++f;
				--e;
			}
		}
		printf("#%d %d\n", ++tc, ans);
	}
	return 0;
}
