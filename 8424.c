#include <stdio.h>
#include <memory.h>
int graph[1001][1001],info[1001];
int DFS(int from,int to,int search) {
	if (info[to])	return search-info[to];
	int ret = 0;
	info[to] = search+1;
	for(int i=1;i<=1000;i++)
		if (graph[to][i]) {
			graph[to][i] = graph[i][to] = 0;
			ret = DFS(to, i, search + 1);
			if (ret)	return ret;
		}
	return ret;
}
int main(int argc, char** argv) {
	int T, N, A, B, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++) {
		memset(info, 0, sizeof(info));
		memset(graph, 0, sizeof(graph));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d",&A, &B);
			graph[A][B] = graph[B][A] = 1;
		}
		printf("#%d %d\n", tc, DFS(A,B,0)+1);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
