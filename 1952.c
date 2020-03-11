/*
 * DP solution
 */
#include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define reg register
int fRI() {
    reg int N = gc(), r = 0;
    for (;48 > N || N > 57; N = gc());
    do {
        r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
    } while (48 <= N);
    return r;
}
void fWI(int tc) {
    reg int r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = (r << 3) + (r << 1) + (tc % 10); tc /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30);
}
int main(int argc, char** argv){
    reg int tc = 1, T = fRI(), answer, d, m, m3;
    int DP[13];
    while(T--){
        d = fRI(); m = fRI(); m3 = fRI(); answer = fRI();
        DP[1] = fRI(); DP[1] = DP[1]*d > m ? m : DP[1]*d;
        DP[2] = fRI(); DP[2] = DP[2]*d > m? m+DP[1] : DP[2]*d+DP[1];
        for(reg int i = 3 ; i <= 12; i++) {
            DP[i] = fRI();
            DP[i] = DP[i]*d < m ? DP[i]*d : m;
            DP[i] = DP[i-3]+m3 > DP[i-1] + DP[i] ? DP[i-1] + DP[i] : DP[i-3]+m3;
        }
        pc(0x23); fWI(tc++); pc(32); fWI(answer > DP[12] ? DP[12] : answer); pc(0x0A);
    }
}

/* DFS
 #include <stdio.h>
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define reg register

int cost[3];
int month[15] = {0};
int answer;

int fRI() {
    reg int N = gc(), r = 0;
    for (;48 > N || N > 57; N = gc());
    do {
        r = (r << 3) + (r << 1) + (N & 0b1111); N = gc();
    } while (48 <= N);
    return r;
}
void fWI(int tc) {
    reg int r = 0, c = 0;
    while (!(tc % 10)) { c++; tc /= 10; }
    while (tc) { r = (r << 3) + (r << 1) + (tc % 10); tc /= 10; }
    while (r) { pc(r % 10 | 0b110000); r /= 10; }
    while (c--) pc(0x30);
}
void DFS(int cm, int cc){
    if(cc>answer) return;
    if(cm >= 12) { answer = answer > cc? cc : answer; return;}
    if (month[cm] + month[cm + 1] + month[cm + 2] > cost[2])
        DFS(cm + 3, cc + cost[2]);
    DFS(cm + 1, cc + month[cm]);
}
int main(int argc, char** argv){
    reg int tc = 1, T = fRI();
    while(T--){
        cost[0] = fRI(); cost[1] = fRI(); cost[2] = fRI(); answer = fRI();
        for(int i = 0 ; i < 12; i++) {
            month[i] = fRI();
            month[i] = month[i]*cost[0] < cost[1] ? month[i]*cost[0] : cost[1];
        }
        DFS(0,0);
        pc(0x23); fWI(tc++); pc(32); fWI(answer); pc(0x0A);
    }
}
*/
