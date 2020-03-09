#include <stdio.h>
#include <memory.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b) ((a<<3)+(a<<1)+(b))
#define REP(i,a,b) for(i = a; i < b; i++)
int MAP[401][401], N, M, answer;
int visit[401];
int fRI(){
    int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = ADD3(r,N&0b1111); N = gc();
    }while(0x30<=N&&N<=0x3A);
    return r;
}

void fWI(int tc) {
    if(!tc) {pc(0x30); return;}
    int r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = ADD3(r,tc%10); tc /= 10; }
    while (r) { pc(r % 10 + 48); r /= 10; }
    while (c--) pc(0x30);
    return;
}
void DFS(int start, int cur,long length){
    visit[cur] = 1;
    int i;
    REP(i,1,N+1){
        if(MAP[cur][i]) {
            if(!visit[i]&&answer>length+MAP[cur][i]) DFS(start, i, length + MAP[cur][i]);
            else if(!(i^start)) answer = answer > length + MAP[cur][start] ? length + MAP[cur][start] : answer;
        }
    }
    return ;
}
int main(void){
    register int tc = 1, T=fRI(), i, s, e, c;
    while(T--){
        N=fRI(); M=fRI();
        memset(MAP,0,sizeof(MAP));
        answer = 987654321;
        REP(i,0,M){
            s = fRI(); e = fRI(); c = fRI();
            MAP[s][e] = c;
            if(!(s^e)) answer = c;
        }
        REP(i,1,N+1){
            memset(visit,0,sizeof(visit));
            DFS(i,i,0);
        }
        pc(0x23); fWI(tc++); pc(0x20);
        fWI(answer); pc('\n');
    }
    return 0;
}
