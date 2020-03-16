#include <stdio.h>
int map[101][101];
int curve[1024];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int main(int argc, char** argv) {
	int N, idx, x, y, d, g, answer = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);
		switch (d) {
		case 0: d = 1; break;
		case 1: d = 0; break;
		case 2: d = 3; break;
		default : d = 2; break;
		}
		idx = 0; curve[idx++] = d;
		for (int gen = 1; gen <= g; gen++)
			for (int rev = idx - 1; rev >= 0; rev--)
				curve[idx++] = curve[rev] ? curve[rev] - 1 : 3;
		map[y][x] = 1;
		for (int s = 0; s < idx; s++) {
			x += dx[curve[s]];
			y += dy[curve[s]];
			map[y][x] = 1;
		}
	}
	for(int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) ++answer;
	if (map[99][99] && map[99][100] && map[100][99] && map[100][100]) ++answer;
	printf("%d", answer);
}
