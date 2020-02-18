#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
bool arr[16][26];
int answer;
int N, TC;
string s;
void DFS(int index,bool cur[]) {
    if (index == N) {
        for (int i = 0; i < 26; i++) {
            if (!cur[i])
                return;
        }
        ++answer;
        return;
    }
    bool next_cur[26];
    memcpy(next_cur, cur, sizeof(next_cur));
    DFS(index + 1, next_cur);
    for (int i = 0; i < 26; i++) {
        if (arr[index][i])
            next_cur[i] = true;
    }
    DFS(index + 1, next_cur);
}

int main(int argc, char** argv) {
    scanf("%d",&TC);
    bool cur[26] = { false, };
    for (int i = 1; i<=TC; i++) {
        scanf("%d",&N);
        memset(arr, false, sizeof(arr));
        answer = 0;
        for (int j = 0; j < N; j++) {
            cin >> s;
            for (int k = 0; k < s.length(); k++)
                arr[j][s[k] - 'a'] = true;
        }
        DFS(0, cur);
        printf("#%d %d\n", i, answer);
    }
}
