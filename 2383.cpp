#include <stdio.h>
#include <queue>
#define gc() getchar_unlocked()
using namespace std;
priority_queue<int,vector<int>,greater<int>> sq1, sq2;
queue<int> s1, s2;
int m, people, stair, answer;
int p[10][2], s[2][3];
int ABS(int a){ return a >= 0 ? a : -a; }
int fRI(){
    register int N = gc(), r = 0;
    for(;0x30>N||N>0x3A;N=gc());
    do{
        r = (r<<3) + (r<<1) + (N&0b1111); N = gc();
    }while(0x30<=N);
    return r;
}
void DFS(int bitmask, int n){
    if(!(n^people)){
        sq1 = sq2 = priority_queue<int,vector<int>,greater<int>> ();
        s1 = s2 = queue<int>();
        for(int i = 0; i < people; i++){
            if(bitmask&(1<<i)) sq1.push(ABS(p[i][0] - s[0][0]) + ABS(p[i][1]-s[0][1]) + 1);
            else sq2.push(ABS(p[i][0] - s[1][0]) + ABS(p[i][1]-s[1][1]) + 1);
        }
        m = 0;
        while((!s1.empty()||!s2.empty()||!sq1.empty()||!sq2.empty())&&m<=answer){
            while(!s1.empty()&&!(s1.front()^m)) s1.pop();
            while(!s2.empty()&&!(s2.front()^m)) s2.pop();
            while(s1.size()<3 && !sq1.empty() && m>=sq1.top()){ s1.push(m+s[0][2]); sq1.pop(); }
            while(s2.size()<3 && !sq2.empty() && m>=sq2.top()){ s2.push(m+s[1][2]); sq2.pop(); }
            m++;
        }
        answer = answer > --m ? m : answer;
        return;
    }
    DFS(bitmask,n+1);
    DFS(bitmask|(1<<n), n+1);
}
int main(void){
    register int tc = 1, T = fRI(), N, i, j;
    while(T--) {
        N = fRI(); people = stair = 0; answer = 987654321;
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++){
                m=fRI();
                if(!(m^1)){
                    p[people][0] = i;
                    p[people][1] = j;
                    people++;
                }
                else if(m){
                    s[stair][0] = i;
                    s[stair][1] = j;
                    s[stair][2] = m;
                    stair++;
                }
            }
        DFS(0,0);
        printf("#%d %d\n",tc++,answer);
        
    }
    return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}
