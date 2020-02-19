#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
//#define macro_max(a,b) (((a)>(b)) ? (a) : (b))

bool graph[11][11];
bool visited[11] = {false, };
int M, N, answer;
int DFS(int cur){
    int ret = 0;
    for(int i=1;i<=N;i++){
        if(graph[cur][i]&&!visited[i]) {
            visited[i] = true;
            ret = max(DFS(i),ret);
            visited[i] = false;
        }
    }
    return ret+1;
}
int main(int argc, char** argv) {
    register int i, j;
    int TC, a, b;
    scanf("%d",&TC);
    for (i = 1; i<=TC; i++) {
        memset(graph,false,sizeof(graph));
        answer = 1;
        scanf("%d %d",&N,&M);
        for(j = 0; j < M; j++){
            scanf("%d %d",&a,&b);
            graph[a][b] = graph[b][a] = true;
        }
        for(int i=1;i<=N;i++){
            visited[i] = true;
            answer = max(answer,DFS(i));
            if(answer==N)
                break;
            visited[i] = false;
        }
        printf("#%d %d\n",i,answer);
    }
}
