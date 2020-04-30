#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
int N, scores[10], len[10], ans;
char names[10][10];
int use[26];
int fRI() {
    int N = gc(), ret = 0;
    for (; N < 48 || N>57; N = gc());
    do {
        ret = (ret << 3) + (ret << 1) + (N & 0b1111); N = gc();
    } while ('0' <= N && N <= '9');
    return ret;
}
char fRC(){
    char ret = '0';
    for(;ret<'A'||ret>'Z';ret = gc());
    return ret;
}
void DFS(int cur, int cost){
    if(use['S'-'A']>=2&&use['A'-'A']&&use['M'-'A']&&use['U'-'A']&&use['N'-'A']&&use['G'-'A']){
        ans = cost > ans ? ans : cost;
        return ;
    }
    if(cur>=N||cost>=ans) return ;
    int flag = 0;
    for(int i = 0; i < len[cur] && !flag; ++i){
        if(use[names[cur][i]-'A']&&names[cur][i]!='S') continue;
        switch(names[cur][i]){
            case 'S':
            case 'A':
            case 'M':
            case 'U':
            case 'N':
            case 'G': ++flag; break;
        }
    }
    if(flag){
        for(int i = 0; i < len[cur]; ++i)
            ++use[names[cur][i]-'A'];
        DFS(cur+1,cost+scores[cur]);
        for(int i = 0; i < len[cur]; ++i)
            --use[names[cur][i]-'A'];
    }
    DFS(cur+1,cost);
}
int solution(){
    memset(use,0,sizeof(use));
    ans = 987654321;
    N = fRI();
    for(int i = 0; i < N; ++i){
        len[i] = fRI();
        for(int j = 0; j < len[i]; ++j) {
            names[i][j] = fRC();
        }
        scores[i] = fRI();
    }
    DFS(0,0);
    return ans == 987654321 ? -1 : ans;
}
int main(int argc, char** argv){
    int tc = 1, T = fRI();
    while(T--){
        printf("#%d %d\n",tc++,solution());
    }
}
