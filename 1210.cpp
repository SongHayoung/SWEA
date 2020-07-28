#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define gc() getchar_unlocked()
inline void fastreadINT_byReference(short &ret){
    int N = gc(), flag = 1;
    for(;N<'0'||N>'9';N=gc())
        if(N=='-'){
            flag=-1;    N=gc(); break;
        }
    ret = 0;
    do{
        ret = (ret<<3) + (ret<<1) + (N & 0b1111);    N=gc();
    }while('0'<=N&&N<='9');
    ret *= flag;
}
int main() {
    short tc, T = 10, y, x, dir;
    short map[100][100], dx[2] = {-1, 1};
    while(T--) {
        fastreadINT_byReference(tc);
        y = dir = 99;
        for(int i = 0; i < 100; ++i)
            for(int j = 0; j < 100; ++j)
                fastreadINT_byReference(map[i][j]);

        for(x = 0; map[y][x] != 2; ++x);

        while(y) {
            if(dir != 99 && 0 <= x + dx[dir] && x + dx[dir] < 99 && map[y][x + dx[dir]])
                x += dx[dir];
            else if(0 != x && map[y][x - 1] != 0 && dir != 1)
                --x, dir = 0;
            else if(99 != x && map[y][x + 1] != 0 && dir != 0)
                ++x, dir = 1;
            else if(map[y - 1][x] == 1)
                --y, dir = 99;
        }
        printf("#%d %d\n",tc, x);
    }
}
