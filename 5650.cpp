#include<iostream>
using namespace std;
int N;
int MAP[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int start_x, start_y;
int answer;
inline bool isFinish(int y, int x){
    if(MAP[y][x]==-1)
        return true;
    return start_x==x&&start_y==y;
}

class WORMHOLE{
public:
    int x;
    int y;
};
WORMHOLE wormhole[11][2];
inline void move(int _dir){
    int x = start_x, y = start_y, dir = _dir, point = 0;
    int nx, ny, numOfWormhole;
    do{
        nx = x + dx[dir];
        ny = y + dy[dir];
        if(0>nx||nx>=N||0>ny||ny>=N){
            dir = (dir+2)%4;
            ++point;
            ny = y; nx = x;
        }
        if(MAP[ny][nx]==5){
            dir = (dir+2)%4;
            ++point;
        }
        else if(MAP[ny][nx]==1){
            ++point;
            if(dir<=1)
                dir = (dir+2)%4;
            else if(dir==2)
                dir = 1;
            else if(dir==3)
                dir = 0;
        }
        else if(MAP[ny][nx]==2){
            ++point;
            if(1<=dir&&dir<=2)
                dir = (dir+2)%4;
            else if(dir==0)
                dir = 1;
            else if(dir==3)
                dir = 2;
        }
        else if(MAP[ny][nx]==3){
            ++point;
            if(dir>=2)
                dir = (dir+2)%4;
            else if(dir==0)
                dir = 3;
            else if(dir==1)
                dir = 2;
        }
        else if(MAP[ny][nx]==4){
            ++point;
            if(dir==0||dir==3)
                dir = (dir+2)%4;
            else if(dir==1)
                dir = 0;
            else if(dir==2)
                dir = 3;
        }
        x = nx; y = ny;
        if (MAP[y][x]>=6) {
            numOfWormhole = MAP[y][x];
            if (wormhole[numOfWormhole][0].y == y && wormhole[numOfWormhole][0].x == x) {
                y = wormhole[numOfWormhole][1].y;
                x = wormhole[numOfWormhole][1].x;
            } else {
                y = wormhole[numOfWormhole][0].y;
                x = wormhole[numOfWormhole][0].x;
            }
        }
    }while(!isFinish(y,x));
    answer = answer < point? point : answer;
}
void solution(){
int wormholeflag[11] = {0, };
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++){
            cin>>MAP[i][j];
            if(MAP[i][j]>=6) {
                wormhole[MAP[i][j]][wormholeflag[MAP[i][j]]].y = i;
                wormhole[MAP[i][j]][wormholeflag[MAP[i][j]]].x = j;
                ++wormholeflag[MAP[i][j]];
            }
        }
    answer = 0;
    for(start_y=0;start_y<N;start_y++)
        for(start_x=0;start_x<N;start_x++){
            if(MAP[start_y][start_x]!=0)
                continue;
            for(int k=0;k<4;k++) {
                move(k);
            }
        }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
        cin >> N;
        solution();
        cout<<"#"<<test_case<<" "<<answer<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
