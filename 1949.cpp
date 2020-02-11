#include <iostream>
#include <memory.h>
#include <math.h>
using namespace std;
int MAP[8][8];
bool visit[8][8];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};
int K,N;

int DFS(int y, int x, int flag){
    visit[y][x] = true;
    int ret=1;
    if(flag==1){
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<N && 0<=ny&&ny<N){
                if(MAP[y][x]>MAP[ny][nx]&&!visit[ny][nx]) {
                    ret = max(ret, DFS(ny, nx, flag) + 1);
                }
                int cur = MAP[ny][nx];
                for(int j=1;j<=K;j++){
                    MAP[ny][nx] = cur - j;
                    if(MAP[y][x]>MAP[ny][nx]&&!visit[ny][nx])
                        ret = max(ret,DFS(ny,nx,flag-1)+1);
                    }
                MAP[ny][nx] = cur;
            }
        }
    }
    else{
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<=nx&&nx<N && 0<=ny&&ny<N){
                if(MAP[y][x]>MAP[ny][nx]&&!visit[ny][nx]){
                    ret = max(ret, DFS(ny,nx,flag)+1);
                }
            }
        }
    }
    visit[y][x] = false;
    return ret;
}
int solution(){
    cin>>N>>K;
    int max_point = 0;
    for(int i=0;i<N;i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            max_point = max_point < MAP[i][j] ? MAP[i][j] : max_point;
        }
    }
    int answer = 0;
    memset(visit,false,sizeof(visit));
    for(int i =0;i<N;i++)
        for(int j=0;j<N;j++)
            if(MAP[i][j]==max_point){
                answer = max(answer, DFS(i, j, 1));
            }
    return answer;
}
int main(int argc, char** argv)
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    int answer;
    for(test_case = 1; test_case <= T; ++test_case){
        answer = solution();
        cout<<"#"<<test_case<<" "<<answer<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
