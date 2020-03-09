#include <stdio.h>
#include <list>
using namespace std;
#define gc() getchar_unlocked()
#define pc(x) putchar_unlocked(x)
#define ADD3(a,b) ((a<<3)+(a<<1)+(b))
#define REP(i,a,b) for(i = a; i < b; i++)
struct DATA{
    int d[7];
    int psum[7];
};
list<DATA> Dlist;
int N, X, M, l, r, s;
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
void init(int cur,DATA &d, int psum){
    if(cur<l&&psum^s) return;
    if(!cur){
        for(int i = 1; i <= N; i++) d.psum[i] = d.psum[i-1] + d.d[i];
        Dlist.push_back(d);
        return ;
    }
    for(int i = X; i >= 0; i--) {
        d.d[cur] = i;
        if(l<=cur&&cur<=r) init(cur-1,d,psum+i);
        else init(cur-1,d,psum);
    }
}
int main(void){
    register int tc = 1, T=fRI(), i;
    DATA d;
    while(T--){
        N=fRI(); X=fRI(); M=fRI(); l = fRI(); r = fRI(); s = fRI();
        Dlist.clear();
        init(N, d,0);
        pc(0x23); fWI(tc++); pc(0x20);
        REP(i,1,M){
            l = fRI(); r = fRI(); s = fRI();
            for(auto it = Dlist.begin(); it!= Dlist.end(); it++)
                if(((*it).psum[r]-(*it).psum[l-1])^s)
                    Dlist.erase(it--);
        }
        if(Dlist.empty()) {pc('-'); pc('1');}
        else{
            REP(i,1,N+1){
                fWI((*Dlist.begin()).d[i]); pc(0x20);
            }
        }
        pc('\n');
    }
    return 0;
}
